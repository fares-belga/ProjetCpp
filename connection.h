#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDate>

#include"produits.h"
#include"notif.h"



class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool createconnection();
    void closeconnection();

};

#endif // CONNECTION_H
