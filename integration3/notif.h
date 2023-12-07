#ifndef NOTIF_H
#define NOTIF_H
#include "produits.h"
#include "connection.h"

#include <QSystemTrayIcon>

class notif
{
public:
    notif();
     ~notif();

    void AjouterP();
    void ModifierP();
    void SupprimerP();
    void echec();

private:

    QSystemTrayIcon *notifyIcon;
};

#endif // NOTIF_H





