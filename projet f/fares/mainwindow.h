#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    void on_pushButton_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Client C;
};

#endif // MAINWINDOW_H
