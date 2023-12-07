#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include <QIntValidator>
#include <QObject>
#include <QtDebug>
#include <QTabWidget>
#include<QSqlQuery>
#include <QDate>
#include <QDateEdit>

#include <QSqlError>
#include <QPdfWriter>
#include <QTextDocument>
#include <QDesktopServices>
#include <QTextDocument>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>


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


#include <QPdfWriter>
#include <QPainter>



// Assurez-vous que le fichier d'en-tête de votre classe Commande est inclus

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui ->LE_ID->setValidator(new QIntValidator(0,9999999,this));
    ui->LE_QUANTITECOMMANDE->setValidator( new QIntValidator(0, 999999, this));
    QRegExp rx("[a-zA-Z]+");


    ui->TAB_CMD->setModel(c.afficher());
    ui->historiqueTV->setModel(h.afficherHistorique());
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include <QMessageBox>
void setWidgetBackground(QWidget *widget, const QColor &color = Qt::magenta, bool visible = true) {
    QPalette palette = widget->palette();
    palette.setColor(QPalette::Background, color);
    widget->setAutoFillBackground(true);
    widget->setPalette(palette);
    widget->setVisible(visible);
}
void MainWindow::on_BTNAJOUTER_clicked()
{     c.afficher();
    qDebug() << "Setting background color to magenta.";
    ui->LE_A->repaint();
    ui->LE_B->repaint();

    ui->LE_A->setAutoFillBackground(true);
    ui->LE_B->setAutoFillBackground(true);

    qDebug() << "Setting background color to magenta.";
    ui->LE_A->repaint();
    ui->LE_A->setAutoFillBackground(true);
    ui->LE_B->repaint();
    ui->LE_B->setAutoFillBackground(true);

    int ID = ui->LE_ID->text().toInt();
    QString STATUS_PRODUIT = ui->LE_S->currentText();  // Changer de ACTION à STATUS_PRODUIT
    QString DATE_PRODUIT = ui->LE_DATE->text();
    int QUANTITECOMMANDE = ui->LE_QUANTITECOMMANDE->text().toInt();

    // Utilisez qDebug() pour imprimer la valeur du statut du produit dans la console de débogage
    qDebug() << "Status of the product: " << STATUS_PRODUIT;

    Commande c(ID, STATUS_PRODUIT, DATE_PRODUIT, QUANTITECOMMANDE);  // Changer de ACTION à STATUS_PRODUIT

    // Ajouter les données à la base de données
    bool insertionSuccess = c.ajouter();

    // Mettre à jour le modèle de la table avec les données nouvellement ajoutées
    ui->TAB_CMD->setModel(c.afficher());
    //historique ajout
    historique hist("Ajout",QString::number(ID));
    hist.saveHistorique();
    ui->historiqueTV->setModel(h.afficherHistorique());


    QPalette paletteA = ui->LE_A->palette();
    QPalette paletteB = ui->LE_B->palette();

    paletteA.setColor(QPalette::Background, Qt::magenta);
    paletteB.setColor(QPalette::Background, Qt::magenta);

    ui->LE_A->setAutoFillBackground(true);
    ui->LE_B->setAutoFillBackground(true);

    // Rétablir la couleur par défaut si nécessaire
    ui->LE_A->setStyleSheet("");
    ui->LE_B->setStyleSheet("");

    if (STATUS_PRODUIT.toLower() == "bon etat") {
        ui->LE_A->setStyleSheet("background-color: green;");
    } else if (STATUS_PRODUIT.toLower() == "mauvais etat") {
        ui->LE_B->setStyleSheet("background-color: red;");
    }

    QMessageBox messageBox;

    if (insertionSuccess) {
        messageBox.setText("Data added to the database successfully!");
    } else {
        messageBox.setText("Failed to add data to the database!");
    }

    messageBox.exec();
}



