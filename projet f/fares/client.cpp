#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QString>
#include <iostream>
#include <QMessageBox>

using namespace std;

Client::Client()
{
cin=0;addmail="";adresslivr="",nbach=0;

}
Client::Client(int cin,QString addmail,QString adresslivr,int nbach){

    this->cin=cin;  this->addmail=addmail; this->adresslivr=adresslivr;this->nbach=nbach;
}
int Client::getcin(){return cin;}
QString Client::getaddmail(){return addmail;}
QString Client::getadresslivr(){return adresslivr;}
void Client::setcin(int cin){this->cin=cin;}
void Client::setaddmail(QString addmail){this->addmail=addmail;}
void Client::setadresslivr(QString adresslivr){this->adresslivr=adresslivr;}
void Client::setnchat(int nachat){this->nbach=nachat;}
bool Client::ajouter(){


QSqlQuery query;
    QString res=QString::number(cin);
QString res1=QString::number(nbach);
          query.prepare("INSERT INTO CLIENTS (cin, addmail, adresslivr,nbach) "
                        "VALUES (:cin, :addmail, :adresslivr,:nbach)");
          query.bindValue(":cin", res);
          query.bindValue(":addmail", addmail);
          query.bindValue(":adresslivr",adresslivr);
          query.bindValue(":nbach",res1);
          return query.exec();


}
bool Client::supprimer(int cin){

    QSqlQuery query;
          query.prepare("Delete from CLIENTS where cin=:cin");
                        query.bindValue(0, cin);
                        return query.exec();


}
bool Client::exporterPDF(QString fileName, QSqlQueryModel* model)//pdff
{
    QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);

            // Écrire les données du modèle dans le fichier PDF
            for (int row = 0; row < model->rowCount(); ++row) {
                for (int column = 0; column < model->columnCount(); ++column) {
                    stream << model->data(model->index(row, column)).toString() << "\t";
                }
                stream << "\n";
            }

            file.close();
            return true;
        } else {
            QMessageBox::warning(nullptr, "Erreur", "Impossible d'ouvrir le fichier pour l'exportation PDF.");
            return false;
        }
}

QSqlQueryModel* Client::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();

       model->setQuery("SELECT* FROM CLIENTS");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
       model->setHeaderData(1, Qt::Horizontal,  QObject::tr("addmail"));
       model->setHeaderData(2, Qt::Horizontal,  QObject::tr("adresslivr"));
       model->setHeaderData(3, Qt::Horizontal,  QObject::tr("nbach"));

    return model;
}

bool Client::modifier(int cin)
{
    QSqlQuery query ;
    QString id_string=QString::number(cin);
    QString res=QString::number(nbach);

    query.prepare("Update CLIENTS set addmail=:addmail,adresslivr=:adresslivr,NBACH=:nbach where cin=:cin");
    query.bindValue(":cin", id_string);
    query.bindValue(":addmail",addmail );
    query.bindValue(":adresslivr",adresslivr );
    query.bindValue(":nbach",res);


   return query.exec();
}
Client Client::clientFidele()
{
    QSqlQuery query;
          query.prepare("SELECT * from clients order by nbach DESC");

          if (!query.exec()) {
              return Client();
          }

          if (query.next()) {
              int cin = query.value(0).toInt();
              QString mail = query.value(1).toString();
              QString adr = query.value(2).toString();
              int nbra = query.value(3).toInt();

              Client cl(cin, mail, adr,nbra);

              return cl;
          } else {
              qDebug() << "Aucun client trouvé.";
              return Client(); // Retourne un employé par défaut
          }
}
