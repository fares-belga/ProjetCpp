#include "login.h"
#include "ui_login.h"
#include <QIcon>
#include "mainwindow.h"
#include <QSqlQuery>
#include "QDebug"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}
Login::Login(QString user,QString pass){
    username=user;
    password=pass;


}


void Login::on_pushButton_conn_clicked()
{
    QString user = ui->lineEdit_usernamee->text();
    QString pass = ui->lineEdit_passwordd->text();
    QSqlQuery query;
    query.prepare("SELECT * FROM admin WHERE username = :username AND password = :password");
    query.bindValue(":username", user);
    query.bindValue(":password", pass);
    query.exec();
    if (query.next()) {
        int action = 1;
        QString res = QString::number(action);

        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE admin SET action = :action WHERE username = :username");
        updateQuery.bindValue(":action", res);
        updateQuery.bindValue(":username", user);
        updateQuery.exec();
        hide();
          mainwindow = new MainWindow(this);
        mainwindow ->show();


}
}

