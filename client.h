#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QObject>
#include <iostream>
using namespace std;


class Client
{
public:
    Client();
    Client(int,QString,QString);
    int getcin();
    QString getaddmail();
    QString getadresslivr();
    void setcin(int);
    void setaddmail(QString);
    void setadresslivr(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
    int cin;
    QString addmail,adresslivr;
protected:

private:

};

#endif // CLIENT_H
