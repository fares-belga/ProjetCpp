
#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23

#-------------------------------------------------
# include<Qtsql/QsqlQuery>
#include<Qtsql/QsqlDatabase>
QT       += core gui sql printsupport  multimedia multimediawidgets charts
QT       += core gui serialport
QT       += sql
QT += core
QT += widgets
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = Atelier_Connexion
TEMPLATE = app
CONFIG +=QTE
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admins.cpp \
    client.cpp \
    commande.cpp \
    connection.cpp \
    historique.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    notif.cpp \
    produits.cpp \
    smtp.cpp

HEADERS += \
   ../../projet c++/build-CLIENT-Desktop_Qt_5_9_9_MinGW_32bit-Debug/ui_mainwindow.h \
    admins.h \
    client.h \
    commande.h \
    connection.h \
    historique.h \
    login.h \
    mainwindow.h \
    notif.h \
    produits.h \
    smtp.h

FORMS += \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
