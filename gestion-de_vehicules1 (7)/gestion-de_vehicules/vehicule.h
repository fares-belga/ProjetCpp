#ifndef VEHICULE_H
#define VEHICULE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class vehicule
{
    int id_veh;
    QString type_veh,date_entretien,kilometrage,image;
public:
    vehicule(){};
    vehicule(int,QString,QString,QString);
    vehicule(int,QString,QString,QString,QString);

    int getid_veh(){return id_veh;};
    QString gettype_veh(){return type_veh;};
    QString getdate_entretien(){return date_entretien;};
    QString getkilometrage(){return kilometrage;};
    QString getImage(){return image;};

    void setid_veh(int id_veh);
    void settype_veh(QString type_veh);
    void setdate_entrtien(QString date_entretien);
    void setkilometrage(QString kilometrage);
    int statistiquesvehicule(QString );
    QSqlQueryModel * recherche_vehicule(QString );
   QSqlQueryModel * triID();
   int statistiquesemploye(QString  type_veh);

    //les fonctions:
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);

};

#endif // VEHICULE_H