void MainWindow::on_BTNMODIFIER_clicked()
{
    // ... Votre code actuel ...

    int ID = ui->LE_ID->text().toInt();
    QString STATUS_PRODUIT = ui->LE_S->currentText();
    QString DATE_PRODUIT = ui->LE_DATE->text();
    int QUANTITECOMMANDE = ui->LE_QUANTITECOMMANDE->text().toInt();

    Commande c(ID, STATUS_PRODUIT, DATE_PRODUIT, QUANTITECOMMANDE);

    // Modifier les données dans la base de données
    bool test = c.modifier(ID);
    ui->TAB_CMD->setModel(c.afficher());

    // Afficher une boîte de message en fonction du résultat de la modification
    QMessageBox messageBox;

    if (test) {
        messageBox.setText("Update successful.");
        //historique ajout
        historique hist("Update",QString::number(ID));
        hist.saveHistorique();
        ui->historiqueTV->setModel(h.afficherHistorique());
        messageBox.setIcon(QMessageBox::Information);
    } else {
        messageBox.setText("Update failed.");
        messageBox.setIcon(QMessageBox::Critical);
    }

    messageBox.exec();

    // ... Votre code actuel ...
}

void MainWindow::on_BTNSUPPRIMER_clicked()
{
    {
        // Récupère la ligne sélectionnée dans le tableau
            int row = ui->TAB_CMD->currentIndex().row();

            // Vérifie si une ligne est sélectionnée
            if (row < 0) {
                QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner une ligne à supprimer.");
                return;
            }

            // Récupère l'ID de l'enregistrement sélectionné dans le tableau
            int ID = ui->TAB_CMD->model()->data(ui->TAB_CMD->model()->index(row, 0)).toInt();


            // Affiche un message de confirmation demandant à l'utilisateur s'il est sûr de vouloir supprimer les informations de l'enregistrement sélectionné
            QMessageBox msgbox;
            msgbox.setText("Voulez-vous vraiment supprimer ces informations ?");
            msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgbox.setDefaultButton(QMessageBox::No);
            int res = msgbox.exec();

            // Si l'utilisateur confirme la suppression, crée un objet Donataire et appelle la fonction "supprimer" pour supprimer l'enregistrement correspondant
            if (res == QMessageBox::Yes) {
               Commande c;
                c.SetID(ID);
                bool test = c.supprimer(c.GetID());

                // Affiche un message de succès ou d'échec
                if(test) {
                    QMessageBox::information(this, "Succès", "Suppression avec succès");
                    //historique ajout
                    historique hist("Delete",QString::number(ID));
                    hist.saveHistorique();
                    ui->historiqueTV->setModel(h.afficherHistorique());
                    ui->TAB_CMD->setModel(c.afficher());


                } else {
                    QMessageBox::warning(this, "Échec", "Échec de suppression");
                }
            }
    }
}



void MainWindow::on_rechercher_commande1_textChanged(const QString &arg1)
{
    if(arg1!="")
           ui->TAB_CMD->setModel(c.rechercher_commande(arg1));
           else
               ui->TAB_CMD->setModel(c.rechercher_commande(arg1));
}


void MainWindow::on_tri_id_a_clicked()
{
   Commande c;
     QSqlQueryModel * result =c.tri_ID();
     ui->TAB_CMD->setModel(result);

}

