#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QString>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
using namespace std;
#include "connection.h"
#include <iostream>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->le_cin->setValidator(new QIntValidator(0, 9999999, this));

    ui->tab_client->setModel(C.afficher());
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

Client C(cin,addmail,adresslivr);
bool test=C.ajouter();
if(test){
    ui->tab_client->setModel(C.afficher());
    QMessageBox::information(nullptr,QObject::tr("ok"),
                             QObject::tr("ajout avec succces \n" "click cancel to exit"),QMessageBox::Cancel);


}
else{
    QMessageBox::critical(nullptr, QObject::tr("not ok"),
                QObject::tr(" ajout non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}


}

void MainWindow::on_pb_supprimer_clicked()
{
    Client C1;
    C1.setcin(ui->le_idsupp->text().toInt());
    bool test=C1.supprimer(C1.getcin());

    if(test){
        ui->tab_client->setModel(C.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("suppression avec succces \n" "click cancel to exit"),QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr,QObject::tr("ok"),
                                 QObject::tr("suppression non effectué \n" "click cancel to exit"),QMessageBox::Cancel);

}


void MainWindow::on_pb_modifier_clicked()
{

        Client C;
        C.setcin(ui->le_idmodif->text().toInt());
        C.setaddmail(ui->le_modifaddmail->text());
        C.setadresslivr(ui->le_modifadd->text());
        bool test=C.modifier(C.getcin());
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("modifier un point"),
                              QObject::tr("point modifier.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("modifier un point"),
                             QObject::tr("Erreur !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
        }

        C.afficher();
}
