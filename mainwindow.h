#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"produits.h"
#include"notif.h"
#include "smtp.h"
#include "arduino.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pb_Ajouter_clicked();



   void on_pb_supprimer_3_clicked();



   void on_modifier_clicked();

   void on_pb_recherche_clicked();

   void on_le_recherche_textChanged(const QString &arg1);

   void on_le_pdf_clicked();

   void on_BtnEnregistrer_clicked();





   void on_le_tri_clicked();
   void on_le_tri_2_clicked();








   void on_stat_butt_clicked();


private:
   Arduino A;
   QByteArray data;
   QString test;
    Ui::MainWindow *ui;

    produits p ;
notif n;
 QStringList files;
};

#endif // MAINWINDOW_H