void MainWindow::on_tri_date_a_clicked()
{
    Commande c;
      QSqlQueryModel * result =c.tri_DATE_PRODUIT();
      ui->TAB_CMD->setModel(result);
}
void MainWindow::on_stat_clicked()
{
    QSqlQueryModel *model = c.afficher();
    int totalCommandes = model->rowCount();

    // Initialiser les compteurs
    int quantiteMoins100 = 0;
    int quantitePlus100 = 0;

    // Calculer le nombre de commandes avec une quantité < 100 ou > 100
    for (int row = 0; row < totalCommandes; ++row) {
        int quantiteCommande = model->data(model->index(row, model->record().indexOf("QUANTITECOMMANDE"))).toInt();

        if (quantiteCommande < 100) {
            quantiteMoins100++;
        } else if (quantiteCommande > 100) {
            quantitePlus100++;
        }
    }

    // Calcul du pourcentage des commandes avec une quantité < 100 ou > 100
    double pourcentageMoins100 = (totalCommandes > 0) ? ((double)quantiteMoins100 / totalCommandes) * 100 : 0;
    double pourcentagePlus100 = (totalCommandes > 0) ? ((double)quantitePlus100 / totalCommandes) * 100 : 0;

    // Créer un objet QPieSeries pour stocker les données du graphique
    QPieSeries *series = new QPieSeries();
    QPieSlice *sliceQuantiteMoins100 = new QPieSlice("Quantité < 100", pourcentageMoins100);
    QPieSlice *sliceQuantitePlus100 = new QPieSlice("Quantité > 100", pourcentagePlus100);

    // Attribuer des couleurs spécifiques aux tranches
    sliceQuantiteMoins100->setColor(QColor("#FF69B4"));  // Rose
    sliceQuantitePlus100->setColor(QColor("#0000FF"));   // Bleu

    // Ajouter les pourcentages aux labels des parts
    sliceQuantiteMoins100->setLabel(QString("Quantité < 100 : %1%").arg(pourcentageMoins100, 0, 'f', 2));
    sliceQuantitePlus100->setLabel(QString("Quantité > 100 : %1%").arg(pourcentagePlus100, 0, 'f', 2));

    series->append(sliceQuantiteMoins100);
    series->append(sliceQuantitePlus100);

    // Créer un objet QChart pour le graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistique Quantité < 100, Quantité > 100");

    // Ajouter une légende personnalisée
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    // Créer un objet QChartView pour afficher le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);  // Activer l'antialiasing pour des graphiques plus fluides

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

void MainWindow::on_PDF_bb_clicked()
{
    QPdfWriter pdf("C:/Users/hammemi/Downloads/CMDD/Commande.pdf");

    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::darkCyan);
    painter.setFont(QFont("Times New Roman", 25));
    painter.drawText(3000, 1400, "PRODUITS");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Times New Roman", 15));
    painter.drawRect(100, 100, 9400, 2500);
    painter.drawRect(100, 3000, 9400, 500);
    painter.setFont(QFont("Times New Roman", 9));
    painter.drawText(4400, 3300, "ID");
    painter.drawText(400, 3300, "STATUS_PRODUIT");
    painter.drawText(1750, 3300, "DATE_PRODUIT");
    painter.drawText(2000, 3300, "QUANTITECOMMANDE");

    painter.drawRect(100, 3000, 9400, 9000);

    QSqlQuery query;
    query.prepare("SELECT * FROM COMMANDE");
    query.exec();
    while (query.next())
    {
        painter.drawText(1350, i, query.value(1).toString());
        painter.drawText(2300, i, query.value(2).toString());
        painter.drawText(3400, i, query.value(3).toString());
        i = i + 350;
    }
    QMessageBox::information(this, QObject::tr("PDF Saved Successfully!"),
                             QObject::tr("PDF Saved Successfully!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_enrg_bb_clicked()
{
    QString dir = "C:/Users/hammemi/Downloads/CMDD";
    QDir().mkpath(dir);
    QString fileName = dir + "/COMMANDE.pdf";
    QPdfWriter pdf(fileName);
    QPainter painter(&pdf);
    int i = 4000;
    painter.drawPixmap(QRect(100, 100, 2000, 2000), QPixmap("C:/Users/msi/Downloads/logo_p.png"));
    painter.setPen(Qt::red);
    painter.setFont(QFont("Times New Roman", 25));
    painter.drawText(3000, 1450, "Liste des Pharmacies");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Times New Roman", 15));
    painter.drawRect(100, 100, 9400, 2500);
    painter.drawRect(100, 3000, 9400, 500);
    painter.setFont(QFont("Times New Roman", 10));

    painter.drawText(4400, 3300, "ID");
    painter.drawText(400, 3300, "STATUS_PRODUIT");
    painter.drawText(1750, 3300, "DATE_PRODUIT");
    painter.drawText(2000, 3300, "QUANTITECOMMANDE");

    painter.drawRect(100, 3000, 9400, 10700);

    QSqlQuery query;
    query.prepare("SELECT ID,STATUS_PRODUIT,DATE_PRODUIT, QUANTITECOMMANDE FROM COMMANDE");
    query.exec();
    while (query.next())
    {
        painter.drawText(300, i, query.value(0).toString());
        painter.drawText(1500, i, query.value(1).toString());
        painter.drawText(3000, i, query.value(2).toString());
        painter.drawText(4800, i, query.value(3).toString());
        i = i + 500;
    }

    int reponse = QMessageBox::question(this, "Générer PDF", " PDF Enregistré ! Voulez Vous Affichez Le PDF ?",
                                        QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile(dir + "/COMMANDE.pdf"));
        painter.end();
    }
    else
    {
        painter.end();
    }
}
