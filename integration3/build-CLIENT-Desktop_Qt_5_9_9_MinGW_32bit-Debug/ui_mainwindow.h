/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGroupBox *groupBox_2;
    QLabel *Status_Produit;
    QLabel *ID;
    QLabel *Date_Produit;
    QLineEdit *LE_ID;
    QComboBox *LE_S;
    QDateEdit *LE_DATE;
    QTableView *TAB_CMD;
    QPushButton *BTNAJOUTER;
    QPushButton *BTNMODIFIER;
    QPushButton *BTNSUPPRIMER;
    QTableView *LE_A;
    QTableView *LE_B;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *rechercher_commande1;
    QPushButton *tri_id_a;
    QPushButton *tri_date_a;
    QPushButton *stat;
    QLabel *Date_Produit_2;
    QLineEdit *LE_QUANTITECOMMANDE;
    QPushButton *PDF_bb;
    QPushButton *enrg_bb;
    QLabel *label_18;
    QTableView *historiqueTV;
    QLabel *label_19;
    QWidget *tab;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *le_cin;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *le_addmail;
    QLineEdit *le_adresslivr;
    QPushButton *pb_ajouter;
    QLabel *label_10;
    QLabel *label_13;
    QLineEdit *achat;
    QLabel *label_15;
    QLabel *label_11;
    QLabel *chartview;
    QPushButton *pushButton_21;
    QLabel *label_6;
    QWidget *tab_4;
    QTableView *tab_client;
    QLineEdit *lineEdit;
    QPushButton *pb_supprimer;
    QPushButton *pushButton13;
    QComboBox *comboBox;
    QPushButton *pushButton_3;
    QWidget *tab_5;
    QLabel *label_7;
    QLineEdit *le_idmodif;
    QPushButton *pb_modifier;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *le_modifaddmail;
    QLineEdit *le_modifadd;
    QLabel *label_12;
    QLineEdit *achat_2;
    QLabel *label_14;
    QWidget *tab_6;
    QTabWidget *tabWidget_3;
    QWidget *tab_7;
    QGroupBox *groupBox_3;
    QLabel *reference_produit;
    QLabel *prix;
    QLabel *date_produit;
    QLabel *quantite;
    QLabel *nom;
    QLineEdit *le_reference_produit;
    QLineEdit *le_prix;
    QLineEdit *le_date_produit;
    QLineEdit *le_nom;
    QPushButton *pb_Ajouter;
    QPushButton *pb_supprimer_3;
    QPushButton *modifier;
    QLabel *label_1;
    QTableView *tab_produits;
    QLabel *nom_2;
    QLineEdit *le_email;
    QLineEdit *le_quantite;
    QPushButton *le_pdf;
    QPushButton *le_tri_2;
    QPushButton *le_tri;
    QPushButton *stat_butt;
    QPushButton *BtnEnregistrer;
    QLineEdit *le_recherche;
    QLabel *label_20;
    QWidget *tab_8;
    QTabWidget *tabWidget_4;
    QWidget *tab_9;
    QGroupBox *groupBox_4;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLineEdit *lineid;
    QLineEdit *linedate;
    QLineEdit *linekilo;
    QComboBox *linetype;
    QPushButton *image;
    QPushButton *pboff;
    QPushButton *pbon;
    QTableView *tableView;
    QPushButton *recherche_2;
    QLineEdit *recherche;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *bu;
    QPushButton *triId_8;
    QPushButton *pushButton_6;
    QPushButton *pushButton_ajout;
    QPushButton *pushButton_modifier;
    QLabel *label_25;
    QLabel *label_26;
    QWidget *tab_10;
    QGroupBox *groupBox_5;
    QLabel *label_27;
    QPushButton *pushButton_supprimer;
    QLineEdit *linesupp;
    QWidget *tab_11;
    QGroupBox *ajouter_p_4;
    QPushButton *pushButton_4;
    QFrame *statE;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1650, 1096);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(50, -10, 1201, 751));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget {\n"
"    background-color: #F0F0F0; /* Couleur de fond */\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #FFFFFF; /* Couleur de fond des onglets non s\303\251lectionn\303\251s (blanc) */\n"
"    color: #333; /* Couleur du texte des onglets non s\303\251lectionn\303\251s (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure des onglets non s\303\251lectionn\303\251s (rouge) */\n"
"    padding: 8px 16px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: #FFFFFF; /* Couleur de fond de l'onglet s\303\251lectionn\303\251 (blanc) */\n"
"    color: #333; /* Couleur du texte de l'onglet s\303\251lectionn\303\251 (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure de l'onglet s\303\251lectionn\303\251 (rouge) */\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background-color: #FFFFFF; /* Couleur de fond au survol de l'onglet (blanc) */\n"
"    border: 1px solid #FF0000; /* Bordure au survol de l'onglet (rouge) */\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #FF0000;"
                        " /* Bordure autour du contenu du QTabWidget (rouge) */\n"
"    margin: 5px; /* Marge autour du contenu du QTabWidget */\n"
"}\n"
"\n"
"/* Styles sp\303\251cifiques pour le contenu des onglets, si n\303\251cessaire */\n"
"QTabWidget::tab-bar {\n"
"    alignment: left;\n"
"}\n"
"\n"
""));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 0, 1031, 721));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid red; /* Changer la couleur de la bordure \303\240 rouge */\n"
"    border-radius: 5px;\n"
"    margin-top: 10px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 3px;\n"
"    background-color: red; /* Changer la couleur de fond \303\240 rouge */\n"
"    \n"
"    /* Styles de police pour le titre */\n"
"    font-family: Arial, sans-serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: black; /* Laisser la couleur du texte en noir */\n"
"}"));
        Status_Produit = new QLabel(groupBox_2);
        Status_Produit->setObjectName(QStringLiteral("Status_Produit"));
        Status_Produit->setGeometry(QRect(10, 90, 121, 31));
        Status_Produit->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        ID = new QLabel(groupBox_2);
        ID->setObjectName(QStringLiteral("ID"));
        ID->setGeometry(QRect(10, 30, 61, 31));
        ID->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        Date_Produit = new QLabel(groupBox_2);
        Date_Produit->setObjectName(QStringLiteral("Date_Produit"));
        Date_Produit->setGeometry(QRect(10, 150, 131, 31));
        Date_Produit->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        LE_ID = new QLineEdit(groupBox_2);
        LE_ID->setObjectName(QStringLiteral("LE_ID"));
        LE_ID->setGeometry(QRect(60, 30, 121, 31));
        LE_ID->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
