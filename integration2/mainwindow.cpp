#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produits.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QObject>
#include <QtDebug>
#include <QTabWidget>
#include<QSqlQuery>
#include <QDate>
#include <QDateEdit>
#include"notif.h"
#include <QSqlError>
#include <QPdfWriter>
#include <QTextDocument>
#include <QDesktopServices>
#include <QTextDocument>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>
#include "smtp.h"

#include <QPainter>
#include <QDebug>



#include <QTextDocumentWriter>
#include <QFileDialog>
#include <QTextDocument>
#include <QPainter>
#include <QApplication>
#include <QTextBrowser>
#include <QtCharts/QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include<QSqlRecord>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>



#include <QDialog>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>

#include "smtp.h"

#include <QPdfWriter>
#include <QPainter>

#include <QtCharts>
#include <QChartView>
#include <QBarSet>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui ->le_reference_produit->setValidator(new QIntValidator(0,9999999,this));
    ui->le_reference_produit->setValidator( new QIntValidator(0, 999999, this));
    QRegExp rx("[a-zA-Z]+");


    ui->tab_produits->setModel(p.afficher());



    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
     break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
   case(-1):qDebug() << "arduino is not available";
}




}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_Ajouter_clicked()
{


    data=A.read_from_arduino(); //input
    test= data;
    qDebug()<<test.left(test.length()-4);
    QString code=test.left(test.length()-4);
    if(code!=""){

    int reference = ui->le_reference_produit->text().toInt();
    float prix = ui->le_prix->text().toFloat();
    QString date_produit = ui->le_date_produit->text();
    int quantite = ui->le_quantite->text().toInt();
    QString NOM = ui->le_nom->text();
    QString EMAIL = ui->le_email->text();

    ui->tab_produits->setModel(p.afficher());
    produits p(reference, prix, date_produit, quantite, NOM, EMAIL);
    bool insertionSuccess =p.ajouter();

    QMessageBox messagebox;
    if (insertionSuccess)
    {
        messagebox.setText("Data added to the database successfully");
        n.AjouterP();
        p.arduino(code , "Ajout");
        A.write_to_arduino("Ajout"); //output
    }
    else
    {
        messagebox.setText("Failed to add data to the database");
        A.write_to_arduino("Failed");
    }
    messagebox.exec();

    if (insertionSuccess)
    {
        QMessageBox::information(nullptr, QObject::tr("Mise à jour"),
                                 QObject::tr("Mise à jour réussie.\n"
                                             "Cliquez sur Annuler pour quitter."),
                                 QMessageBox::Cancel);
        n.ModifierP();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Mise à jour"),
                               QObject::tr("Échec de la mise à jour.\n"
                                           "Cliquez sur Annuler pour quitter."),
                               QMessageBox::Cancel);
    }}
    else
        QMessageBox::critical(nullptr, QObject::tr("scan RFID"),QObject::tr("scan  fAILED"), QMessageBox::Cancel);

    // Mettez à jour le modèle après la modification
    ui->tab_produits->setModel(p.afficher());
}





void MainWindow::on_pb_supprimer_3_clicked()
{



        data=A.read_from_arduino();
        test= data;
        qDebug()<<test.left(test.length()-4);
        QString code=test.left(test.length()-4);
        if(code!=""){
        // Récupère la ligne sélectionnée dans le tableau
            int row = ui->tab_produits->currentIndex().row();

            // Vérifie si une ligne est sélectionnée
            if (row < 0) {
                QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner une ligne à supprimer.");
                return;
            }

            // Récupère l'ID de l'enregistrement sélectionné dans le tableau
            int reference = ui->tab_produits->model()->data(ui->tab_produits->model()->index(row, 0)).toInt();


            // Affiche un message de confirmation demandant à l'utilisateur s'il est sûr de vouloir supprimer les informations de l'enregistrement sélectionné
            QMessageBox msgbox;
            msgbox.setText("Voulez-vous vraiment supprimer ces informations ?");
            msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgbox.setDefaultButton(QMessageBox::No);
            int res = msgbox.exec();

            // Si l'utilisateur confirme la suppression, crée un objet Donataire et appelle la fonction "supprimer" pour supprimer l'enregistrement correspondant
            if (res == QMessageBox::Yes) {
                produits p;
                p.Setreference_produit(reference);
                bool test = p.supprimer(p.Getreference_produit());

                // Affiche un message de succès ou d'échec
                if(test) {
                    QMessageBox::information(this, "Succès", "Suppression avec succès");
                    ui->tab_produits->setModel(p.afficher());
                    n.SupprimerP();
                    p.arduino(code , "Delete");
                    A.write_to_arduino("Delete"); //output

                } else {
                    QMessageBox::warning(this, "Échec", "Échec de suppression");
                    A.write_to_arduino("Failed");
                }
            }
    }else
                    QMessageBox::critical(nullptr, QObject::tr("scan RFID"),QObject::tr("scan  fAILED"), QMessageBox::Cancel);

}




