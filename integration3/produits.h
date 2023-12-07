#ifndef Produits_H
#define Produits_H
#include <QString>
#include<iostream>
#include <QSqlQueryModel>
#include <QDate>





class produits
{


    public:
        produits();
       produits(int,float,QString,int,QString,QString);
        bool ajouter();
    bool modifier(int reference_produit );
    bool existeReference(int reference) const;
        QSqlQueryModel* afficher();
        bool supprimer(int REFERENCE_PRODUIT );

        int Getreference_produit();
        void Setreference_produit(int);
       float Getprix();
        void Setprix(float) ;
        QString Getdate_produit();
        void Setdate_produit(QString);
        int Getquantite();
        void Setquantite(int);
        QString GetNOM();
        void SetNOM(QString);
        QString GeteEMAIL();
        void SetEMAIL(QString);

         void SetOutputFormat();


         QSqlQueryModel* rechercherProduit(QString recherche);
          QSqlQueryModel *tri_reference_produit();
          QSqlQueryModel *tri_prix();

            void arduino(QString code , QString action);



    protected:

    private:
        int REFERENCE_PRODUIT;
        float PRIX;
        QString DATE_PRODUIT;
        int QUANTITE;
        QString NOM;
        QString EMAIL;

};


#endif // PRODUIT_H
