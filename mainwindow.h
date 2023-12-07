#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "connexion.h"
#include "commande.h"

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

#include <QTextDocument>
#include <QPrinter>
#include <QApplication>
#include <QTextBrowser>
#include "historique.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SortCommands();


private slots:
    void on_BTNAJOUTER_clicked();

    void on_BTNMODIFIER_clicked();

    void on_BTNSUPPRIMER_clicked();

    void on_rechercher_commande1_textChanged(const QString &arg1);

    void on_tri_id_a_clicked();

    void on_tri_date_a_clicked();

    void on_stat_clicked();


    void on_PDF_bb_clicked();

    void on_enrg_bb_clicked();

private:

   QByteArray data;
   QString test;
    Ui::MainWindow *ui;

    Commande c ;

 QStringList files;
 historique h;



};
#endif // MAINWINDOW_H
