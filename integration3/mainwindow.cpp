#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "admins.h"
#include <QString>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
using namespace std;
#include "connection.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts>
#include <iostream>
#include <QIntValidator>
#include <QTextStream>
#include <QTextDocument>
#include <QDesktopWidget>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
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
#include <QFileDialog>
#include <QDialog>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QPdfWriter>
#include <QPainter>
#include "vehicule.h"
#include <QMessageBox>


#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QSettings>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QPdfWriter>
#include <QDataStream>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QComboBox>
#include "sms.h"
#include "ImageDelegate.h"
QString destinationPath;
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui ->le_reference_produit->setValidator(new QIntValidator(0,9999999,this));
    ui->le_reference_produit->setValidator( new QIntValidator(0, 999999, this));
    QRegExp rx("[a-zA-Z]+");


    ui->tab_produits->setModel(p.afficher());
    vehicule Etmp;

        ui->tableView->setModel(Etmp.afficher());
        ui->tableView->setItemDelegateForColumn(4, new ImageDelegate(this));
    ui->le_cin->setValidator(new QIntValidator(0, 9999999, this));
    ui->tab_client->setModel(C.afficher());
    admins a;
    if(a.role()==0){
        ui->label_6->setText("admin");
        ui->label_11->setText(a.getid());

    }
    if(a.role()==1){
        ui->label_6->setText("client");
        ui->label_11->setText(a.getid());
      ui->tab_client->hide();
    }
    stat();
    //int ret=A.connect_arduino(); // lancer la connexion à arduino
               // switch(ret){
                //case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                   // break;
                //case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
                 //  break;
                //case(-1):qDebug() << "arduino is not available";
                //}
                //A.write_to_arduino("Bonjour");
                QSqlQuery query;
                query.prepare("INSERT INTO LCD (message, datemess) " "VALUES (:message, :datemess)");
                query.bindValue(":message", "Bonjour");
                query.bindValue(":datemess", QDateTime::currentDateTime());
                query.exec();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
 qDebug();
int cin=ui->le_cin->text().toInt();
QString addmail=ui->le_addmail->text();
QString adresslivr=ui->le_adresslivr->text();
int nbach=ui->achat->text().toInt();

Client C(cin,addmail,adresslivr,nbach);
bool test=C.ajouter();
if(test){
    ui->tab_client->setModel(C.afficher());
    //A.write_to_arduino("ajout de "+ QString::number(cin));
    QSqlQuery query;
    query.prepare("INSERT INTO LCD (message, datemess) " "VALUES (:message, :datemess)");
    query.bindValue(":message", "ajout de "+QString::number(cin));
    query.bindValue(":datemess", QDateTime::currentDateTime());
    query.exec();



}
stat();

}

void MainWindow::on_pb_supprimer_clicked()
{
    Client C1;
    QModelIndex index=ui->tab_client->currentIndex();
        int i=index.row();
        QModelIndex in=index.sibling(i,0);
        QString val=ui->tab_client->model()->data(in).toString();
    bool test=C1.supprimer(val.toInt());

    if(test){
        ui->tab_client->setModel(C.afficher());
      //  A.write_to_arduino("supp de "+val);
        QSqlQuery query;
        query.prepare("INSERT INTO LCD (message, datemess) " "VALUES (:message, :datemess)");
        query.bindValue(":message", "supp de "+val);
        query.bindValue(":datemess", QDateTime::currentDateTime());
        query.exec();



    }
stat();
}

void MainWindow::on_pb_modifier_clicked()
{

        Client C;
        C.setcin(ui->le_idmodif->text().toInt());
        C.setaddmail(ui->le_modifaddmail->text());
        C.setadresslivr(ui->le_modifadd->text());
         C.setnchat(ui->achat_2->text().toInt());
        //bool test=C.modifier(C.getcin());
       // A.write_to_arduino("mod de "+QString::number(C.getcin()));
        QSqlQuery query;
        query.prepare("INSERT INTO LCD (message, datemess) " "VALUES (:message, :datemess)");
        query.bindValue(":message", "mod de "+QString::number(C.getcin()));
        query.bindValue(":datemess", QDateTime::currentDateTime());
        query.exec();

        C.afficher();
        stat();
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString text=ui->lineEdit->text();

    if(text.isEmpty())
    {
        Client C;
        C.afficher();
stat();
    }
    else
    {
        qry->prepare("select cin,ADDMAIL,adresslivr,nbach from Clients where ( cin LIKE'%"+text+"%' OR ADDMAIL LIKE'%"+text+"%' OR adresslivr LIKE'%"+text+"%') ");
        qry->exec();
        modal->setQuery(*qry);
        ui->tab_client->setModel(modal);
       // bool test=C.modifier(C.getcin());
       // A.write_to_arduino("search");
        QSqlQuery query;
        query.prepare("INSERT INTO LCD (message, datemess) " "VALUES (:message, :datemess)");
        query.bindValue(":message", "search");
        query.bindValue(":datemess", QDateTime::currentDateTime());
        query.exec();
    }
}

