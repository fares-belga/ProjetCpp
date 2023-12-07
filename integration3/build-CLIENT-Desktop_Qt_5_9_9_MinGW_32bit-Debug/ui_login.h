/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QFrame *frame;
    QLabel *label_conn;
    QPushButton *pushButton_conn;
    QLineEdit *lineEdit_usernamee;
    QLineEdit *lineEdit_passwordd;
    QLabel *label_user;
    QLabel *label_pass;
    QToolButton *toolButton;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(827, 728);
        Login->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(Login);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(180, 140, 420, 490));
        QFont font;
        font.setFamily(QStringLiteral("century gothic"));
        font.setKerning(true);
        frame->setFont(font);
        frame->setStyleSheet(QLatin1String(" *{\n"
"font-family:century gothic;\n"
"font-size:24px;}\n"
"QFrame{\n"
"background : rgba(0,0,0,0.8);\n"
"border-radius:15px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_conn = new QLabel(frame);
        label_conn->setObjectName(QStringLiteral("label_conn"));
        label_conn->setGeometry(QRect(150, 40, 171, 101));
        label_conn->setStyleSheet(QLatin1String("\n"
"QLabel{\n"
"color : white;\n"
"background:transparent;}"));
        pushButton_conn = new QPushButton(frame);
        pushButton_conn->setObjectName(QStringLiteral("pushButton_conn"));
        pushButton_conn->setGeometry(QRect(40, 420, 341, 51));
        pushButton_conn->setStyleSheet(QLatin1String("QPushButton{\n"
"background: #87CEEB;\n"
"color: white;\n"
"border-radius:15px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"color: #333;\n"
"border-radius:15px;\n"
"background: #49ebff;}  "));
        lineEdit_usernamee = new QLineEdit(frame);
        lineEdit_usernamee->setObjectName(QStringLiteral("lineEdit_usernamee"));
        lineEdit_usernamee->setGeometry(QRect(40, 220, 341, 31));
        lineEdit_usernamee->setStyleSheet(QLatin1String("\n"
"QLineEdit\n"
"{\n"
"background:transparent;\n"
"border:none;\n"
"color:#717072;\n"
"border-bottom: 1px solid #717072\n"
"}"));
        lineEdit_passwordd = new QLineEdit(frame);
        lineEdit_passwordd->setObjectName(QStringLiteral("lineEdit_passwordd"));
        lineEdit_passwordd->setGeometry(QRect(40, 320, 341, 31));
        lineEdit_passwordd->setStyleSheet(QLatin1String("\n"
"QLineEdit\n"
"{\n"
"background:transparent;\n"
"border:none;\n"
"color:#717072;\n"
"border-bottom: 1px solid #717072\n"
"}"));
        lineEdit_passwordd->setEchoMode(QLineEdit::Password);
        label_user = new QLabel(frame);
        label_user->setObjectName(QStringLiteral("label_user"));
        label_user->setGeometry(QRect(40, 180, 231, 21));
        label_user->setStyleSheet(QLatin1String("\n"
"QLabel{\n"
"color : white;\n"
"background:transparent;}"));
        label_pass = new QLabel(frame);
        label_pass->setObjectName(QStringLiteral("label_pass"));
        label_pass->setGeometry(QRect(40, 270, 231, 41));
        label_pass->setStyleSheet(QLatin1String("\n"
"QLabel{\n"
"color : white;\n"
"background:transparent;}"));
        toolButton = new QToolButton(Login);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(330, 70, 121, 121));
        toolButton->setStyleSheet(QLatin1String("QToolButton{\n"
"background: #87CEEB;\n"
"border-radius:60px;}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/utilisateur.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(50, 50));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Dialog", Q_NULLPTR));
        label_conn->setText(QApplication::translate("Login", "Connexion", Q_NULLPTR));
        pushButton_conn->setText(QApplication::translate("Login", "Connecter", Q_NULLPTR));
        lineEdit_usernamee->setText(QString());
        lineEdit_usernamee->setPlaceholderText(QApplication::translate("Login", "Nom de utilisateur", Q_NULLPTR));
        lineEdit_passwordd->setText(QString());
        lineEdit_passwordd->setPlaceholderText(QApplication::translate("Login", "Mot de passe", Q_NULLPTR));
        label_user->setText(QApplication::translate("Login", "Nom de Utilisateur", Q_NULLPTR));
        label_pass->setText(QApplication::translate("Login", "Mot de passe", Q_NULLPTR));
        toolButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
