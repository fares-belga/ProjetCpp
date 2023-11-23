#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
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
#include "admins.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
      //  ui->tab_client->hide(); fi integ
    }
    stat();
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
        bool test=C.modifier(C.getcin());


        C.afficher();
        stat();
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)//recherche
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

void MainWindow::on_pushButton_clicked()
{

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
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)//triii
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

void MainWindow::on_pushButton_2_clicked()//deconnect
{
    QSqlQuery query;

       admins a;
      QString id=a.getid();
      int action=0;
      QString res=QString::number(action);
      query.prepare("UPDATE admin "" SET action=:action  where username='"+id+"' ");
        query.bindValue(":action",res);
        query.exec();

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

void MainWindow::on_pushButton_3_clicked() //fidelitéé
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