void MainWindow::on_tab_client_clicked(const QModelIndex &index)
{
    int i;
i=index.row();
QModelIndex in=index.sibling(i,0);
QString val=ui->tab_client->model()->data(in).toString();


    QSqlQuery qry;
    qry.prepare("select cin,ADDMAIL,adresslivr,nbach from Clients where cin='"+val+"' " );


    if(qry.exec())
    {
        while(qry.next())
        {
            ui->le_idmodif->setText(qry.value(0).toString());
            ui->le_modifaddmail->setText(qry.value(1).toString());
            ui->le_modifadd->setText(qry.value(2).toString());
     ui->achat_2->setText(qry.value(3).toString());
        }

}
}

void MainWindow::on_pushButton13_clicked()
{
//    QString strStream;
//    QTextStream out(&strStream);

//    const int rowCount = ui->tab_client->model()->rowCount();
//    const int columnCount = ui->tab_client->model()->columnCount();

//    out <<  "<html>\n"
//        "<head>\n"
//        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
//        <<  QString("<title>%1</title>\n").arg("col1")
//        <<  "</head>\n"
//        "<body bgcolor=#ffffff link=#5000A0>\n"
//        "<table border=1 cellspacing=0 cellpadding=2>\n";

//    // headers
//    out << "<thead><tr bgcolor=#f0f0f0>";
//    for (int column = 0; column < columnCount; column++)
//        if (!ui->tab_client->isColumnHidden(column))
//            out << QString("<th>%1</th>").arg(ui->tab_client->model()->headerData(column, Qt::Horizontal).toString());
//    out << "</tr></thead>\n";

//    // data table
//    for (int row = 0; row < rowCount; row++) {
//        out << "<tr>";
//        for (int column = 0; column < columnCount; column++) {
//            if (!ui->tab_client->isColumnHidden(column)) {
//                QString data = ui->tab_client->model()->data(ui->tab_client->model()->index(row, column)).toString().simplified();
//                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
//            }
//        }
//        out << "</tr>\n";
//    }
//    out <<  "</table>\n"
//        "</body>\n"
//        "</html>\n";

//    QTextDocument *document = new QTextDocument();
//    document->setHtml(strStream);

//    QPrinter printer;

//        document->print(&printer);


//    delete document;
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
          if (!fileName.isEmpty()) {
              Client P; // Supposons que P est une instance de votre classe Prouduit
              QSqlQueryModel* model = P.afficher(); // Obtenez le modèle de votre base de données
              if (P.exporterPDF(fileName, model)) {
                  QMessageBox::information(this, "Exportation PDF", "Les données ont été exportées en PDF avec succès !");
              } else {
                  QMessageBox::warning(this, "Exportation PDF", "Échec de l'exportation en PDF.");
              }
          }
        //  A.write_to_arduino("PDF");
          QSqlQuery query;
          query.prepare("INSERT INTO LCD (message, datemess) " "VALUES (:message, :datemess)");
          query.bindValue(":message", "PDF");
          query.bindValue(":datemess", QDateTime::currentDateTime());
          query.exec();
}


