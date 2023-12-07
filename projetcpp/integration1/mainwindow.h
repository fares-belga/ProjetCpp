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



private:
    Ui::MainWindow *ui;
    Client C;
    QByteArray data; // variable contenant les données reçues
    QString test;
QString ref;
Commande c ;

QStringList files;
historique h;


};

#endif // MAINWINDOW_H