void MainWindow::on_modifier_clicked()
{



    data=A.read_from_arduino();
    test= data;
    qDebug()<<test.left(test.length()-4);
    QString code=test.left(test.length()-4);
    if(code!="") {

    int reference =ui->le_reference_produit->text().toInt();
    float prix=ui->le_prix->text().toFloat();
    QString date_produit = ui->le_date_produit->text();
    int quantite=ui->le_quantite->text().toInt();
    QString nom=ui->le_nom->text();
     QString EMAIL=ui->le_email->text();


        produits p(reference,prix,date_produit,quantite,nom,EMAIL);
         bool test=p.modifier(reference);
           ui->tab_produits->setModel(p.afficher());
          if(test){
              QMessageBox::information(nullptr, QObject::tr("update"),
                    QObject::tr(" successful.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
              n.ModifierP();
              p.arduino(code , "Modifier");
                    A.write_to_arduino("Modifier");

    }
          else
          {
         QMessageBox::critical(nullptr, QObject::tr("update"),
                     QObject::tr(" failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
          A.write_to_arduino("Failed");

         }
    }else
        QMessageBox::critical(nullptr, QObject::tr("scan RFID"),QObject::tr("scan  fAILED"), QMessageBox::Cancel);
}

void MainWindow::on_pb_recherche_clicked()
{

        // Récupérez le texte saisi dans le champ de recherche (le_recherche)
        QString searchText = ui->le_recherche->text();
        QSqlQueryModel* model = new QSqlQueryModel();

        if (model == nullptr) {
            qDebug() << "Failed to create QSqlQueryModel.";
            return;
        }

        QSqlQuery query;
        // Utilisez une condition pour déterminer si l'entrée est un nombre (ref) ou une chaîne (NOM)
        if (searchText.toInt() > 0) {
            // Si l'entrée est un nombre (ref), recherchez par ref

            query.prepare("SELECT * FROM PRODUITS WHERE REFERENCE_PRODUIT = :REFERENCE_PRODUIT");
            query.bindValue(":REFERENCE_PRODUIT", searchText.toInt());
        } else {
            // Sinon, recherchez par NOM
            query.prepare("SELECT * FROM PRODUITS WHERE NOM = :NOM");
            query.bindValue(":NOM", searchText);
        }

        if (query.exec()) {
            model->setQuery(query);
            model->setQuery("SELECT * FROM produits");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference_produit"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_produit"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));
             model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));


            ui->tab_produits->setModel(model);
        } else {
            qDebug() << "Error in SQL query: " << query.lastError().text();
            return;
        }

    }



void MainWindow::on_le_recherche_textChanged(const QString &arg1)
{
    if(arg1!="")
           ui->tab_produits->setModel(p.rechercherProduit(arg1));
           else
               ui->tab_produits->setModel(p.rechercherProduit(arg1));
}