void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel ();
    QSqlQuery*qry=new QSqlQuery();
    QString type=ui->comboBox->currentText();
    if (type=="Par defaut"){
        qry->prepare("select * from Clients");


        qry->exec();
        model->setQuery(*qry);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
        model->setHeaderData(1, Qt::Horizontal,  QObject::tr("addmail"));
        model->setHeaderData(2, Qt::Horizontal,  QObject::tr("adresslivr"));
        model->setHeaderData(3, Qt::Horizontal,  QObject::tr("nb"));

        ui->tab_client->setModel(model);}
        else if (type=="Cin"){
            qry->prepare("select * from Clients  order by Cin");


            qry->exec();
            model->setQuery(*qry);
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
            model->setHeaderData(1, Qt::Horizontal,  QObject::tr("addmail"));
            model->setHeaderData(2, Qt::Horizontal,  QObject::tr("adresslivr"));
            model->setHeaderData(3, Qt::Horizontal,  QObject::tr("nb"));

            ui->tab_client->setModel(model);


        }
        else if (type=="Email"){
            qry->prepare("select * from Clients  order by ADDMAIL");


            qry->exec();
            model->setQuery(*qry);
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
            model->setHeaderData(1, Qt::Horizontal,  QObject::tr("addmail"));
            model->setHeaderData(2, Qt::Horizontal,  QObject::tr("adresslivr"));
            model->setHeaderData(3, Qt::Horizontal,  QObject::tr("nb"));

            ui->tab_client->setModel(model);


        }
    else if (type=="Adresse"){
        qry->prepare("select * from Clients  order by ADRESSLIVR");


        qry->exec();
        model->setQuery(*qry);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
        model->setHeaderData(1, Qt::Horizontal,  QObject::tr("addmail"));
        model->setHeaderData(2, Qt::Horizontal,  QObject::tr("adresslivr"));
        model->setHeaderData(3, Qt::Horizontal,  QObject::tr("nb"));

        ui->tab_client->setModel(model);


    }
}


