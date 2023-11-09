#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap image("C:\\Users\\USER\\Documents\\QT Projects\\BDProj\\pic.png"); // Replace with the path to your image
       ui->label->setPixmap(image);
       ui->TblData->setModel(cmd.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_btnajouter_clicked()
{

    // Recupération des infos
    int id = ui->TXTBID->text().toUInt();
    QString rp = ui->TXTBREFP->text();
    QString sp = ui->TXTBSP->text();
    // Instancier une commande
    Commande cmd(id, rp, sp);
    bool tst = cmd.ajouter();
    if(tst)
    {
          QMessageBox::information(nullptr, QObject::tr("OK"),
                                   QObject::tr(" Ajout effectué . \n\
                                               Click Cancel to exit."), QMessageBox::Cancel);

    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                              QObject::tr("ajout non effectué.\n\
Click Cancel to exit."), QMessageBox::Cancel);
}
    ui->TblData->setModel(cmd.afficher());
}



void MainWindow::on_btns_clicked()
{

    // Recupération des infos
    int id = ui->TXTBID->text().toUInt();
    bool tst = cmd.supprimer(id);
    if(tst)
    {
          QMessageBox::information(nullptr, QObject::tr("OK"),
                                   QObject::tr(" suppression effectué . \n\
                                               Click Cancel to exit."), QMessageBox::Cancel);

    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                              QObject::tr("suppression non effectué.\n\
Click Cancel to exit."), QMessageBox::Cancel);
}
    ui->TblData->setModel(cmd.afficher());
}

void MainWindow::on_btnm_clicked()
{
    // Recupération des infos
    int id = ui->TXTBID->text().toUInt();
    QString rp = ui->TXTBREFP->text();
    QString sp = ui->TXTBSP->text();
    // Instancier une commande
    Commande cmd(id, rp, sp);
    bool tst = cmd.modifier();
    if(tst)
    {
          QMessageBox::information(nullptr, QObject::tr("OK"),
                                   QObject::tr(" Modification effectué . \n\
                                               Click Cancel to exit."), QMessageBox::Cancel);

    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK "),
                              QObject::tr("Modification non effectué.\n\
Click Cancel to exit."), QMessageBox::Cancel);
}
    ui->TblData->setModel(cmd.afficher());

}