"QLabel#bordureRouge {\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"}\n"
"\n"
""));
        LE_S = new QComboBox(groupBox_2);
        LE_S->setObjectName(QStringLiteral("LE_S"));
        LE_S->setGeometry(QRect(130, 90, 121, 31));
        LE_S->setStyleSheet(QString::fromUtf8("/* Styles de la ComboBox avec des couleurs diff\303\251rentes */\n"
"QComboBox {\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border: 1px solid #808080; /* Bordure pour d\303\251finir les limites du QComboBox (gris) */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    background-color: white; /* Couleur de fond du QComboBox */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #606060; /* Bordure au survol du QComboBox (gris plus fonc\303\251) */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: right center;\n"
"    width: 15px; /* Largeur de la fl\303\250che de d\303\251filement */\n"
"    border-left: 1px solid #808080; /* Bordure \303\240 gauche de la fl\303\250che */\n"
"    background-color: #DCE0EE; /* Couleur de fond de la fl\303\250che"
                        " */\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(arrow_down.png); /* Remplacez avec le chemin de votre propre image de fl\303\250che vers le bas */\n"
"}\n"
"\n"
"QComboBox::down-arrow:disabled {\n"
"    image: url(arrow_down_disabled.png); /* Image de fl\303\250che d\303\251sactiv\303\251e (remplacez le chemin) */\n"
"}\n"
"\n"
"QComboBox::down-arrow:hover {\n"
"    background-color: #C5D9EA; /* Couleur de fond de la fl\303\250che au survol */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    border: 1px solid #808080; /* Bordure du menu d\303\251roulant */\n"
"    selection-background-color: #DCE0EE; /* Couleur de fond de l'\303\251l\303\251ment s\303\251lectionn\303\251 */\n"
"    selection-color: #333; /* Couleur du texte de l'\303\251l\303\251ment s\303\251lectionn\303\251 */\n"
"}\n"
""));
        LE_DATE = new QDateEdit(groupBox_2);
        LE_DATE->setObjectName(QStringLiteral("LE_DATE"));
        LE_DATE->setGeometry(QRect(130, 150, 121, 31));
        LE_DATE->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border: 1px solid #808080; /* Bordure pour d\303\251finir les limites du QComboBox (gris) */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    background-color: white; /* Couleur de fond du QComboBox */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #606060; /* Bordure au survol du QComboBox (gris plus fonc\303\251) */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: right center;\n"
"    width: 15px; /* Largeur de la fl\303\250che de d\303\251filement */\n"
"    border-left: 1px solid #808080; /* Bordure \303\240 gauche de la fl\303\250che */\n"
"    background-color: #DCE0EE; /* Couleur de fond de la fl\303\250che */\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(arrow_d"
                        "own.png); /* Remplacez avec le chemin de votre propre image de fl\303\250che vers le bas */\n"
"}\n"
"\n"
"QComboBox::down-arrow:disabled {\n"
"    image: url(arrow_down_disabled.png); /* Image de fl\303\250che d\303\251sactiv\303\251e (remplacez le chemin) */\n"
"}\n"
"\n"
"QComboBox::down-arrow:hover {\n"
"    background-color: #C5D9EA; /* Couleur de fond de la fl\303\250che au survol */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    border: 1px solid #808080; /* Bordure du menu d\303\251roulant */\n"
"    selection-background-color: #DCE0EE; /* Couleur de fond de l'\303\251l\303\251ment s\303\251lectionn\303\251 */\n"
"    selection-color: #333; /* Couleur du texte de l'\303\251l\303\251ment s\303\251lectionn\303\251 */\n"
"}\n"
"\n"
"\n"
"QDateEdit::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}\n"
""));
        TAB_CMD = new QTableView(groupBox_2);
        TAB_CMD->setObjectName(QStringLiteral("TAB_CMD"));
        TAB_CMD->setGeometry(QRect(310, 80, 611, 311));
        TAB_CMD->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    border:none;\n"
"    font: 75 28pt \"Arial\";\n"
"}\n"
"\n"
"QTableView {\n"
"    background-color: #f5f5f5;\n"
"    alternate-background-color: #e0e0e0;\n"
"    selection-background-color: #a8d8ea;\n"
"    selection-color: #333;\n"
"    gridline-color: #ccc;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #FF0000; /* Rouge */\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #ddd;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #a8d8ea;\n"
"}\n"
"\n"
"QTableView::item:hover {\n"
"    background-color: #d4e9f8;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 1px solid #ddd;\n"
"    background: #FF0000; /* Rouge */\n"
"    width: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #FF0000; /* Rouge */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    border: 1px solid #ddd;\n"
"    height: 10px;\n"
"    subcontr"
                        "ol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    border: 1px solid #ddd;\n"
"    background: #FF0000; /* Rouge */\n"
"    height: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #FF0000; /* Rouge */\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal,\n"
"QScrollBar::sub-line:horizontal {\n"
"    border: 1px solid #ddd;\n"
"    width: 10px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
""));
        BTNAJOUTER = new QPushButton(groupBox_2);
        BTNAJOUTER->setObjectName(QStringLiteral("BTNAJOUTER"));
        BTNAJOUTER->setGeometry(QRect(10, 280, 111, 41));
        BTNAJOUTER->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral("../../1091585.png"), QSize(), QIcon::Normal, QIcon::Off);
        BTNAJOUTER->setIcon(icon);
        BTNAJOUTER->setIconSize(QSize(20, 20));
        BTNMODIFIER = new QPushButton(groupBox_2);
        BTNMODIFIER->setObjectName(QStringLiteral("BTNMODIFIER"));
        BTNMODIFIER->setGeometry(QRect(120, 280, 111, 41));
        BTNMODIFIER->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../6325975.png"), QSize(), QIcon::Normal, QIcon::Off);
        BTNMODIFIER->setIcon(icon1);
        BTNMODIFIER->setIconSize(QSize(20, 20));
        BTNSUPPRIMER = new QPushButton(groupBox_2);
        BTNSUPPRIMER->setObjectName(QStringLiteral("BTNSUPPRIMER"));
        BTNSUPPRIMER->setGeometry(QRect(60, 330, 121, 41));
        BTNSUPPRIMER->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../6861362.png"), QSize(), QIcon::Normal, QIcon::Off);
        BTNSUPPRIMER->setIcon(icon2);
        BTNSUPPRIMER->setIconSize(QSize(20, 20));
        LE_A = new QTableView(groupBox_2);
        LE_A->setObjectName(QStringLiteral("LE_A"));
        LE_A->setGeometry(QRect(820, 550, 61, 51));
        LE_A->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    border:none;\n"
"    font: 75 28pt \"Arial\";\n"
"}\n"
"\n"
"QTableView {\n"
"    background-color: #f5f5f5;\n"
"    alternate-background-color: #e0e0e0;\n"
"    selection-background-color: #a8d8ea;\n"
"    selection-color: #333;\n"
"    gridline-color: #ccc;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #FF0000; /* Rouge */\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #ddd;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #a8d8ea;\n"
"}\n"
"\n"
"QTableView::item:hover {\n"
"    background-color: #d4e9f8;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 1px solid #ddd;\n"
"    background: #FF0000; /* Rouge */\n"
"    width: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #FF0000; /* Rouge */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    border: 1px solid #ddd;\n"
"    height: 10px;\n"
"    subcontr"
                        "ol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    border: 1px solid #ddd;\n"
"    background: #FF0000; /* Rouge */\n"
"    height: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #FF0000; /* Rouge */\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal,\n"
"QScrollBar::sub-line:horizontal {\n"
"    border: 1px solid #ddd;\n"
"    width: 10px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
""));
        LE_B = new QTableView(groupBox_2);
        LE_B->setObjectName(QStringLiteral("LE_B"));
        LE_B->setGeometry(QRect(920, 550, 61, 51));
        LE_B->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    border:none;\n"
"    font: 75 28pt \"Arial\";\n"
"}\n"
"\n"
"QTableView {\n"
"    background-color: #f5f5f5;\n"
"    alternate-background-color: #e0e0e0;\n"
"    selection-background-color: #a8d8ea;\n"
"    selection-color: #333;\n"
"    gridline-color: #ccc;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #FF0000; /* Rouge */\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #ddd;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #a8d8ea;\n"
"}\n"
"\n"
"QTableView::item:hover {\n"
"    background-color: #d4e9f8;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 1px solid #ddd;\n"
"    background: #FF0000; /* Rouge */\n"
"    width: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #FF0000; /* Rouge */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    border: 1px solid #ddd;\n"
"    height: 10px;\n"
"    subcontr"
                        "ol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    border: 1px solid #ddd;\n"