void MainWindow::on_pushButton_21_clicked()
{
    QSqlQuery query;

       admins a;
      QString id=a.getid();
      int action=0;
      QString res=QString::number(action);
      query.prepare("UPDATE admin "" SET action=:action  where username='"+id+"' ");
        query.bindValue(":action",res);
        query.exec();
       // A.write_to_arduino("Good Bye");
        QSqlQuery quey;
        quey.prepare("INSERT INTO LCD (message, datemess) " "VALUES (:message, :datemess)");
        quey.bindValue(":message", "Good Bye");
        quey.bindValue(":datemess", QDateTime::currentDateTime());
        quey.exec();
        qApp->quit();

}
void MainWindow::closeEvent (QCloseEvent *event)
{
    QSqlQuery query,qry;

       admins a;
      QString id=a.getid();
      int action=0;
      QString res=QString::number(action);
      query.prepare("UPDATE admins "" SET action=:action  where username='"+id+"' ");
        query.bindValue(":action",res);
        query.exec();
      //  A.write_to_arduino("Good Bye");
        QSqlQuery quey;
        quey.prepare("INSERT INTO LCD (message, datemess) " "VALUES (:message, :datemess)");
        quey.bindValue(":message", "Good Bye");
        quey.bindValue(":datemess", QDateTime::currentDateTime());
        quey.exec();
        qApp->quit();
}
void MainWindow::stat(){

    vector<statt> v1,v11,v2,v3,v4;
    QSqlQuery qry,qry1,qry2,qry3;
statt s0,s1,s2,s3;

    qry.prepare("select cin,ADRESSLIVR from clients" );


    qry.exec();

        while(qry.next())
        {
            s0.cin=qry.value(0).toString();
            s0.address=qry.value(1).toString();
            v1.push_back(s0);
        }
        int occ0=0,occ01=0,occ02=0,occ03=0,occ1=0,occ2=0,occ3=0,occ4=0;
        QString addressocc="",addressocc1="",addressocc2="",addressocc3="",cin="",cin1="",cin2="",cin3="";
for( int i=0;i<v1.size();i++){
    occ0=0;
    for( int j=0;j<v1.size();j++){
        if (v1[i].address==v1[j].address)
            occ0++;
    }
    if(occ0>occ1){
        occ1=occ0;
    addressocc=v1[i].address;
    cin=v1[i].cin;}
}
qry1.prepare("select cin,ADRESSLIVR from clients where ADRESSLIVR!='"+addressocc+"'" );


qry1.exec();

    while(qry1.next())
    {
        s1.cin=qry1.value(0).toInt();
        s1.address=qry1.value(1).toString();
        v2.push_back(s1);
    }
    for( int i=0;i<v2.size();i++){
        occ01=0;

        for( int j=0;j<v2.size();j++){
            if (v2[i].address==v2[j].address)
                occ01++;
        }
        if(occ01>occ2){
            occ2=occ01;
        addressocc1=v2[i].address;
        cin1=v2[i].cin;}
    }
    qry2.prepare("select cin,ADRESSLIVR from clients where ADRESSLIVR!='"+addressocc+"' and ADRESSLIVR!='"+addressocc1+"' " );


    qry2.exec();

        while(qry2.next())
        {
            s2.cin=qry2.value(0).toInt();
            s2.address=qry2.value(1).toString();

            v3.push_back(s2);
        }
        for(unsigned int i=0;i<v3.size();i++){
            occ02=0;

            for(unsigned int j=0;j<v3.size();j++){
                if (v3[i].address==v3[j].address)
                    occ02++;
            }
            if(occ02>occ3){
                occ3=occ02;
            addressocc2=v3[i].address;
            cin2=v3[i].cin;}
        }
        qry3.prepare("select cin,ADRESSLIVR from clients where ADRESSLIVR!='"+addressocc+"' and ADRESSLIVR!='"+addressocc1+"' and ADRESSLIVR!='"+addressocc2+"'" );


        qry3.exec();

            while(qry3.next())
            {
                s3.cin=qry3.value(0).toInt();
                s3.address=qry3.value(1).toString();

                v4.push_back(s3);
            }
            for(unsigned int i=0;i<v4.size();i++){
                occ03=0;

                for(unsigned int j=0;j<v4.size();j++){
                    if (v4[i].address==v4[j].address)
                        occ03++;
                }
                if(occ03>occ4){
                    occ4=occ03;
                addressocc3=v4[i].address;
                cin3=v4[i].cin;}
            }

QPieSeries *series = new QPieSeries();
series->append(addressocc,occ1);
series->append(addressocc1,occ2);
series->append(addressocc2,occ3);
series->append(addressocc3,occ4);
QPieSlice *slice0 = series->slices().at(0);
slice0->setLabelVisible();
QPieSlice *slice1 = series->slices().at(1);
QPieSlice *slice2 = series->slices().at(2);
slice2->setLabelVisible();
slice2->setExploded();
slice2->setPen(QPen(Qt::darkBlue, 2));
slice2->setBrush(Qt::blue);
QPieSlice *slice3 = series->slices().at(3);
slice3->setLabelVisible();
slice3->setExploded();
slice3->setPen(QPen(Qt::darkGray, 2));
slice3->setBrush(Qt::gray);
slice1->setExploded();
slice1->setLabelVisible();
slice1->setPen(QPen(Qt::darkGreen, 2));
slice1->setBrush(Qt::green);
QChart *chart = new QChart();
 chart->addSeries(series);
 chart->setTitle("Les adresse le plus populair");

    chart->setAnimationOptions(QChart::AllAnimations);

    chart->legend()->hide();

    chartView = new QChartView(chart,ui->chartview);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(441,301);

    chartView->show();


}

void MainWindow::on_pushButton_3_clicked()
{
    Client cl;
          Client clf;
          clf=cl.clientFidele();
          if(clf.getnbach()>=10)
          {
              int remise=(clf.getnbach()-9)*1.5;
              int nb=clf.getnbach()-9;
                QString newremise_string=QString::number(remise);
                QString nb_string=QString::number(nb);
                QString m="Le client le plus fidèle est " + QString::number(clf.getcin()) + " " +clf.getaddmail() +" "+ ", il aura une remise de " +" "+  newremise_string + " "+ "% sur " + nb_string + " produits.";
                ui->label_15->setText(m);

          }
          else
          {
              QString s="Desolez il n'y a pas de client fidele ";
              ui->label_15->setText(s);
           }
}













//**************************************************arsaaa****************************



#include <QMessageBox>
void setWidgetBackground (QWidget *widget, const QColor &color = Qt::magenta, bool visible = true) {
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

   // QMessageBox messageBox;

    //if (insertionSuccess) {
        //messageBox.setText("Data added to the database successfully!");
    //} else {
        //messageBox.setText("Failed to add data to the database!");
    //}

  //  messageBox.exec();
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
        //messageBox.setIcon(QMessageBox::Information);
   // } else {
     //   messageBox.setText("Update failed.");
      //  messageBox.setIcon(QMessageBox::Critical);
  }

   // messageBox.exec();

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



