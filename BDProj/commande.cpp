#include "commande.h"

Commande::Commande() {}

Commande::Commande(int id, QString rp, QString sp)
{
    this->id = id;
    reference_produit = rp;
    status_produit= sp;

}

bool Commande::ajouter()
{
    QSqlQuery query;
    QString res = QString::number (id);
    //prepare () prend la requête en paramètre pour la préparer à l'exécution.

    query.prepare("insert into Commande (id, Reference_Produit, Status_Produit) values(:id,:Reference_Produit,:Status_Produit)");
    //Création des variables liées
    query.bindValue (":id", res);
    query.bindValue (":Reference_Produit", reference_produit) ;
    query.bindValue (":Status_Produit", status_produit);

    return query.exec(); //exec() envoie la requête pour l'exécuter

}

bool Commande::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number (id);
    //prepare () prend la requête en paramètre pour la préparer à l'exécution.

    query.prepare("DELETE FROM  Commande  WHERE ID = :id");
    //Création des variables liées
    query.bindValue (":id", res);

    return query.exec(); //exec() envoie la requête pour l'exécuter
}

bool Commande::modifier()
{
    QSqlQuery query;
    QString res = QString::number (id);
    //prepare () prend la requête en paramètre pour la préparer à l'exécution.

    query.prepare("UPDATE Commande  SET reference_produit = :reference_produit, status_produit = :status_produit where id = :id");
    //Création des variables liées
    query.bindValue (":id", res);
    query.bindValue (":reference_produit", reference_produit) ;
    query.bindValue (":status_produit", status_produit);

    return query.exec(); //exec() envoie la requête pour l'exécuter

}

QSqlQueryModel* Commande::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Commande");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("REFERENCE_PRODUIT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("STATUS_PRODUIT"));
    return model;

}