"    background: #FF0000; /* Rouge */\n"
"    height: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #FF0000; /* Rouge */\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal,\n"
"QScrollBar::sub-line:horizontal {\n"
"    border: 1px solid #ddd;\n"
"    width: 10px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
""));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(810, 620, 81, 41));
        label_16->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(900, 620, 101, 41));
        label_17->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        rechercher_commande1 = new QLineEdit(groupBox_2);
        rechercher_commande1->setObjectName(QStringLiteral("rechercher_commande1"));
        rechercher_commande1->setGeometry(QRect(330, 30, 431, 41));
        rechercher_commande1->setStyleSheet(QString::fromUtf8("/* Styles de base pour QLineEdit */\n"
"QLineEdit {\n"
"    background-color: #eee; /* Gris clair */\n"
"    color: #000000; /* Noir */\n"
"    font-size: 16px;\n"
"    font-weight: normal; /* Le style normal est plus appropri\303\251 pour un QLineEdit */\n"
"    border: 2px solid #FF0000; /* Rouge */\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"/* Animation de survol */\n"
"QLineEdit:hover {\n"
"    background-color: #eee /* Gris un peu plus fonc\303\251 au survol */\n"
"}\n"
""));
        tri_id_a = new QPushButton(groupBox_2);
        tri_id_a->setObjectName(QStringLiteral("tri_id_a"));
        tri_id_a->setGeometry(QRect(490, 400, 81, 41));
        tri_id_a->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../../tri.png"), QSize(), QIcon::Normal, QIcon::Off);
        tri_id_a->setIcon(icon3);
        tri_id_a->setIconSize(QSize(40, 40));
        tri_date_a = new QPushButton(groupBox_2);
        tri_date_a->setObjectName(QStringLiteral("tri_date_a"));
        tri_date_a->setGeometry(QRect(570, 400, 81, 41));
        tri_date_a->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}"));
        tri_date_a->setIcon(icon3);
        tri_date_a->setIconSize(QSize(40, 40));
        stat = new QPushButton(groupBox_2);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(780, 20, 51, 51));
        stat->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: none;\n"
"    font: 8pt \"Sitka Display Semibold\";\n"
"    text-align: middle;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: rgb(255, 255, 255);\n"
" \n"
"\n"
"    border: none;\n"
"    text-align: middle;\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../../Downloads/4624024.png"), QSize(), QIcon::Normal, QIcon::Off);
        stat->setIcon(icon4);
        stat->setIconSize(QSize(50, 50));
        Date_Produit_2 = new QLabel(groupBox_2);
        Date_Produit_2->setObjectName(QStringLiteral("Date_Produit_2"));
        Date_Produit_2->setGeometry(QRect(10, 220, 171, 31));
        Date_Produit_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        LE_QUANTITECOMMANDE = new QLineEdit(groupBox_2);
        LE_QUANTITECOMMANDE->setObjectName(QStringLiteral("LE_QUANTITECOMMANDE"));
        LE_QUANTITECOMMANDE->setGeometry(QRect(160, 220, 121, 31));
        LE_QUANTITECOMMANDE->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
"QLabel#bordureRouge {\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"}\n"
""));
        PDF_bb = new QPushButton(groupBox_2);
        PDF_bb->setObjectName(QStringLiteral("PDF_bb"));
        PDF_bb->setGeometry(QRect(1290, 620, 93, 81));
        PDF_bb->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: none;\n"
"    font: 8pt \"Sitka Display Semibold\";\n"
"    text-align: middle;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: rgb(255, 255, 255);\n"
" \n"
"\n"
"    border: none;\n"
"    text-align: middle;\n"
"}\n"
""));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../../337946.png"), QSize(), QIcon::Normal, QIcon::Off);
        PDF_bb->setIcon(icon5);
        PDF_bb->setIconSize(QSize(50, 50));
        enrg_bb = new QPushButton(groupBox_2);
        enrg_bb->setObjectName(QStringLiteral("enrg_bb"));
        enrg_bb->setGeometry(QRect(1360, 640, 71, 51));
        enrg_bb->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: none;\n"
"    font: 8pt \"Sitka Display Semibold\";\n"
"    text-align: middle;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: rgb(255, 255, 255);\n"
" \n"
"\n"
"    border: none;\n"
"    text-align: middle;\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QStringLiteral("../../2810399.png"), QSize(), QIcon::Normal, QIcon::Off);
        enrg_bb->setIcon(icon6);
        enrg_bb->setIconSize(QSize(35, 35));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(970, 70, 51, 21));
        label_18->setPixmap(QPixmap(QString::fromUtf8("../../editfind_104370.png")));
        label_18->setScaledContents(true);
        historiqueTV = new QTableView(groupBox_2);
        historiqueTV->setObjectName(QStringLiteral("historiqueTV"));
        historiqueTV->setGeometry(QRect(20, 410, 411, 271));
        historiqueTV->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    border:none;\n"
"    font: 75 28pt \"Arial\";\n"
"}\n"
"\n"
"QTableView {\n"
"    background-color: #f5f5f5;\n"
"    alternate-background-color: #e0e0e0;\n"
"    selection-background-color: #a8d8ea;\n"
"    selection-color: #333;\n"
"    gridline-color: #ccc;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #FF0000; /* Rouge */\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #ddd;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #a8d8ea;\n"
"}\n"
"\n"
"QTableView::item:hover {\n"
"    background-color: #d4e9f8;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 1px solid #ddd;\n"
"    background: #FF0000; /* Rouge */\n"
"    width: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #FF0000; /* Rouge */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    border: 1px solid #ddd;\n"
"    height: 10px;\n"
"    subcontr"
                        "ol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    border: 1px solid #ddd;\n"
"    background: #FF0000; /* Rouge */\n"
"    height: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #FF0000; /* Rouge */\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal,\n"
"QScrollBar::sub-line:horizontal {\n"
"    border: 1px solid #ddd;\n"
"    width: 10px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
""));
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(450, 510, 191, 31));
        label_19->setStyleSheet(QLatin1String("font:  75 16pt \"Times New Roman\";\n"
"color: rgb(44, 51, 89);"));
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 1251, 711));
        tabWidget_2->setStyleSheet(QLatin1String("background-color: rgb(232, 232, 232);\n"
"background-color: rgb(255, 255, 255);"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 0, 991, 491));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid red; /* Changer la couleur de la bordure \303\240 rouge */\n"
"    border-radius: 5px;\n"
"    margin-top: 10px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 3px;\n"
"    background-color: red; /* Changer la couleur de fond \303\240 rouge */\n"
"    \n"
"    /* Styles de police pour le titre */\n"
"    font-family: Arial, sans-serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: black; /* Laisser la couleur du texte en noir */\n"
"}"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 71, 31));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(500, 200, 47, 14));
        le_cin = new QLineEdit(groupBox);
        le_cin->setObjectName(QStringLiteral("le_cin"));
        le_cin->setGeometry(QRect(70, 40, 171, 31));
        le_cin->setStyleSheet(QLatin1String("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(46, 80, 51, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 80, 91, 31));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 120, 131, 31));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        le_addmail = new QLineEdit(groupBox);
        le_addmail->setObjectName(QStringLiteral("le_addmail"));
        le_addmail->setGeometry(QRect(90, 80, 161, 31));
        le_addmail->setStyleSheet(QLatin1String("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}"));
        le_adresslivr = new QLineEdit(groupBox);
        le_adresslivr->setObjectName(QStringLiteral("le_adresslivr"));
        le_adresslivr->setGeometry(QRect(120, 120, 171, 31));
        le_adresslivr->setStyleSheet(QLatin1String("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}"));
        pb_ajouter = new QPushButton(groupBox);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(30, 260, 111, 41));
        pb_ajouter->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}\n"