//*****************************ghoff*******************










void MainWindow::on_le_reference_produit_cursorPositionChanged(int arg1, int arg2)
{
    // mainwindow.cpp (in the constructor or setup code)
    connect(ui->le_reference_produit, SIGNAL(cursorPositionChanged(int, int)), this, SLOT(on_le_reference_produit_cursorPositionChanged(int, int)));

}



void MainWindow::on_pb_Ajouter_clicked()
{

    int reference = ui->le_reference_produit->text().toInt();
    float prix = ui->le_prix->text().toFloat();
    QString date_produit = ui->le_date_produit->text();
    int quantite = ui->le_quantite->text().toInt();
    QString NOM = ui->le_nom->text();
    QString EMAIL = ui->le_email->text();

    ui->tab_produits->setModel(p.afficher());
    produits p(reference, prix, date_produit, quantite, NOM, EMAIL);
    bool insertionSuccess = p.ajouter();

    QMessageBox messagebox;
    if (insertionSuccess)
    {
       // messagebox.setText("Data added to the database successfully");
        n.AjouterP();
    }
    else
    {
       // messagebox.setText("Failed to add data to the database");
    }
   // messagebox.exec();

    if (insertionSuccess)
    {
       // QMessageBox::information(nullptr, QObject::tr("Mise à jour"),
                                // QObject::tr("Mise à jour réussie.\n"
                                      //       "Cliquez sur Annuler pour quitter."),
                               //  QMessageBox::Cancel);
        n.ModifierP();
    }
    else
    {
       // QMessageBox::critical(nullptr, QObject::tr("Mise à jour"),
                             //  QObject::tr("Échec de la mise à jour.\n"
                                       //    "Cliquez sur Annuler pour quitter."),
                               //QMessageBox::Cancel);
    }

    // Mettez à jour le modèle après la modification
    ui->tab_produits->setModel(p.afficher());
}







void MainWindow::on_pb_supprimer_3_clicked()
{
    int row = ui->tab_produits->currentIndex().row();

    if (row < 0) {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner une ligne à supprimer.");
        return;
    }

    int reference = ui->tab_produits->model()->data(ui->tab_produits->model()->index(row, 0)).toInt();

    qDebug() << "Reference à supprimer: " << reference;

    QMessageBox msgbox;
    msgbox.setText("Voulez-vous vraiment supprimer ces informations ?");
    msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgbox.setDefaultButton(QMessageBox::No);
    int res = msgbox.exec();

    if (res == QMessageBox::Yes) {
        produits p;
        p.Setreference_produit(reference);
        bool test = p.supprimer(p.Getreference_produit());

        if (test) {
            QMessageBox::information(this, "Succès", "Suppression avec succès");
            ui->tab_produits->setModel(p.afficher());
            n.SupprimerP();
        } else {
            QMessageBox::warning(this, "Échec", "Échec de suppression");
        }
    }
}

void MainWindow::on_modifier_clicked()
{
    int reference = ui->le_reference_produit->text().toInt();
    float prix = ui->le_prix->text().toFloat();
    QString date_produit = ui->le_date_produit->text();
    int quantite = ui->le_quantite->text().toInt();
    QString nom = ui->le_nom->text();
    QString EMAIL = ui->le_email->text();

    qDebug() << "Reference à modifier: " << reference;

    produits p(reference, prix, date_produit, quantite, nom, EMAIL);
    bool test = p.modifier(reference);

    ui->tab_produits->setModel(p.afficher());
     n.ModifierP();

    //if (test) {
        //QMessageBox::information(nullptr, QObject::tr("update"),
                                 QObject::tr(" successful.\n"
                                         //   "Click Cancel to exit."), QMessageBox::Cancel);
       // n.ModifierP();
   // } else {
       // QMessageBox::critical(nullptr, QObject::tr("update"),
                               //QObject::tr(" failed.\n"
                                       //    "Click Cancel to exit."), QMessageBox::Cancel);
   // }
);}

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


//***************************************************rana***************************************************






