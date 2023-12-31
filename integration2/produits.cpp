#include "produits.h"
#include <QtDebug>
#include <QSqlQuery>
#include<QObject>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlRecord>
#include<QString>
#include <QSqlQueryModel>
#include<QDate>
#include<QDateTime>
#include "smtp.h"
using namespace std;



produits::produits()
{
  REFERENCE_PRODUIT=0;
   PRIX=0;
   DATE_PRODUITS="";
   QUANTITE=0;
    NOM="";
    EMAIL="";
}

produits::produits(int reference_produit , float prix, QString date_produits , int quantite , QString NOM, QString EMAIL)

{
  this->REFERENCE_PRODUIT=reference_produit;
    this->PRIX=prix;
    this->DATE_PRODUITS=date_produits;
    this->QUANTITE=quantite;
    this->NOM=NOM;
    this->EMAIL=EMAIL;}

int produits::Getreference_produit()
{ return REFERENCE_PRODUIT; }
void produits::Setreference_produit(int reference_produit )
{ this->REFERENCE_PRODUIT = reference_produit; }

float produits::Getprix()
{ return PRIX; }
void produits::Setprix(float prix)
{ this->PRIX = prix; }

QString produits::Getdate_produits()
{ return DATE_PRODUITS; }

void produits::Setdate_produits(QString date_produits)
{ this->DATE_PRODUITS = date_produits; }

int produits::Getquantite()
{ return QUANTITE; }

void produits::Setquantite(int quantite)
{ this->QUANTITE = quantite; }

QString produits::GetNOM()
{ return NOM; }
void produits::SetNOM(QString NOM)
{
    this->NOM= NOM;
}

QString produits:: GeteEMAIL()
{ return EMAIL; }
void produits::SetEMAIL(QString EMAIL)
{
    this->EMAIL = EMAIL;
}



 bool produits::ajouter()
 {
     bool test = false;
     QSqlQuery query;
     QString reference_produit_string = QString::number(REFERENCE_PRODUIT);
   ;


     QString prix_string = QString::number(PRIX);
     QString quantite_string = QString::number(QUANTITE);

    query.prepare("INSERT INTO PRODUITS (REFERENCE_PRODUIT,PRIX , DATE_PRODUITS,QUANTITE,NOM,EMAIL) "
                        "VALUES (:reference_produit, :prix, :date_produits,:quantite,:NOM,:EMAIL)");
          query.bindValue(":reference_produit",reference_produit_string);
          query.bindValue(":prix", prix_string);
          query.bindValue(":date_produits", DATE_PRODUITS);
          query.bindValue(":quantite",quantite_string);
          query.bindValue(":NOM", NOM);
          query.bindValue(":EMAIL", EMAIL);
          bool inserted = query.exec();

                       // Vérifie si l'ajout de la réservation s'est fait avec succès
                   if (inserted) {
                       // Si la réservation a été ajoutée avec succès, envoyez un e-mail de notification
                       QString destinataire = "hammemi.ghofrane@esprit.tn"; // Adresse e-mail du destinataire
                       QString sujet = "Nouvelle réservation ajoutée";
                       QString contenu = "Une nouvelle réservation a été ajoutée.\n"
                                         "reference_produit : " + reference_produit_string + "\n"
                                         "prix: " + prix_string + "\n"
                                         "quantite : " + quantite_string + "\n";

                       // Créez une instance de la classe Smtp en fournissant les informations de connexion SMTP nécessaires
                       Smtp *smtp = new Smtp("hammemi.ghofrane@esprit.tn", "221JFT7467", "smtp.gmail.com", 465);

                       //qDebug("brevo");
                       // Envoyez l'e-mail avec les détails de la réservation
                       smtp->sendMail("hammemi.ghofrane@esprit.tn", destinataire, sujet, contenu);
                       // Supprimez l'instance de Smtp après avoir terminé l'envoi de l'e-mail

                   }

                   // Retourne le résultat de l'ajout de la réservation
                   return inserted;


          if(query.exec()){
              test =true;
         } else {
              qDebug()<<"Error:"<<query.lastError().text();
          }


          return test;

 }
 bool produits::supprimer(int reference_produit  )
 {
     QSqlQuery query;
         query.prepare("SELECT * FROM PRODUITS WHERE REFERENCE_PRODUIT = :reference_produit");
         query.bindValue(":reference_produit", reference_produit);

         if (query.exec() && query.next()) {
             // The reference_produit exists, so we can proceed with deletion.
             query.prepare("DELETE FROM PRODUITS WHERE REFERENCE_PRODUIT = :reference_produit");
             query.bindValue(":reference_produit", reference_produit);
             if (query.exec()) {
                 return true; // Deletion was successful
             } else {
                 qDebug() << "Error during deletion:" << query.lastError().text();
                 return false;
             }
         } else {
             // The reference_produit does not exist.
             return false;
         }
     }
 QSqlQueryModel* produits ::afficher()
 {

   QSqlQueryModel* model=new QSqlQueryModel();


      model->setQuery("SELECT * FROM produits");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference_produit"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_produits"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
   return model;

 }
 bool produits::modifier(int reference_produit)
 {
     bool test = false;
     QSqlQuery query;
     QString reference_produit_string = QString::number(reference_produit);
     QString prix_string = QString::number(PRIX);
     QString quantite_string = QString::number(QUANTITE);

     query.prepare("UPDATE PRODUITS SET PRIX = :prix, DATE_PRODUITS = :date_produit, QUANTITE = :quantite, NOM = :NOM, EMAIL = :EMAIL WHERE REFERENCE_PRODUIT = :reference_produit");
     query.bindValue(":reference_produit", reference_produit_string);
     query.bindValue(":prix", prix_string);
     query.bindValue(":date_produits", DATE_PRODUITS);
     query.bindValue(":quantite", quantite_string);
     query.bindValue(":NOM", NOM);
     query.bindValue(":EMAIL",EMAIL );

     if (query.exec()) {
         test = true;
     } else {
         qDebug() << "Error: " << query.lastError().text();
     }

     return test;
 }
 QSqlQueryModel *produits::rechercherProduit(QString recherche)
             {
                 QSqlQueryModel * model = new QSqlQueryModel();
                 model->setQuery("SELECT * FROM PRODUITS WHERE REFERENCE_PRODUIT LIKE ('%"+recherche+"%')OR UPPER(NOM) LIKE UPPER('%"+recherche+"%')OR PRIX LIKE UPPER('%"+recherche+"%')");
                 model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference_produit"));
                 model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_produits"));
                model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
                 model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));
                 model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));

              return model;


             }
 QSqlQueryModel *produits::tri_reference_produit()
 {

      QSqlQueryModel * model = new QSqlQueryModel();
      model->setQuery("select * from produits order by reference_produit");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference_produit"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
                     model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_produits"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
                    return model;

 }

 QSqlQueryModel *produits::tri_prix()
 {



      QSqlQueryModel * model = new QSqlQueryModel();
      model->setQuery("select * from produits order by prix");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference_produit"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
                     model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_produits"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
                    return model;


 }
















 void produits::arduino(QString code , QString action)
 {

     QSqlQuery query;
     QDateTime time=QDateTime::currentDateTime();
    query.prepare("INSERT INTO HISTOROQUE (CODE,ACTION , TIME) "
                  "VALUES (:code, :action, :time)");
          query.bindValue(":code",code);
          query.bindValue(":action", action);
          query.bindValue(":time", time);
        query.exec();

 }



