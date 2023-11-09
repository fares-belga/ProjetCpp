#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "connexion.h"
#include "commande.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btnajouter_clicked();


    void on_btns_clicked();

    void on_btnm_clicked();

private:
    Ui::MainWindow *ui;
    Connexion cnx;
    Commande cmd;
};
#endif // MAINWINDOW_H
