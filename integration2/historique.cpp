#include "historique.h"
#include <QFile>
#include <QDateTime>
#include "commande.h"
#include <QTextStream>


historique::historique()
{

}

historique::historique(QString action,QString idCmd)
{
     this->action=action;
     this-> idCmd=idCmd;
}

bool historique::saveHistorique(){
    QSqlQuery query;
    query.prepare("INSERT INTO historiquecmnd (action,idCmd)" "VALUES (:action,:idCmd)");
    query.bindValue(":action",action);
    query.bindValue(":idCmd",idCmd);
    return query.exec();
}

QSqlQueryModel * historique::afficherHistorique()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * from historiquecmnd");
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ACTION"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ID Commande"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date"));
    return model;
}