""));
        QIcon icon7;
        icon7.addFile(QStringLiteral("../1091585.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_ajouter->setIcon(icon7);
        pb_ajouter->setIconSize(QSize(25, 25));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(560, 30, 121, 91));
        label_10->setPixmap(QPixmap(QString::fromUtf8("../Pictures/logo.png")));
        label_10->setScaledContents(true);
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 160, 111, 31));
        label_13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        achat = new QLineEdit(groupBox);
        achat->setObjectName(QStringLiteral("achat"));
        achat->setGeometry(QRect(100, 160, 171, 31));
        achat->setStyleSheet(QLatin1String("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}"));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(90, 380, 681, 41));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(190, 360, 221, 16));
        chartview = new QLabel(groupBox);
        chartview->setObjectName(QStringLiteral("chartview"));
        chartview->setGeometry(QRect(460, 40, 351, 271));
        pushButton_21 = new QPushButton(groupBox);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setGeometry(QRect(140, 260, 111, 41));
        pushButton_21->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}\n"
"\n"
""));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 230, 47, 14));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tab_client = new QTableView(tab_4);
        tab_client->setObjectName(QStringLiteral("tab_client"));
        tab_client->setGeometry(QRect(10, 70, 561, 291));
        tab_client->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    border:none;\n"
"    font: 75 28pt \"Arial\";\n"
"}\n"
"\n"
"QTableView {\n"
"    background-color: #f5f5f5;\n"
"    alternate-background-color: #e0e0e0;\n"
"    selection-background-color: #a8d8ea;\n"
"    selection-color: #333;\n"
"    gridline-color: #ccc;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #FF0000; /* Rouge */\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #ddd;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #a8d8ea;\n"
"}\n"
"\n"
"QTableView::item:hover {\n"
"    background-color: #d4e9f8;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 1px solid #ddd;\n"
"    background: #FF0000; /* Rouge */\n"
"    width: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #FF0000; /* Rouge */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    border: 1px solid #ddd;\n"
"    height: 10px;\n"
"    subcontr"
                        "ol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    border: 1px solid #ddd;\n"
"    background: #FF0000; /* Rouge */\n"
"    height: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #FF0000; /* Rouge */\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal,\n"
"QScrollBar::sub-line:horizontal {\n"
"    border: 1px solid #ddd;\n"
"    width: 10px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
""));
        tab_client->setSelectionBehavior(QAbstractItemView::SelectRows);
        lineEdit = new QLineEdit(tab_4);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 20, 341, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("/* Styles de base pour QLineEdit */\n"
"QLineEdit {\n"
"    background-color: #eee; /* Gris clair */\n"
"    color: #000000; /* Noir */\n"
"    font-size: 16px;\n"
"    font-weight: normal; /* Le style normal est plus appropri\303\251 pour un QLineEdit */\n"
"    border: 2px solid #FF0000; /* Rouge */\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"/* Animation de survol */\n"
"QLineEdit:hover {\n"
"    background-color: #eee /* Gris un peu plus fonc\303\251 au survol */\n"
"}\n"
""));
        pb_supprimer = new QPushButton(tab_4);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(610, 180, 101, 41));
        pb_supprimer->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}\n"
""));
        QIcon icon8;
        icon8.addFile(QStringLiteral("../6861362.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_supprimer->setIcon(icon8);
        pushButton13 = new QPushButton(tab_4);
        pushButton13->setObjectName(QStringLiteral("pushButton13"));
        pushButton13->setGeometry(QRect(720, 460, 101, 61));
        pushButton13->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: none;\n"
"    font: 8pt \"Sitka Display Semibold\";\n"
"    text-align: middle;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: rgb(255, 255, 255);\n"
" \n"
"\n"
"    border: none;\n"
"    text-align: middle;\n"
"}\n"
""));
        QIcon icon9;
        icon9.addFile(QStringLiteral("../337946.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton13->setIcon(icon9);
        pushButton13->setIconSize(QSize(44, 45));
        comboBox = new QComboBox(tab_4);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(410, 30, 141, 31));
        comboBox->setStyleSheet(QString::fromUtf8("/* Styles de la ComboBox avec des couleurs diff\303\251rentes */\n"
"QComboBox {\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border: 1px solid #808080; /* Bordure pour d\303\251finir les limites du QComboBox (gris) */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    background-color: white; /* Couleur de fond du QComboBox */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #606060; /* Bordure au survol du QComboBox (gris plus fonc\303\251) */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: right center;\n"
"    width: 15px; /* Largeur de la fl\303\250che de d\303\251filement */\n"
"    border-left: 1px solid #808080; /* Bordure \303\240 gauche de la fl\303\250che */\n"
"    background-color: #DCE0EE; /* Couleur de fond de la fl\303\250che"
                        " */\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(arrow_down.png); /* Remplacez avec le chemin de votre propre image de fl\303\250che vers le bas */\n"
"}\n"
"\n"
"QComboBox::down-arrow:disabled {\n"
"    image: url(arrow_down_disabled.png); /* Image de fl\303\250che d\303\251sactiv\303\251e (remplacez le chemin) */\n"
"}\n"
"\n"
"QComboBox::down-arrow:hover {\n"
"    background-color: #C5D9EA; /* Couleur de fond de la fl\303\250che au survol */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    border: 1px solid #808080; /* Bordure du menu d\303\251roulant */\n"
"    selection-background-color: #DCE0EE; /* Couleur de fond de l'\303\251l\303\251ment s\303\251lectionn\303\251 */\n"
"    selection-color: #333; /* Couleur du texte de l'\303\251l\303\251ment s\303\251lectionn\303\251 */\n"
"}\n"
""));
        pushButton_3 = new QPushButton(tab_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(610, 220, 101, 41));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}\n"
""));
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label_7 = new QLabel(tab_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 60, 151, 31));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        le_idmodif = new QLineEdit(tab_5);
        le_idmodif->setObjectName(QStringLiteral("le_idmodif"));
        le_idmodif->setGeometry(QRect(130, 60, 141, 31));
        le_idmodif->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
"QLabel#bordureRouge {\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"}\n"
""));
        pb_modifier = new QPushButton(tab_5);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(320, 160, 101, 41));
        pb_modifier->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}\n"
""));
        QIcon icon10;
        icon10.addFile(QStringLiteral("../6325975.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_modifier->setIcon(icon10);
        pb_modifier->setIconSize(QSize(25, 25));
        label_8 = new QLabel(tab_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 110, 121, 31));
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        label_9 = new QLabel(tab_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 160, 141, 31));
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        le_modifaddmail = new QLineEdit(tab_5);
        le_modifaddmail->setObjectName(QStringLiteral("le_modifaddmail"));
        le_modifaddmail->setGeometry(QRect(110, 110, 161, 31));
        le_modifaddmail->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
"QLabel#bordureRouge {\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"}\n"
""));
        le_modifadd = new QLineEdit(tab_5);
        le_modifadd->setObjectName(QStringLiteral("le_modifadd"));
        le_modifadd->setGeometry(QRect(110, 210, 161, 31));
        le_modifadd->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
"QLabel#bordureRouge {\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"}\n"
""));
        label_12 = new QLabel(tab_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(470, 20, 141, 101));
        label_12->setPixmap(QPixmap(QString::fromUtf8("../Pictures/logo.png")));
        label_12->setScaledContents(true);
        achat_2 = new QLineEdit(tab_5);
        achat_2->setObjectName(QStringLiteral("achat_2"));
        achat_2->setGeometry(QRect(120, 160, 151, 31));
        achat_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
