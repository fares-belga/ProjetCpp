#include "mainwindow.h"
#include "login.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include "client.h"
#include <QDebug>
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    Client C;
    qDebug();
    bool test=c.createconnect();
    MainWindow w;
    Login l;
    if(test)
    {l.show();

}

    return a.exec();
}


