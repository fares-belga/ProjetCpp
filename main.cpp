#include "mainwindow.h"
#include "login.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include "client.h"
#include <QDebug>
#include <QSystemTrayIcon>  // Ajout de l'inclusion nécessaire
#include <QIcon>           // Ajout de l'inclusion nécessaire
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ...

    // Création de l'icône du plateau système
    QSystemTrayIcon* trayIcon = new QSystemTrayIcon();

    // Chargement de l'icône depuis un fichier (remplacez le chemin par le vôtre)
    QIcon icon(":/path/to/your/icon.png");

    // Configuration de l'icône pour le QSystemTrayIcon
    trayIcon->setIcon(icon);

    Connection c;
    Client C;
    qDebug();
    bool test = c.createconnect();
    MainWindow w;
    Login l;

    if (test) {
        // Affichage de la fenêtre de connexion
        l.show();
    }

    // Affichage de l'icône du plateau système
    trayIcon->show();

    return a.exec();
}