"QLabel#bordureRouge {\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"}\n"
""));
        label_14 = new QLabel(tab_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 210, 101, 31));
        label_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        tabWidget_2->addTab(tab_5, QString());
        label_14->raise();
        label_7->raise();
        le_idmodif->raise();
        pb_modifier->raise();
        label_8->raise();
        label_9->raise();
        le_modifaddmail->raise();
        le_modifadd->raise();
        label_12->raise();
        achat_2->raise();
        tabWidget->addTab(tab, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tabWidget_3 = new QTabWidget(tab_6);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(0, -10, 1171, 701));
        tabWidget_3->setStyleSheet(QStringLiteral(""));
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        groupBox_3 = new QGroupBox(tab_7);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(30, 0, 1081, 651));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid red; /* Changer la couleur de la bordure \303\240 rouge */\n"
"    border-radius: 5px;\n"
"    margin-top: 10px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 3px;\n"
"    background-color: red; /* Changer la couleur de fond \303\240 rouge */\n"
"    \n"
"    /* Styles de police pour le titre */\n"
"    font-family: Arial, sans-serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: black; /* Laisser la couleur du texte en noir */\n"
"}"));
        reference_produit = new QLabel(groupBox_3);
        reference_produit->setObjectName(QStringLiteral("reference_produit"));
        reference_produit->setGeometry(QRect(30, 130, 161, 31));
        reference_produit->setStyleSheet(QString::fromUtf8("\n"
"QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        prix = new QLabel(groupBox_3);
        prix->setObjectName(QStringLiteral("prix"));
        prix->setGeometry(QRect(30, 180, 91, 31));
        prix->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        date_produit = new QLabel(groupBox_3);
        date_produit->setObjectName(QStringLiteral("date_produit"));
        date_produit->setGeometry(QRect(30, 230, 151, 31));
        date_produit->setStyleSheet(QString::fromUtf8("\n"
"QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        quantite = new QLabel(groupBox_3);
        quantite->setObjectName(QStringLiteral("quantite"));
        quantite->setGeometry(QRect(30, 280, 141, 31));
        quantite->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        nom = new QLabel(groupBox_3);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(30, 320, 71, 31));
        nom->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        le_reference_produit = new QLineEdit(groupBox_3);
        le_reference_produit->setObjectName(QStringLiteral("le_reference_produit"));
        le_reference_produit->setGeometry(QRect(170, 130, 131, 31));
        le_reference_produit->setAutoFillBackground(false);
        le_reference_produit->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}\n"
""));
        le_prix = new QLineEdit(groupBox_3);
        le_prix->setObjectName(QStringLiteral("le_prix"));
        le_prix->setGeometry(QRect(120, 180, 151, 31));
        le_prix->setAutoFillBackground(false);
        le_prix->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}\n"
"\n"
""));
        le_date_produit = new QLineEdit(groupBox_3);
        le_date_produit->setObjectName(QStringLiteral("le_date_produit"));
        le_date_produit->setGeometry(QRect(130, 230, 141, 31));
        le_date_produit->setAutoFillBackground(false);
        le_date_produit->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}\n"
""));
        le_nom = new QLineEdit(groupBox_3);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(80, 320, 171, 31));
        le_nom->setAutoFillBackground(false);
        le_nom->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}\n"
""));
        pb_Ajouter = new QPushButton(groupBox_3);
        pb_Ajouter->setObjectName(QStringLiteral("pb_Ajouter"));
        pb_Ajouter->setGeometry(QRect(30, 430, 111, 41));
        pb_Ajouter->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}"));
        QIcon icon11;
        icon11.addFile(QStringLiteral("../../Downloads/1091585.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_Ajouter->setIcon(icon11);
        pb_Ajouter->setIconSize(QSize(20, 20));
        pb_supprimer_3 = new QPushButton(groupBox_3);
        pb_supprimer_3->setObjectName(QStringLiteral("pb_supprimer_3"));
        pb_supprimer_3->setGeometry(QRect(100, 470, 61, 51));
        pb_supprimer_3->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}"));
        QIcon icon12;
        icon12.addFile(QStringLiteral("../../Downloads/6861362.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_supprimer_3->setIcon(icon12);
        pb_supprimer_3->setIconSize(QSize(20, 20));
        modifier = new QPushButton(groupBox_3);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(140, 430, 101, 41));
        modifier->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}"));
        QIcon icon13;
        icon13.addFile(QStringLiteral("../../Downloads/6325975.png"), QSize(), QIcon::Normal, QIcon::Off);
        modifier->setIcon(icon13);
        modifier->setIconSize(QSize(20, 20));
        label_1 = new QLabel(groupBox_3);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(0, 20, 161, 101));
        label_1->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/Sans_titre-2-removebg-preview.png")));
        label_1->setScaledContents(true);
        tab_produits = new QTableView(groupBox_3);
        tab_produits->setObjectName(QStringLiteral("tab_produits"));
        tab_produits->setGeometry(QRect(330, 80, 731, 411));
        tab_produits->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    border:none;\n"
"    font: 75 28pt \"Arial\";\n"
"}\n"
"\n"
"QTableView {\n"
"    background-color: #f5f5f5;\n"
"    alternate-background-color: #e0e0e0;\n"
"    selection-background-color: #a8d8ea;\n"
"    selection-color: #333;\n"
"    gridline-color: #ccc;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #FF0000; /* Rouge */\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #ddd;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #a8d8ea;\n"
"}\n"
"\n"
"QTableView::item:hover {\n"
"    background-color: #d4e9f8;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 1px solid #ddd;\n"
"    background: #FF0000; /* Rouge */\n"
"    width: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #FF0000; /* Rouge */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    border: 1px solid #ddd;\n"
"    height: 10px;\n"
"    subcontr"
                        "ol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    border: 1px solid #ddd;\n"
"    background: #FF0000; /* Rouge */\n"
"    height: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #FF0000; /* Rouge */\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal,\n"
"QScrollBar::sub-line:horizontal {\n"
"    border: 1px solid #ddd;\n"
"    width: 10px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
""));
        nom_2 = new QLabel(groupBox_3);
        nom_2->setObjectName(QStringLiteral("nom_2"));
        nom_2->setGeometry(QRect(30, 370, 81, 31));
        nom_2->setStyleSheet(QString::fromUtf8("\n"
"QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        le_email = new QLineEdit(groupBox_3);
        le_email->setObjectName(QStringLiteral("le_email"));
        le_email->setGeometry(QRect(100, 370, 151, 31));
        le_email->setAutoFillBackground(false);
        le_email->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}\n"
""));
        le_quantite = new QLineEdit(groupBox_3);
        le_quantite->setObjectName(QStringLiteral("le_quantite"));
        le_quantite->setGeometry(QRect(110, 280, 131, 31));
        le_quantite->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}\n"
"\n"
""));
        le_pdf = new QPushButton(groupBox_3);
        le_pdf->setObjectName(QStringLiteral("le_pdf"));
        le_pdf->setGeometry(QRect(880, 20, 61, 51));
        le_pdf->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: none;\n"
"    font: 8pt \"Sitka Display Semibold\";\n"
"    text-align: middle;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: rgb(255, 255, 255);\n"
"\n"
"    border: none;\n"
"    text-align: middle;\n"
"}\n"
""));
        QIcon icon14;
        icon14.addFile(QStringLiteral("../../Downloads/337946.png"), QSize(), QIcon::Normal, QIcon::Off);
        le_pdf->setIcon(icon14);
        le_pdf->setIconSize(QSize(50, 50));
        le_tri_2 = new QPushButton(groupBox_3);
        le_tri_2->setObjectName(QStringLiteral("le_tri_2"));
        le_tri_2->setGeometry(QRect(540, 500, 121, 61));
        le_tri_2->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}\n"
