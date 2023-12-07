#include "commande.h"
#include <QtDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlRecord>
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
#include <QDateTime>

Commande::Commande()
{
    ID = 0;

    STATUS_PRODUIT = "";
    DATE_PRODUIT = "";
}

Commande::Commande(int ID, QString STATUS_PRODUIT, QString DATE_PRODUIT,int QUANTITECOMMANDE)
    : ID(ID), STATUS_PRODUIT(STATUS_PRODUIT), DATE_PRODUIT(DATE_PRODUIT),QUANTITECOMMANDE(QUANTITECOMMANDE)
{
}

int Commande::GetID() {
    return ID;
}

void Commande::SetID(int id) {
    ID = id;
}


QString Commande::GetSTATUS_PRODUIT() {
    return STATUS_PRODUIT;
}

void Commande::SetSTATUS_PRODUIT(QString STATUS) {
   STATUS_PRODUIT = STATUS;
}

QString Commande::GetDATE_PRODUIT() {
    return DATE_PRODUIT;
}

void Commande::SetDATE_PRODUIT(QString DATE) {
    DATE_PRODUIT = DATE;
}
int Commande::GetQUANTITECOMMANDE() {
    return QUANTITECOMMANDE;
}

void Commande::SetQUANTITECOMMANDE(int QUANTITECO) {
    QUANTITECOMMANDE = QUANTITECO;
}


bool Commande::ajouter()
{
    QSqlQuery query;
    QString ID_string = QString::number(ID);
    QString QUANTITECOMMANDE_string=QString::number(QUANTITECOMMANDE);

    query.prepare("INSERT INTO COMMANDE (ID, STATUS_PRODUIT, DATE_PRODUIT,QUANTITECOMMANDE) "
                  "VALUES (:ID,  :STATUS_PRODUIT, :DATE_PRODUIT,:QUANTITECOMMANDE)");
    query.bindValue(":ID", ID_string);

    query.bindValue(":STATUS_PRODUIT", STATUS_PRODUIT);
    query.bindValue(":DATE_PRODUIT", DATE_PRODUIT);
    query.bindValue(":QUANTITECOMMANDE", QUANTITECOMMANDE_string);

    bool inserted = query.exec();

    if (inserted) {
       // qDebug() << "Record inserted successfully!";
    } else {
      //  qDebug() << "Error:" << query.lastError().text();
    }

    return inserted;
}


bool Commande::modifier(int ID)
{
    QSqlQuery query;
    query.prepare("UPDATE COMMANDE SET STATUS_PRODUIT = :STATUS_PRODUIT, DATE_PRODUIT = :DATE_PRODUIT,QUANTITECOMMANDE= :QUANTITECOMMANDE WHERE ID = :ID");

    query.bindValue(":ID", ID);

    query.bindValue(":STATUS_PRODUIT", STATUS_PRODUIT);
    query.bindValue(":DATE_PRODUIT", DATE_PRODUIT);
    query.bindValue(":QUANTITECOMMANDE",QUANTITECOMMANDE);
    if (query.exec()) {
      //  qDebug() << "Modification réussie";
        return true;
    } else {
     //   qDebug() << "Erreur lors de la modification : " << query.lastError().text();
        return false;
    }
}
bool Commande::setupDatabaseConnection()
{
    // Your database connection setup code goes here
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "your_connection_name");

    // Replace "your_database_file_path" with the actual path to your SQLite database file
    db.setDatabaseName("your_database_file_path");

    if (!db.open()) {
        //qDebug() << "Error: Failed to open the database." << db.lastError();
        return false;
    }

    return true;
}

QSqlQueryModel* Commande::afficher()
{
    // Ensure the database connection is set up
    if (!setupDatabaseConnection()) {
        // Handle the error, perhaps by returning nullptr or displaying an error message
        return nullptr;
    }

    QSqlQueryModel* model = new QSqlQueryModel();

    // Use an explicit SELECT statement with specific column names
    model->setQuery("SELECT ID, STATUS_PRODUIT, DATE_PRODUIT, QUANTITECOMMANDE FROM COMMANDE");

    // Set header data
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("STATUS_PRODUIT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_PRODUIT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITECOMMANDE"));

    return model;
}
bool Commande:: supprimer(int ID )
{
QSqlQuery query;
    query.prepare("SELECT * FROM COMMANDE WHERE ID = :ID");
    query.bindValue(":ID", ID);

    if (query.exec() && query.next()) {
        // The reference_produit exists, so we can proceed with deletion.
        query.prepare("DELETE FROM COMMANDE WHERE ID = :ID");
        query.bindValue(":ID",ID);
        if (query.exec()) {
            return true; // Deletion was successful
        } else {
         //   qDebug() << "Error during deletion:" << query.lastError().text();
            return false;
        }
    } else {
        // The ID does not exist.
        return false;
    }
}
QSqlQueryModel *Commande::rechercher_commande(QString recherche)
            {
                QSqlQueryModel * model = new QSqlQueryModel();
                model->setQuery("SELECT * FROM COMMANDE WHERE ID LIKE ('%"+recherche+"%')OR UPPER(STATUS_PRODUIT) LIKE UPPER('%"+recherche+"%')OR DATE_PRODUIT LIKE UPPER('%"+recherche+"%')");
                model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
                model->setHeaderData(1, Qt::Horizontal, QObject::tr("STATUS_PRODUIT"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_PRODUIT"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITECOMMANDE"));


             return model;


            }
QSqlQueryModel *Commande::tri_ID()
{

     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("select * from COMMANDE order by ID");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("STATUS_PRODUIT"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_PRODUIT"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITECOMMANDE"));

                   return model;

}

QSqlQueryModel *Commande::tri_DATE_PRODUIT()
{



     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("select * from COMMANDE order by DATE_PRODUIT");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("STATUS_PRODUIT"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_PRODUIT"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("QUANTITECOMMANDE"));

                   return model;


}







