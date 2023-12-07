#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include <QString>
#include <QSqlQuery>
#include <QDate>
#include <QSqlQueryModel>

class historique
{
private:
    int id;
    QString action;
    QString idCmd;
    QDate dateCmd;
public:
    historique();
    historique(QString,QString);
    bool saveHistorique();
    QSqlQueryModel* afficherHistorique();
};

#endif // HISTORIQUE_H
