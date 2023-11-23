#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vehicule.h"
#include <QMessageBox>



#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>



#include <QDialog>
#include <QSettings>
#include <QTextStream>
#include <QFile>
#include <QDataStream>


#include <QPdfWriter>
#include <QPainter>
#include <QDataStream>
#include <QDate>

#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QComboBox>

#include "sms.h"
#include "ImageDelegate.h"
QString destinationPath;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   vehicule Etmp;
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
    ui->tableView->setItemDelegateForColumn(4, new ImageDelegate(this));
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_ajout_clicked()
{
    //recuperation des informations saisies dans les 3 champs
        int id_veh=ui->lineid->text().toInt();
        QString type_veh=ui->linetype->currentText();

        QString date_entretien=ui->linedate->text();
        QString kilometrage=ui->linekilo->text();
        QString id_veh_str = QString::number(id_veh);

        vehicule v(id_veh,type_veh,date_entretien,kilometrage,destinationPath);
        bool test=v.ajouter();
        sms s;
        if(test)
        {
            //refresh(actualiser)
            ui->tableView->setModel(Etmp.afficher());
            ui->tableView->setItemDelegateForColumn(4, new ImageDelegate(this));
            s.sendSMS("+21650214128", "ajout un nouvelle vehicule avec succès   ID: " + id_veh_str + " | Type: " + type_veh + " | Date Entretien: " + date_entretien +" | Kilometrage: " + kilometrage);
            QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    int id_veh=ui->linesupp->text().toInt();
    bool test=Etmp.supprimer(id_veh);
    if (test)
    {
        //refresh
        ui->tableView->setModel(Etmp.afficher());
        ui->tableView->setItemDelegateForColumn(4, new ImageDelegate(this));
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("suppression effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_modifier_clicked()
{

                        QMessageBox::StandardButton reply;
                        reply= QMessageBox::question(this, "Confirmation", "voulez vous modifier?",
                                                      QMessageBox::Yes|QMessageBox::No);
                        if(reply == QMessageBox::Yes)
                        {int id_veh=ui->lineid->text().toInt();
                            QString type_veh=ui->linetype->currentText();
                            QString date_entretien=ui->linedate->text();
                            QString kilometrage=ui->linekilo->text();

                            vehicule v(id_veh,type_veh,date_entretien,kilometrage,destinationPath);
                           // QString id_veh_str = QString::number(id_veh);

                      QSqlQuery quer;
                         quer.prepare("UPDATE VEHICULE SET ID_VEH= :id_veh ,TYPE_VEH= :type_veh, DATE_ENTRETIEN= :date_entretien , KILOMETRAGE=:kilometrage where  ID_VEH= :id_veh");
                         quer.bindValue(":id_veh", id_veh);
                         quer.bindValue(":type_veh", type_veh);
                         quer.bindValue(":date_entretien", date_entretien);
                         quer.bindValue(":kilometrage", kilometrage);

                       QMessageBox msgBox;
                       if(quer.exec())
                       {
                       msgBox.setText("Modification avec succes.");
                       ui->tableView->setModel(Etmp.afficher());

                       }
                       else
                          {msgBox.setText("échec de modification");
                            msgBox.exec();
                           }
                        }
}

void MainWindow::on_triId_8_clicked()
{
    ui->tableView->setModel(Etmp.triID());
}

void MainWindow::on_pushButton_6_clicked() //pdf_button
{
    QPdfWriter pdf("C:/Users/Rana/Downloads/gestion-de_vehicules1 (7)/gestion-de_vehicules/pdf/Liste_vehicule.pdf");

       QPainter painter(&pdf);
       int i = 4100;

              QColor dateColor(0x4a5bcf);
              painter.setPen(dateColor);

              painter.setFont(QFont("Montserrat SemiBold", 11));
              QDate cd = QDate::currentDate();
              painter.drawText(8400,250,cd.toString("Tunis"));
              painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

              QColor titleColor(0x341763);
              painter.setPen(titleColor);
              painter.setFont(QFont("Montserrat SemiBold", 25));

              painter.drawText(3000,2700,"Liste des Vehicule");

              painter.setPen(Qt::black);
              painter.setFont(QFont("Time New Roman", 15));
              painter.drawRect(100,3300,9400,500);

              painter.setFont(QFont("Montserrat SemiBold", 10));

              painter.drawText(500,3600,"id_veh");
              painter.drawText(2000,3600,"type_veh");
              painter.drawText(3300,3600,"date_entretien");
              painter.drawText(4500,3600,"kilometrage");

              painter.setFont(QFont("Montserrat", 10));
              painter.drawRect(100,3300,9400,9000);

              QSqlQuery query;
              query.prepare("select * from vehicule");
              query.exec();
              int y=4300;
              while (query.next())
              {
                  painter.drawLine(100,y,9490,y);
                  y+=500;
                  painter.drawText(500,i,query.value(0).toString());
                  painter.drawText(2000,i,query.value(1).toString());
                  painter.drawText(3300,i,query.value(2).toString());
                  painter.drawText(4500,i,query.value(3).toString());
                  painter.drawText(7500,i,query.value(4).toString());

                 i = i + 500;
              }
              QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
              QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_pushButton_4_clicked() //statistique_button
{
    vehicule Etmp;
        QBarSet *set0 = new QBarSet("");

        *set0  << Etmp.statistiquesvehicule("Audi")<< Etmp.statistiquesvehicule("BMW")<< Etmp.statistiquesvehicule("Mercedes");


        QColor color(0x6568F3);
        set0->setColor(color);

        QBarSeries *series = new QBarSeries();
        series->append(set0);




        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setBackgroundVisible(false);

        QColor bgColor(0xF4DCD3);
                       chart->setBackgroundBrush(QBrush(QColor(bgColor)));

                       chart->setBackgroundVisible(true);

        QStringList categories;
        categories  << "Audi"<< "BMW"<< "Mecedes";
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis, series);

        QChartView *chartView = new QChartView(chart);

        chartView->setMinimumWidth(500);
        chartView->setMinimumHeight(300);
        chartView->setParent(ui->statE);
        chart->legend()->setAlignment(Qt::AlignBottom);
        chartView->show();

}



void MainWindow::on_recherche_2_clicked()
{
    vehicule Etmp;
     ui->tableView->setModel(Etmp.recherche_vehicule(ui->recherche->text()));
}
/*
void MainWindow::on_send_clicked()
{
    sms s;
     const QString msg = ui->msg->toPlainText();

    const QString recipient_phone_number = "+216"+ ui->tlf->text();

   s.sendSMS(recipient_phone_number, msg);

}
*/

void MainWindow::on_image_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    if (!imagePath.isEmpty()) {
        // Determine the current working directory
        QString currentDir = QDir::currentPath();

        // Create the Resources folder if it doesn't exist
        QString saveDirectory = currentDir + "/Resources/";
        QDir().mkpath(saveDirectory);

        // Extract the file name from the full path
        QString fileName = QFileInfo(imagePath).fileName();

        // Create the destination path
        destinationPath = saveDirectory + fileName;

        // Copy the file
        if (QFile::copy(imagePath, destinationPath)) {
            qDebug() << "Image copied successfully to:" << destinationPath;

            // Now you can use destinationPath as needed (e.g., store it in the database or display the image)
        } else {
            qDebug() << "Failed to copy image!";
        }
    }

}