void MainWindow::on_pushButton_ajout_clicked()
{
    //recuperation des informations saisies dans les 3 champs
        int id_veh=ui->lineid->text().toInt();
        QString type_veh=ui->linetype->currentText();

        QString date_entretien=ui->linedate->text();
        QString kilometrage=ui->linekilo->text();
        QString id_veh_str = QString::number(id_veh);

        vehicule v(id_veh,type_veh,date_entretien,kilometrage,destinationPath);
        bool test=v.ajouter();
        sms s;
        if(test)
        {
            //refresh(actualiser)
            ui->tableView->setModel(Etmp.afficher());
            ui->tableView->setItemDelegateForColumn(4, new ImageDelegate(this));
            s.sendSMS("+21650214128", "ajout un nouvelle vehicule avec succès   ID: " + id_veh_str + " | Type: " + type_veh + " | Date Entretien: " + date_entretien +" | Kilometrage: " + kilometrage);
        //    QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
      //  }
        //else
         //   QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}
}
void MainWindow::on_pushButton_supprimer_clicked()
{
    int id_veh=ui->linesupp->text().toInt();
    bool test=Etmp.supprimer(id_veh);
    if (test)
    {
        //refresh
        ui->tableView->setModel(Etmp.afficher());
        ui->tableView->setItemDelegateForColumn(4, new ImageDelegate(this));
        //QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("suppression effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    //else
       // QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}


void MainWindow::on_pushButton_modifier_clicked()
{

                        QMessageBox::StandardButton reply;
                        reply= QMessageBox::question(this, "Confirmation", "voulez vous modifier?",
                                                      QMessageBox::Yes|QMessageBox::No);
                        if(reply == QMessageBox::Yes)
                        {int id_veh=ui->lineid->text().toInt();
                            QString type_veh=ui->linetype->currentText();
                            QString date_entretien=ui->linedate->text();
                            QString kilometrage=ui->linekilo->text();

                            vehicule v(id_veh,type_veh,date_entretien,kilometrage,destinationPath);
                           QString id_veh_str = QString::number(id_veh);

                      QSqlQuery quer;
                         quer.prepare("UPDATE VEHICULE SET ID_VEH= :id_veh ,TYPE_VEH= :type_veh, DATE_ENTRETIEN= :date_entretien , KILOMETRAGE=:kilometrage where  ID_VEH= :id_veh");
                         quer.bindValue(":id_veh", id_veh);
                         quer.bindValue(":type_veh", type_veh);
                         quer.bindValue(":date_entretien", date_entretien);
                         quer.bindValue(":kilometrage", kilometrage);

                       QMessageBox msgBox;
                       if(quer.exec())
                       {
                       msgBox.setText("Modification avec succes.");
                       //ui->tableView->setModel(Etmp.afficher());

                       }
                       else
                          {msgBox.setText("échec de modification");
                            msgBox.exec();
                           }
                        }
}

void MainWindow::on_triId_8_clicked()
{
    ui->tableView->setModel(Etmp.triID());
}

void MainWindow::on_pushButton_6_clicked() //pdf_button
{
    QPdfWriter pdf("C:/Users/Rana/Desktop/ranan/gestion-de_vehicules/gestion-de_vehicules/pdf/Liste_vehicule.pdf");

       QPainter painter(&pdf);
       int i = 4100;

              QColor dateColor(0x4a5bcf);
              painter.setPen(dateColor);

              painter.setFont(QFont("Montserrat SemiBold", 11));
              QDate cd = QDate::currentDate();
              painter.drawText(8400,250,cd.toString("Tunis"));
              painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

              QColor titleColor(0x341763);
              painter.setPen(titleColor);
              painter.setFont(QFont("Montserrat SemiBold", 25));

              painter.drawText(3000,2700,"Liste des Vehicule");

              painter.setPen(Qt::black);
              painter.setFont(QFont("Time New Roman", 15));
              painter.drawRect(100,3300,9400,500);

              painter.setFont(QFont("Montserrat SemiBold", 10));

              painter.drawText(500,3600,"id_veh");
              painter.drawText(2000,3600,"type_veh");
              painter.drawText(3300,3600,"date_entretien");
              painter.drawText(4500,3600,"kilometrage");

              painter.setFont(QFont("Montserrat", 10));
              painter.drawRect(100,3300,9400,9000);

              QSqlQuery query;
              query.prepare("select * from vehicule");
              query.exec();
              int y=4300;
              while (query.next())
              {
                  painter.drawLine(100,y,9490,y);
                  y+=500;
                  painter.drawText(500,i,query.value(0).toString());
                  painter.drawText(2000,i,query.value(1).toString());
                  painter.drawText(3300,i,query.value(2).toString());
                  painter.drawText(4500,i,query.value(3).toString());
                  painter.drawText(7500,i,query.value(4).toString());

                 i = i + 500;
              }
              QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
              QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_pushButton_4_clicked() //statistique_button
{
    vehicule Etmp;
        QBarSet *set0 = new QBarSet("");

        *set0  << Etmp.statistiquesvehicule("Audi")<< Etmp.statistiquesvehicule("BMW")<< Etmp.statistiquesvehicule("Mercedes");


        QColor color(0x6568F3);
        set0->setColor(color);

        QBarSeries *series = new QBarSeries();
        series->append(set0);




        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setBackgroundVisible(false);

        QColor bgColor(0xF4DCD3);
                       chart->setBackgroundBrush(QBrush(QColor(bgColor)));

                       chart->setBackgroundVisible(true);

        QStringList categories;
        categories  << "Audi"<< "BMW"<< "Mecedes";
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis, series);

        QChartView *chartView = new QChartView(chart);

        chartView->setMinimumWidth(500);
        chartView->setMinimumHeight(300);
        chartView->setParent(ui->statE);
        chart->legend()->setAlignment(Qt::AlignBottom);
        chartView->show();


}



void MainWindow::on_recherche_2_clicked()
{
    vehicule Etmp;
     ui->tableView->setModel(Etmp.recherche_vehicule(ui->recherche->text()));
}
/*
void MainWindow::on_send_clicked()
{
    sms s;
     const QString msg = ui->msg->toPlainText();

    const QString recipient_phone_number = "+216"+ ui->tlf->text();

   s.sendSMS(recipient_phone_number, msg);

}
*/

void MainWindow::on_image_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    if (!imagePath.isEmpty()) {
        // Determine the current working directory
        QString currentDir = QDir::currentPath();

        // Create the Resources folder if it doesn't exist
        QString saveDirectory = currentDir + "/Resources/";
        QDir().mkpath(saveDirectory);

        // Extract the file name from the full path
        QString fileName = QFileInfo(imagePath).fileName();

        // Create the destination path
       // destinationPath = saveDirectory + fileName;

        // Copy the file
       // if (QFile::copy(imagePath, destinationPath)) {
          //  qDebug() << "Image copied successfully to:" << destinationPath;

            // Now you can use destinationPath as needed (e.g., store it in the database or display the image)
        } else {
            qDebug() << "Failed to copy image!";
        }
    }

//}


/*
void MainWindow::on_pbon_clicked()
{
        int bytesWritten = A.write_to_arduino("1");

       if (bytesWritten == -1) {
           qDebug() << "Échec de l'envoi de la commande 'On' à l'Arduino.";
       } else {
           qDebug() << "Commande 'On' envoyée avec succès à l'Arduino.";

       }
}

void MainWindow::on_pboff_clicked()
{

  //  int bytesWritten = A.write_to_arduino("0");

       if (bytesWritten == -1) {
           qDebug() << "Échec de l'envoi de la commande 'Off' à l'Arduino.";
       } else {
           qDebug() << "Commande 'Off' envoyée avec succès à l'Arduino.";
       }
}
*/
void MainWindow::on_pushButton_clicked()
{
    if (Etmp.incrementNbVeh()) {
        QMessageBox::information(this, "Success", "Number of vehicles incremented successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Failed to increment the number of vehicles.");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if (Etmp.decrementNbVeh()) {
        QMessageBox::information(this, "Success", "Number of vehicles decremented successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Failed to decrement the number of vehicles. Current count might already be 0.");
    }
}

//void MainWindow::on_bu_clicked()
//{
    //data= A.read_from_arduino();
        // qDebug() <<data;
       // vehicule v;
      //  if (data== "1" || data == "1\r\n") {
          //  v.incrementNbVeh();
//         qDebug() << "Successfully incremented nb_veh";
            //}
//}













void MainWindow::on_lineid_cursorPositionChanged(int arg1, int arg2)
{
    // mainwindow.cpp (in the constructor or setup code)
    connect(ui->lineid, SIGNAL(cursorPositionChanged(int, int)), this, SLOT(on_lineid_cursorPositionChanged(int, int)));

}
