#include "connexion.h"

Connexion::Connexion()
{
}

bool Connexion::createConnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("ProjetCpp");
    db.setUserName("Arsalen");
    db.setPassword("Mamitomamito123");
    return db.open();

}

void Connexion::closeConnection()
{
    // Fermeture de la base de données
    db.close();

}

Connexion::~Connexion() {}
