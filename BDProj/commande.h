#ifndef COMMANDE_H
#define COMMANDE_H

#include "connexion.h"
#include<QString>
#include<QSqlQueryModel>


class Commande
{
public:
    Commande();
    Commande(int, QString, QString);
    bool ajouter();
    bool supprimer(int id);
    bool modifier();
    QSqlQueryModel* afficher();

private:
    int id;
    QString reference_produit;
    QString status_produit;
};



#endif // COMMANDE_H
