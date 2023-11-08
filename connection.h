#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
using namespace std;

class Connection
{
    QSqlDatabase db;

public:
    Connection();
    bool createconnect();

};

#endif // CONNECTION_H
