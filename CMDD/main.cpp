#include "mainwindow.h"
#include "connexion.h"

#include <QApplication>
#include<QDebug>

#include <QtSql>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion cnx;
    bool test = cnx.createConnection();
    MainWindow w;
    if(test)
    {
          w.show();
          QMessageBox::information(nullptr, QObject::tr("DataBase is open"),
                                   QObject::tr(" connection successful . \n\
                                               Click Cancel to exit."), QMessageBox::Cancel);

    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("DataBase is not open"),
                              QObject::tr("Connection failed.\n\
Click Cancel to exit."), QMessageBox::Cancel);

    }



    return a.exec();
}
