#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "connection.h"
#include <QMainWindow>
#include "client.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts>
#include "commande.h"

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

#include <QTextDocument>
#include <QPrinter>
#include <QApplication>
#include <QTextBrowser>
#include "historique.h"
#include"produits.h"
#include"notif.h"
#include "smtp.h"
#include "vehicule.h"
QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
      QChartView *chartView ;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void stat();
void closeEvent (QCloseEvent *event);
private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();


    void on_pb_modifier_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_tab_client_clicked(const QModelIndex &index);

    void on_pushButton13_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_21_clicked();

    void on_pushButton_3_clicked();
    //**************************************************************************arsalen****************************************************************************************************************


    void on_BTNAJOUTER_clicked();

    void on_BTNMODIFIER_clicked();

    void on_BTNSUPPRIMER_clicked();

    void on_rechercher_commande1_textChanged(const QString &arg1);

    void on_tri_id_a_clicked();

    void on_tri_date_a_clicked();

    void on_stat_clicked();


    void on_PDF_bb_clicked();

    void on_enrg_bb_clicked();



    void on_le_reference_produit_cursorPositionChanged(int arg1, int arg2);



    //*****************ghof************

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
   //*****
   void on_pushButton_ajout_clicked();

   void on_pushButton_supprimer_clicked();

   void on_pushButton_modifier_clicked();


   void on_triId_8_clicked();

   void on_pushButton_6_clicked();
   void on_pushButton_4_clicked();
   void on_recherche_2_clicked();
   void on_image_clicked();
   void on_bu_clicked();
   void on_pbon_clicked();
   void on_pboff_clicked();
   void on_pushButton_clicked();
   void on_pushButton_2_clicked();

   void on_lineid_cursorPositionChanged(int arg1, int arg2);




   //void on_pushButton_ajout_clickd();
  // void on_pushButton_supprimer_clickd();
  // void on_pushButton_modifier_clickd();


   void on_triId_8_clickd();

private:
    Ui::MainWindow *ui;
    Client C;
    QByteArray data; // variable contenant les données reçues
    QString test;
QString ref;
Commande c ;

QStringList files;
historique h;
produits p ;
notif n;
 QEventLoop loop;
 vehicule Etmp;
 vehicule v;
 //Arduino A;
// QByteArray data;
};

#endif // MAINWINDOW_H