""));
        QIcon icon15;
        icon15.addFile(QStringLiteral("../../Downloads/tri.png"), QSize(), QIcon::Normal, QIcon::Off);
        le_tri_2->setIcon(icon15);
        le_tri_2->setIconSize(QSize(40, 40));
        le_tri = new QPushButton(groupBox_3);
        le_tri->setObjectName(QStringLiteral("le_tri"));
        le_tri->setGeometry(QRect(660, 500, 181, 61));
        le_tri->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}"));
        le_tri->setIcon(icon15);
        le_tri->setIconSize(QSize(40, 40));
        stat_butt = new QPushButton(groupBox_3);
        stat_butt->setObjectName(QStringLiteral("stat_butt"));
        stat_butt->setGeometry(QRect(580, 20, 61, 51));
        stat_butt->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: none;\n"
"    font: 8pt \"Sitka Display Semibold\";\n"
"    text-align: middle;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: rgb(255, 255, 255);\n"
"\n"
"    border: none;\n"
"    text-align: middle;\n"
"}\n"
""));
        stat_butt->setIcon(icon4);
        stat_butt->setIconSize(QSize(50, 50));
        BtnEnregistrer = new QPushButton(groupBox_3);
        BtnEnregistrer->setObjectName(QStringLiteral("BtnEnregistrer"));
        BtnEnregistrer->setGeometry(QRect(950, 40, 61, 31));
        BtnEnregistrer->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: none;\n"
"    font: 8pt \"Sitka Display Semibold\";\n"
"    text-align: middle;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: rgb(255, 255, 255);\n"
" \n"
"\n"
"    border: none;\n"
"    text-align: middle;\n"
"}\n"
""));
        QIcon icon16;
        icon16.addFile(QStringLiteral("../../Downloads/2810399.png"), QSize(), QIcon::Normal, QIcon::Off);
        BtnEnregistrer->setIcon(icon16);
        BtnEnregistrer->setIconSize(QSize(35, 35));
        le_recherche = new QLineEdit(groupBox_3);
        le_recherche->setObjectName(QStringLiteral("le_recherche"));
        le_recherche->setGeometry(QRect(260, 30, 271, 31));
        le_recherche->setStyleSheet(QString::fromUtf8("/* Styles de base pour QLineEdit */\n"
"QLineEdit {\n"
"    background-color: #eee; /* Gris clair */\n"
"    color: #000000; /* Noir */\n"
"    font-size: 16px;\n"
"    font-weight: normal; /* Le style normal est plus appropri\303\251 pour un QLineEdit */\n"
"    border: 2px solid #FF0000; /* Rouge */\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"/* Animation de survol */\n"
"QLineEdit:hover {\n"
"    background-color: #eee /* Gris un peu plus fonc\303\251 au survol */\n"
"}\n"
""));
        le_recherche->setMaxLength(32775);
        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(540, 40, 31, 20));
        label_20->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/editfind_104370.png")));
        label_20->setScaledContents(true);
        tabWidget_3->addTab(tab_7, QString());
        tabWidget->addTab(tab_6, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        tabWidget_4 = new QTabWidget(tab_8);
        tabWidget_4->setObjectName(QStringLiteral("tabWidget_4"));
        tabWidget_4->setGeometry(QRect(0, 0, 1091, 871));
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        groupBox_4 = new QGroupBox(tab_9);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 0, 1051, 691));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid red; /* Changer la couleur de la bordure \303\240 rouge */\n"
"    border-radius: 5px;\n"
"    margin-top: 10px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 3px;\n"
"    background-color: red; /* Changer la couleur de fond \303\240 rouge */\n"
"    \n"
"    /* Styles de police pour le titre */\n"
"    font-family: Arial, sans-serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: black; /* Laisser la couleur du texte en noir */\n"
"}"));
        label_21 = new QLabel(groupBox_4);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(10, 50, 131, 31));
        label_21->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        label_22 = new QLabel(groupBox_4);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(10, 90, 121, 31));
        label_22->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        label_23 = new QLabel(groupBox_4);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 130, 161, 31));
        label_23->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        label_24 = new QLabel(groupBox_4);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(10, 170, 161, 31));
        label_24->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
""));
        lineid = new QLineEdit(groupBox_4);
        lineid->setObjectName(QStringLiteral("lineid"));
        lineid->setGeometry(QRect(80, 50, 141, 31));
        lineid->setAutoFillBackground(false);
        lineid->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
"QLabel#bordureRouge {\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"}\n"
"\n"
""));
        linedate = new QLineEdit(groupBox_4);
        linedate->setObjectName(QStringLiteral("linedate"));
        linedate->setGeometry(QRect(120, 130, 141, 31));
        linedate->setAutoFillBackground(false);
        linedate->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
"QLabel#bordureRouge {\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"}\n"
"\n"
""));
        linekilo = new QLineEdit(groupBox_4);
        linekilo->setObjectName(QStringLiteral("linekilo"));
        linekilo->setGeometry(QRect(120, 170, 121, 31));
        linekilo->setAutoFillBackground(false);
        linekilo->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
"\n"
"QLabel#bordureRouge {\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"}\n"
"\n"
""));
        linetype = new QComboBox(groupBox_4);
        linetype->setObjectName(QStringLiteral("linetype"));
        linetype->setGeometry(QRect(100, 90, 121, 31));
        linetype->setStyleSheet(QString::fromUtf8("/* Styles de la ComboBox avec des couleurs diff\303\251rentes */\n"
"QComboBox {\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border: 1px solid #808080; /* Bordure pour d\303\251finir les limites du QComboBox (gris) */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"    background-color: white; /* Couleur de fond du QComboBox */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #606060; /* Bordure au survol du QComboBox (gris plus fonc\303\251) */\n"
"}"));
        image = new QPushButton(groupBox_4);
        image->setObjectName(QStringLiteral("image"));
        image->setGeometry(QRect(120, 250, 111, 41));
        image->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}"));
        QIcon icon17;
        icon17.addFile(QStringLiteral("../../Downloads/405438657_2064753557217198_1636686424829253042_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        image->setIcon(icon17);
        image->setIconSize(QSize(30, 30));
        pboff = new QPushButton(groupBox_4);
        pboff->setObjectName(QStringLiteral("pboff"));
        pboff->setGeometry(QRect(50, 490, 111, 41));
        pboff->setStyleSheet(QString::fromUtf8("/* Style simplifi\303\251 du QPushButton */\n"
"QPushButton {\n"
"    background: #eee; /* Gris clair */\n"
"    color: #333; /* Noir */\n"
"    border: 2px solid #f00; /* Rouge */\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    transition: background 0.3s ease; /* Transition en douceur de la couleur de fond */\n"
"}\n"
"\n"
"/* Animation de survol */\n"
"QPushButton:hover {\n"
"    background: #ddd; /* Gris plus fonc\303\251 au survol */\n"
"}\n"
""));
        pbon = new QPushButton(groupBox_4);
        pbon->setObjectName(QStringLiteral("pbon"));
        pbon->setGeometry(QRect(50, 440, 111, 41));
        pbon->setStyleSheet(QString::fromUtf8("/* Style simplifi\303\251 du QPushButton */\n"
"QPushButton {\n"
"    background: #eee; /* Gris clair */\n"
"    color: #333; /* Noir */\n"
"    border: 2px solid #f00; /* Rouge */\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    transition: background 0.3s ease; /* Transition en douceur de la couleur de fond */\n"
"}\n"
"\n"
"/* Animation de survol */\n"
"QPushButton:hover {\n"
"    background: #ddd; /* Gris plus fonc\303\251 au survol */\n"
"}\n"
""));
        tableView = new QTableView(groupBox_4);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(280, 90, 551, 361));
        tableView->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    border:none;\n"
"    font: 75 28pt \"Arial\";\n"
"}\n"
"\n"
"QTableView {\n"
"    background-color: #f5f5f5;\n"
"    alternate-background-color: #e0e0e0;\n"
"    selection-background-color: #a8d8ea;\n"
"    selection-color: #333;\n"
"    gridline-color: #ccc;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #FF0000; /* Rouge */\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #ddd;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #a8d8ea;\n"
"}\n"
"\n"
"QTableView::item:hover {\n"
"    background-color: #d4e9f8;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 1px solid #ddd;\n"
"    background: #FF0000; /* Rouge */\n"
"    width: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #FF0000; /* Rouge */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    border: 1px solid #ddd;\n"
"    height: 10px;\n"
"    subcontr"
                        "ol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    border: 1px solid #ddd;\n"
"    background: #FF0000; /* Rouge */\n"
"    height: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #FF0000; /* Rouge */\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal,\n"
"QScrollBar::sub-line:horizontal {\n"
"    border: 1px solid #ddd;\n"
"    width: 10px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
""));
        recherche_2 = new QPushButton(groupBox_4);
        recherche_2->setObjectName(QStringLiteral("recherche_2"));
        recherche_2->setGeometry(QRect(750, 40, 41, 31));
        recherche_2->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: none;\n"
