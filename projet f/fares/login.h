#ifndef LOGIN_H
#define LOGIN_H
#include "mainwindow.h"

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    QString getusername(){return username;}

    Login(QString,QString);
    explicit Login(QWidget *parent = nullptr);
    ~Login();
private slots:
void on_pushButton_conn_clicked();

private:
    Ui::Login *ui;
    MainWindow *mainwindow;
QString username,password;

protected:
};

#endif // LOGIN_H