void MainWindow::on_le_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/hammemi/Desktop/testt/testcrud/produits.pdf");

                  QPainter painter(&pdf);
                  int i = 4000;
                         painter.setPen(Qt::darkCyan);
                         painter.setFont(QFont("Time New Roman", 25));
                         painter.drawText(3000,1400,"PRODUITS");
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Time New Roman", 15));
                         painter.drawRect(100,100,9400,2500);
                         painter.drawRect(100,3000,9400,500);
                         painter.setFont(QFont("Time New Roman", 9));
                         painter.drawText(4400,3300,"reference_produit");
                         painter.drawText(400,3300,"prix");
                         painter.drawText(1750,3300,"date_produit");
                         painter.drawText(2000,3300,"quantite");
                         painter.drawText(2400,3300,"nom");
                         painter.drawText(2400,3300,"EMAIL");



                         painter.drawRect(100,3000,9400,9000);

                         QSqlQuery query;
                         query.prepare("select * from PRODUITS");
                         query.exec();
                         while (query.next())
                         {

                             painter.drawText(1350,i,query.value(1).toString());
                             painter.drawText(2300,i,query.value(2).toString());
                             painter.drawText(3400,i,query.value(3).toString());
                             i = i + 350;
                         }
                         QMessageBox::information(this, QObject::tr("PDF Saved Successfuly!"),
                         QObject::tr("PDF Saved Successfuly!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}


// ... (previous code)
void MainWindow::on_BtnEnregistrer_clicked()
{
QString dir = "C:/Users/hammemi/Desktop/testt/testcrud";
   QDir().mkpath(dir);
   QString fileName = dir + "/PRODUIT.pdf";
   QPdfWriter pdf(fileName);
   QPainter painter(&pdf);
   int i = 4000;
painter.drawPixmap(QRect(100,100,2000,2000),QPixmap("C:/Users/msi/Downloads/logo_p.png"));//C:\Users\msi\Downloads
    painter.setPen(Qt::red);
    painter.setFont(QFont("Time New Roman", 25));
    painter.drawText(3000,1450,"Liste des Pharmacies");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Time New Roman", 15));
    painter.drawRect(100,100,9400,2500);
    painter.drawRect(100,3000,9400,500);
    painter.setFont(QFont("Time New Roman", 10));
    painter.drawText(4400, 3300, "reference_produit");
           painter.drawText(400, 3300, "prix");
           painter.drawText(1350, 3300, "date_produit");
           painter.drawText(1350, 3300, "quantite");
           painter.drawText(1350, 3300, "nom");
            painter.drawText(1350, 3300, "EMAIL");


    painter.drawRect(100,3000,9400,10700);

    QTextDocument previewDoc;
   QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");

    QTextCursor cursor(&previewDoc);

    QSqlQuery query;
    query.prepare("SELECT reference_produit, prix, date_produit, quantite, nom");
    query.exec();
    while (query.next())
    {
        painter.drawText(300,i,query.value(0).toString());
        painter.drawText(1500,i,query.value(1).toString());
        painter.drawText(3000,i,query.value(2).toString());
        painter.drawText(4800,i,query.value(3).toString());
        painter.drawText(6600,i,query.value(4).toString());
        painter.drawText(8400,i,query.value(5).toString());
        //painter.drawText(10000,i,query.value(6).toString());
        //painter.drawText(11500,i,query.value(7).toString());
        //painter.drawText(13500,i,query.value(8).toString());

        i = i +500;
    }

    int reponse = QMessageBox::question(this, "Générer PDF", " PDF Enregistré ! Voulez Vous Affichez Le PDF ?",
        QMessageBox::Yes|QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PRODUITS.pdf"));
        painter.end();
    }
    else
    {
         painter.end();
    }
}


void MainWindow::on_le_tri_clicked()
{
   produits p;
    QSqlQueryModel * result =p.tri_reference_produit();
    ui->tab_produits->setModel(result);


}

void MainWindow::on_le_tri_2_clicked()
{
    produits p;
    QSqlQueryModel * result =p.tri_prix();
    ui->tab_produits->setModel(result);

}








void MainWindow::on_stat_butt_clicked()
{
    QSqlQueryModel *model = p.afficher();
    int totalproduits = model->rowCount();

    // Initialiser les compteurs
    int quantiteMoins100 = 0;
    int quantitePlus100 = 0;

    // Calculer le nombre de produits avec une quantité < 100 ou > 100
    for (int row = 0; row < totalproduits; ++row) {
        int quantite = model->data(model->index(row, 3)).toInt(); // Assuming column index 3 is for "QUANTITE"

        if (quantite < 100) {
            quantiteMoins100++;
        } else if (quantite > 100) {
            quantitePlus100++;
        }
    }

    // Calcul du pourcentage des produits avec une quantité < 100 ou > 100
    double pourcentageMoins100 = (totalproduits > 0) ? ((double)quantiteMoins100 / totalproduits) * 100 : 0;
    double pourcentagePlus100 = (totalproduits > 0) ? ((double)quantitePlus100 / totalproduits) * 100 : 0;

    // Créer un objet QPieSeries pour stocker les données du graphique
    QPieSeries *series = new QPieSeries();
    QPieSlice *slicequantiteMoins100 = new QPieSlice("Quantité < 100", pourcentageMoins100);
    QPieSlice *slicequantitePlus100 = new QPieSlice("Quantité > 100", pourcentagePlus100);

    // Attribuer des couleurs spécifiques aux tranches
    // ...

    // Attribuer des couleurs spécifiques aux tranches
    slicequantiteMoins100->setColor(QColor("#800000"));  // Rouge
    slicequantitePlus100->setColor(QColor("#FF0000"));   // Gris





    // Ajouter les pourcentages aux labels des parts
    slicequantiteMoins100->setLabel(QString("Quantité < 100 : %1%").arg(pourcentageMoins100, 0, 'f', 2));
    slicequantitePlus100->setLabel(QString("Quantité > 100 : %1%").arg(pourcentagePlus100, 0, 'f', 2));
    series->append(slicequantiteMoins100);
    series->append(slicequantitePlus100);

    // Créer un objet QChart pour le graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistique Quantité Moins 100, Quantité Plus 100");

    // Ajouter une légende personnalisée
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    // Ajouter une animation au graphique
    chart->setAnimationOptions(QChart::AllAnimations);

    // Créer un objet QChartView pour afficher le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);  // Activer l'antialiasing pour des graphiques plus fluides

    // Appliquer les styles CSS directement à QChartView
    chartView->setStyleSheet("QChartView { background-color: #f5f5f5; } QPieSeries { color: white; }");

    // Créer un nouveau QDialog pour afficher le graphique
    QDialog *chartDialog = new QDialog(this);
    chartDialog->setFixedSize(800, 600);  // Ajuster la taille en conséquence
    QVBoxLayout *layout = new QVBoxLayout(chartDialog);
    layout->addWidget(chartView);

    // Bouton pour fermer la fenêtre de statistiques
    QPushButton *closeButton = new QPushButton("Fermer", chartDialog);
    connect(closeButton, &QPushButton::clicked, chartDialog, &QDialog::close);
    layout->addWidget(closeButton);

    // Afficher la fenêtre
    chartDialog->exec();
}
