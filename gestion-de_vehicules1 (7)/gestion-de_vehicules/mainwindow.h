#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "vehicule.h"
#include <QMainWindow>

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
    void on_pushButton_ajout_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();


    void on_triId_8_clicked();

    void on_pushButton_6_clicked();



    void on_pushButton_4_clicked();

    void on_recherche_2_clicked();

    void on_image_clicked();

private:
    Ui::MainWindow *ui;
    vehicule Etmp;
    vehicule v;
};

#endif // MAINWINDOW_H