"    font: 8pt \"Sitka Display Semibold\";\n"
"    text-align: middle;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: rgb(255, 255, 255);\n"
" \n"
"\n"
"    border: none;\n"
"    text-align: middle;\n"
"}\n"
""));
        QIcon icon18;
        icon18.addFile(QStringLiteral("../../Downloads/editfind_104370.png"), QSize(), QIcon::Normal, QIcon::Off);
        recherche_2->setIcon(icon18);
        recherche_2->setIconSize(QSize(30, 30));
        recherche = new QLineEdit(groupBox_4);
        recherche->setObjectName(QStringLiteral("recherche"));
        recherche->setGeometry(QRect(350, 40, 391, 31));
        recherche->setStyleSheet(QString::fromUtf8("/* Styles de base pour QLineEdit */\n"
"QLineEdit {\n"
"    background-color: #eee; /* Gris clair */\n"
"    color: #000000; /* Noir */\n"
"    font-size: 16px;\n"
"    font-weight: normal; /* Le style normal est plus appropri\303\251 pour un QLineEdit */\n"
"    border: 2px solid #FF0000; /* Rouge */\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"/* Animation de survol */\n"
"QLineEdit:hover {\n"
"    background-color: #eee /* Gris un peu plus fonc\303\251 au survol */\n"
"}\n"
""));
        pushButton_2 = new QPushButton(groupBox_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 450, 101, 41));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}\n"
""));
        QIcon icon19;
        icon19.addFile(QStringLiteral("../../Downloads/1286853.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon19);
        pushButton_2->setIconSize(QSize(20, 20));
        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 450, 101, 41));
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}\n"
""));
        QIcon icon20;
        icon20.addFile(QStringLiteral("../../Downloads/3394726.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon20);
        pushButton->setIconSize(QSize(20, 20));
        bu = new QPushButton(groupBox_4);
        bu->setObjectName(QStringLiteral("bu"));
        bu->setGeometry(QRect(170, 470, 91, 31));
        bu->setStyleSheet(QLatin1String("#pushButton_6{\n"
"color:white;\n"
"background-color:#6568F3;\n"
"border-radius:19px;\n"
"}\n"
"#pushButton_6:hover{\n"
"color:white;\n"
"background-color:#FF7244;\n"
"border-radius:19px;\n"
"}"));
        bu->setCheckable(true);
        bu->setChecked(true);
        triId_8 = new QPushButton(groupBox_4);
        triId_8->setObjectName(QStringLiteral("triId_8"));
        triId_8->setGeometry(QRect(830, 260, 101, 41));
        triId_8->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}"));
        QIcon icon21;
        icon21.addFile(QStringLiteral("../../Downloads/404295983_191859510588151_8301914838282796655_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        triId_8->setIcon(icon21);
        triId_8->setIconSize(QSize(30, 30));
        pushButton_6 = new QPushButton(groupBox_4);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(1330, 470, 91, 61));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: none;\n"
"    font: 8pt \"Sitka Display Semibold\";\n"
"    text-align: middle;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: rgb(255, 255, 255);\n"
" \n"
"\n"
"    border: none;\n"
"    text-align: middle;\n"
"}\n"
""));
        QIcon icon22;
        icon22.addFile(QStringLiteral("../../Downloads/352885013_1349384105640096_903490800808895943_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon22);
        pushButton_6->setIconSize(QSize(50, 50));
        pushButton_ajout = new QPushButton(groupBox_4);
        pushButton_ajout->setObjectName(QStringLiteral("pushButton_ajout"));
        pushButton_ajout->setGeometry(QRect(10, 250, 111, 41));
        pushButton_ajout->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}"));
        QIcon icon23;
        icon23.addFile(QStringLiteral("../../Downloads/405372321_1037480560873898_4815069443858606315_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ajout->setIcon(icon23);
        pushButton_ajout->setIconSize(QSize(25, 25));
        pushButton_modifier = new QPushButton(groupBox_4);
        pushButton_modifier->setObjectName(QStringLiteral("pushButton_modifier"));
        pushButton_modifier->setGeometry(QRect(60, 290, 111, 41));
        pushButton_modifier->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}"));
        QIcon icon24;
        icon24.addFile(QStringLiteral("../../Downloads/404467417_349568170990140_3321058413461044392_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_modifier->setIcon(icon24);
        pushButton_modifier->setIconSize(QSize(25, 25));
        label_25 = new QLabel(groupBox_4);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(1180, 20, 241, 131));
        label_25->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/385529522_792587036009758_9013698152391309674_n.png")));
        label_25->setScaledContents(true);
        label_26 = new QLabel(groupBox_4);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(560, 470, 281, 161));
        label_26->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/370290046_1289397509120198_7699179722019319833_n.png")));
        label_26->setScaledContents(true);
        tabWidget_4->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        groupBox_5 = new QGroupBox(tab_10);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(120, 10, 821, 471));
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid red; /* Changer la couleur de la bordure \303\240 rouge */\n"
"    border-radius: 5px;\n"
"    margin-top: 10px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 3px;\n"
"    background-color: red; /* Changer la couleur de fond \303\240 rouge */\n"
"    \n"
"    /* Styles de police pour le titre */\n"
"    font-family: Arial, sans-serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: black; /* Laisser la couleur du texte en noir */\n"
"}"));
        label_27 = new QLabel(groupBox_5);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(30, 100, 281, 31));
        label_27->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    border: 1px solid #FF0000; /* Bordure pour d\303\251finir les limites du QLabel (rouge) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
