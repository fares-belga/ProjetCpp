#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QString>
#include <iostream>
using namespace std;

Client::Client()
{
cin=0;addmail="";adresslivr="";

}
Client::Client(int cin,QString addmail,QString adresslivr){

    this->cin=cin;  this->addmail=addmail; this->adresslivr=adresslivr;
}
int Client::getcin(){return cin;}
QString Client::getaddmail(){return addmail;}
QString Client::getadresslivr(){return adresslivr;}
void Client::setcin(int cin){this->cin=cin;}
void Client::setaddmail(QString addmail){this->addmail=addmail;}
void Client::setadresslivr(QString adresslivr){this->adresslivr=adresslivr;}

bool Client::ajouter(){


QSqlQuery query;
    QString res=QString::number(cin);

          query.prepare("INSERT INTO CLIENTS (cin, addmail, adresslivr) "
                        "VALUES (:cin, :addmail, :adresslivr)");
          query.bindValue(0, res);
          query.bindValue(1, addmail);
          query.bindValue(2,adresslivr);
          return query.exec();


}
bool Client::supprimer(int cin){

    QSqlQuery query;
          query.prepare("Delete from CLIENTS where cin=:cin");
                        query.bindValue(0, cin);
                        return query.exec();


}
QSqlQueryModel* Client::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();

       model->setQuery("SELECT* FROM CLIENTS");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
       model->setHeaderData(1, Qt::Horizontal,  QObject::tr("addmail"));
       model->setHeaderData(1, Qt::Horizontal,  QObject::tr("adresslivr"));

    return model;
}

bool Client::modifier(int cin)
{
    QSqlQuery query ;
    QString id_string=QString::number(cin);
   
    query.prepare("Update CLIENTS set addmail=:addmail,adresslivr=:adresslivr where cin=:cin");
    query.bindValue(":cin", id_string);
    query.bindValue(":addmail",addmail );
    query.bindValue(":adresslivr",adresslivr );

   return query.exec();
}
