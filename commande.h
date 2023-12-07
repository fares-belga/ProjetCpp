#ifndef COMMANDE_H
#define COMMANDE_H

#include "connection.h"
#include<QString>
#include<iostream>
#include<QSqlQueryModel>



class Commande
{
public:
    Commande();

           Commande(int,QString,QString,int);
            bool ajouter();
        bool modifier(int ID );
        bool existeID(int ID) const;
            QSqlQueryModel* afficher();
            QSqlQueryModel *rechercher_commande(QString recherche);
            bool supprimer(int ID );
            QSqlQueryModel *tri_ID();
            QSqlQueryModel *tri_DATE_PRODUIT();

            int GetID();
            void SetID(int);


            QString GetSTATUS_PRODUIT();
            void SetSTATUS_PRODUIT(QString);
            QString GetDATE_PRODUIT();
            void SetDATE_PRODUIT(QString);
            int GetQUANTITECOMMANDE();
            void SetQUANTITECOMMANDE(int);

private:
    int ID;

    QString STATUS_PRODUIT;
    QString DATE_PRODUIT;
    int QUANTITECOMMANDE;
    bool setupDatabaseConnection();
};



#endif // COMMANDE_H