""));
        pushButton_supprimer = new QPushButton(groupBox_5);
        pushButton_supprimer->setObjectName(QStringLiteral("pushButton_supprimer"));
        pushButton_supprimer->setGeometry(QRect(410, 150, 51, 51));
        pushButton_supprimer->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}"));
        pushButton_supprimer->setIcon(icon12);
        pushButton_supprimer->setIconSize(QSize(30, 30));
        linesupp = new QLineEdit(groupBox_5);
        linesupp->setObjectName(QStringLiteral("linesupp"));
        linesupp->setGeometry(QRect(290, 100, 181, 31));
        linesupp->setStyleSheet(QLatin1String("QLabel {\n"
"    background-color: transparent; /* Rendre le fond transparent */\n"
"    color: #333; /* Couleur du texte pour contraster (noir) */\n"
"    padding: 5px; /* Espacement interne pour le texte */\n"
"    border-radius: 3px; /* Coins arrondis */\n"
"\n"
"    /* Styles de police */\n"
"    font-family: Arial, sans-serif; /* Famille de police */\n"
"    font-size: 14px; /* Taille de police */\n"
"    font-weight: bold; /* Poids de la police (gras) */\n"
"}\n"
""));
        tabWidget_4->addTab(tab_10, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        ajouter_p_4 = new QGroupBox(tab_11);
        ajouter_p_4->setObjectName(QStringLiteral("ajouter_p_4"));
        ajouter_p_4->setGeometry(QRect(120, 10, 821, 531));
        QFont font;
        font.setFamily(QStringLiteral("Montserrat ExtraBold"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        ajouter_p_4->setFont(font);
        ajouter_p_4->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid red; /* Changer la couleur de la bordure \303\240 rouge */\n"
"    border-radius: 5px;\n"
"    margin-top: 10px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 3px;\n"
"    background-color: red; /* Changer la couleur de fond \303\240 rouge */\n"
"    \n"
"    /* Styles de police pour le titre */\n"
"    font-family: Arial, sans-serif;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: black; /* Laisser la couleur du texte en noir */\n"
"}"));
        pushButton_4 = new QPushButton(ajouter_p_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(260, 400, 141, 41));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: white; /* Changer la couleur du fond en blanc */\n"
"    color: black; /* Changer la couleur du texte en noir */\n"
"    border: 1px solid red; /* Changer la couleur de la bordure en rouge */\n"
"    padding: 5px 10px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #DCE0EE;\n"
"}"));
        QIcon icon25;
        icon25.addFile(QStringLiteral("../../Downloads/statistics.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon25);
        pushButton_4->setIconSize(QSize(35, 35));
        statE = new QFrame(ajouter_p_4);
        statE->setObjectName(QStringLiteral("statE"));
        statE->setGeometry(QRect(70, 50, 641, 321));
        statE->setFrameShape(QFrame::StyledPanel);
        statE->setFrameShadow(QFrame::Raised);
        tabWidget_4->addTab(tab_11, QString());
        tabWidget->addTab(tab_8, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1650, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);
        tabWidget_2->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(0);
        tabWidget_4->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "COMMANDE", Q_NULLPTR));
        Status_Produit->setText(QApplication::translate("MainWindow", "Status_Produit", Q_NULLPTR));
        ID->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        Date_Produit->setText(QApplication::translate("MainWindow", "Date_Produit", Q_NULLPTR));
        LE_S->clear();
        LE_S->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Bon etat", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Mauvais etat", Q_NULLPTR)
        );
        BTNAJOUTER->setText(QApplication::translate("MainWindow", "ajouter", Q_NULLPTR));
        BTNMODIFIER->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        BTNSUPPRIMER->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Bon etat", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Mauvais etat", Q_NULLPTR));
        tri_id_a->setText(QApplication::translate("MainWindow", "tri ID", Q_NULLPTR));
        tri_date_a->setText(QApplication::translate("MainWindow", "tri date", Q_NULLPTR));
        stat->setText(QString());
        Date_Produit_2->setText(QApplication::translate("MainWindow", "Quantite Commande", Q_NULLPTR));
        PDF_bb->setText(QString());
        enrg_bb->setText(QString());
        label_18->setText(QString());
        label_19->setText(QApplication::translate("MainWindow", "HISTORIQUE", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "COMMANDE", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "ajout", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "CIN", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "ADDMAIL", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "ADRESSLIVR", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_10->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "nb d'achat", Q_NULLPTR));
        label_15->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        chartview->setText(QString());
        pushButton_21->setText(QApplication::translate("MainWindow", "Disconecter", Q_NULLPTR));
        label_6->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Ajouter un client", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        pushButton13->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Par defaut", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Cin", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Adresse", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Email", Q_NULLPTR)
        );
        pushButton_3->setText(QApplication::translate("MainWindow", "Client fid", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "afficher un client", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "carte identit\303\251", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "addmail", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "adresslivr", Q_NULLPTR));
        label_12->setText(QString());
        label_14->setText(QApplication::translate("MainWindow", "nb d'achat", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "modifier un client", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "CLIENTS", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Ajout", Q_NULLPTR));
        reference_produit->setText(QApplication::translate("MainWindow", "referenc_ produit ", Q_NULLPTR));
        prix->setText(QApplication::translate("MainWindow", "prix", Q_NULLPTR));
        date_produit->setText(QApplication::translate("MainWindow", "Date_produit", Q_NULLPTR));
        quantite->setText(QApplication::translate("MainWindow", "Quantite", Q_NULLPTR));
        nom->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        le_reference_produit->setText(QString());
        le_prix->setText(QString());
        le_date_produit->setText(QString());
        le_nom->setText(QString());
        pb_Ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pb_supprimer_3->setText(QString());
        modifier->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        label_1->setText(QString());
        nom_2->setText(QApplication::translate("MainWindow", "Email", Q_NULLPTR));
        le_email->setText(QString());
        le_quantite->setText(QString());
        le_pdf->setText(QString());
        le_tri_2->setText(QApplication::translate("MainWindow", " PRIX", Q_NULLPTR));
        le_tri->setText(QApplication::translate("MainWindow", "reference_produit", Q_NULLPTR));
        stat_butt->setText(QString());
        BtnEnregistrer->setText(QString());
        label_20->setText(QString());
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_7), QApplication::translate("MainWindow", "Ajouter un  produit", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "PRODUIT", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "ajout de vehicule", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "id_veh", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "type_veh", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "date_entretien", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "kilometrage", Q_NULLPTR));
        lineid->setText(QString());
        linedate->setText(QString());
        linekilo->setText(QString());
        linetype->clear();
        linetype->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Audi", Q_NULLPTR)
         << QApplication::translate("MainWindow", "BMW", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Mercedes", Q_NULLPTR)
        );
        image->setText(QApplication::translate("MainWindow", "image", Q_NULLPTR));
        pboff->setText(QApplication::translate("MainWindow", "fermer bariere", Q_NULLPTR));
        pbon->setText(QApplication::translate("MainWindow", "ouvrire barier", Q_NULLPTR));
        recherche_2->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow", "sortir", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "entrer", Q_NULLPTR));
        bu->setText(QString());
        triId_8->setText(QApplication::translate("MainWindow", "Trier", Q_NULLPTR));
        pushButton_6->setText(QString());
        pushButton_ajout->setText(QApplication::translate("MainWindow", "valider", Q_NULLPTR));
        pushButton_modifier->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        label_25->setText(QString());
        label_26->setText(QString());
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_9), QApplication::translate("MainWindow", "creer", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "SUPPRIMER", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "donner l'ID du vehicule a supprimer:", Q_NULLPTR));
        pushButton_supprimer->setText(QString());
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_10), QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        ajouter_p_4->setTitle(QApplication::translate("MainWindow", "STATISTIQUE", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "statistique", Q_NULLPTR));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_11), QApplication::translate("MainWindow", "statistique", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
