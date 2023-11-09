#ifndef CONNEXION_H
#define CONNEXION_H

#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>

class Connexion
{
public:

    Connexion();
    bool createConnection();
    void closeConnection();
     ~Connexion();
private:
    QSqlDatabase db;
};

#endif // CONNEXION_H
