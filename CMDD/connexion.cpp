#include "connexion.h"

Connexion::Connexion()
{
}

bool Connexion::createConnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("ProjetCpp");
    db.setUserName("ghofrane");
    db.setPassword("123456");
    return db.open();

}

void Connexion::closeConnection()
{
    // Fermeture de la base de données
    db.close();

}

Connexion::~Connexion() {}
