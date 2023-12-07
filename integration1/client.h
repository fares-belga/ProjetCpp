#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QObject>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QSqlQueryModel>
#include <QFile>
#include <QPdfWriter>
#include <QTextStream>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <iostream>
using namespace std;


class Client
{
public:
    Client();
    Client(int,QString,QString,int);
    int getcin();
    QString getaddmail();
    QString getadresslivr();
    void setcin(int);
    void setnchat(int);
    void setaddmail(QString);
    void setadresslivr(QString);
    bool ajouter();
    int getnbach (){return nbach;};
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
    bool exporterPDF(QString fileName, QSqlQueryModel* model);
Client clientFidele();
private:
    int cin,nbach;
    QString addmail,adresslivr;
protected:

private:

};
class statt{
public:
    QString cin,address;

};
#endif // CLIENT_H
