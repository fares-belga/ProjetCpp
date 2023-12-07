#include "notif.h"



notif::notif()
{

}
notif::~notif()
{

}



void notif::AjouterP()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    // Définissez l'icône de l'icône système
    notifyIcon->setIcon(QIcon("C:/Users/hammemi/Pictures/Screenshots/mm.png"));

    notifyIcon->show();
    notifyIcon->showMessage("Gestion des PRODUITS", "Nouveau PRODUIT est ajouté", QSystemTrayIcon::Information, 15000);
}

void notif::ModifierP()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("Gestion des PRODUITS", "PRODUIT modifié", QSystemTrayIcon::Information, 15000);
    notifyIcon->setIcon(QIcon("C:/Users/hammemi/Pictures/Screenshots/mm.png"));
}

void notif::SupprimerP()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("Gestion des PRODUITS", "PRODUIT supprimé", QSystemTrayIcon::Information, 15000);
    notifyIcon->setIcon(QIcon("C:/Users/hammemi/Pictures/Screenshots/mm.png"));
}

void notif::echec()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("Gestion des produits", "Action échouée", QSystemTrayIcon::Critical, 15000);
}
