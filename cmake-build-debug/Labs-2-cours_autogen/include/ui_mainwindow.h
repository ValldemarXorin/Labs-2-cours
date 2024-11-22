/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *PageSwitcher;
    QWidget *AutoselectionMoviePage;
    QListWidget *MenuListAutoselectionMoviePage;
    QPushButton *MenuButtonAutoselectionMoviePage;
    QWidget *SearchPage;
    QLineEdit *SearchFieldSearchPage;
    QListWidget *MenuListSearchPage;
    QPushButton *MenuButtonSearchPage;
    QListWidget *MoviesListSearchPage;

    void setupUi(QMainWindow *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName("mainwindow");
        mainwindow->resize(615, 445);
        mainwindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"                background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, \n"
"                                    stop: 0 #1E1E1E, /* \320\235\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 (\321\202\320\265\320\274\320\275\321\213\320\271) */\n"
"                                    stop: 1 #001f3f); /* \320\232\320\276\320\275\320\265\321\207\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 (\321\202\320\265\320\274\320\275\320\276-\321\201\320\270\320\275\320\270\320\271) */\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216 */\n"
"    }"));
        centralwidget = new QWidget(mainwindow);
        centralwidget->setObjectName("centralwidget");
        PageSwitcher = new QStackedWidget(centralwidget);
        PageSwitcher->setObjectName("PageSwitcher");
        PageSwitcher->setGeometry(QRect(0, 0, 621, 451));
        AutoselectionMoviePage = new QWidget();
        AutoselectionMoviePage->setObjectName("AutoselectionMoviePage");
        MenuListAutoselectionMoviePage = new QListWidget(AutoselectionMoviePage);
        new QListWidgetItem(MenuListAutoselectionMoviePage);
        new QListWidgetItem(MenuListAutoselectionMoviePage);
        new QListWidgetItem(MenuListAutoselectionMoviePage);
        new QListWidgetItem(MenuListAutoselectionMoviePage);
        new QListWidgetItem(MenuListAutoselectionMoviePage);
        MenuListAutoselectionMoviePage->setObjectName("MenuListAutoselectionMoviePage");
        MenuListAutoselectionMoviePage->setGeometry(QRect(-10, 0, 141, 441));
        MenuListAutoselectionMoviePage->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"    border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"}\n"
"\n"
"QScrollBar:vertical, QScrollBar:horizontal {\n"
"    width: 0px; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \321\210\320\270\321\200\320\270\320\275\321\203 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \321\201\320\272\321\200\320\276\320\273\320\273\320\260 */\n"
"    background: transparent; /* \320\224\320\265\320\273\320\260\320\265\320\274 \321"
                        "\204\320\276\320\275 \320\277\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\274 */\n"
"}\n"
"\n"
"QListWidget::item {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"    padding: 10px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\264\320\273\321\217 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 \320\264\320\273\321\217 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 */\n"
"	outline: none;\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"    background-color: #0078d7; /* \320\246\320"
                        "\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\264\320\273\321\217 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 */\n"
"	outline: none;\n"
"}\n"
"\n"
"QListWidget::item:hover {\n"
"    background-color: #1E1E1E; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"    color: #FFFFFF;\n"
"}"));
        MenuButtonAutoselectionMoviePage = new QPushButton(AutoselectionMoviePage);
        MenuButtonAutoselectionMoviePage->setObjectName("MenuButtonAutoselectionMoviePage");
        MenuButtonAutoselectionMoviePage->setGeometry(QRect(20, 20, 75, 31));
        MenuButtonAutoselectionMoviePage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"        color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"        border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"        border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"        padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"		background-color: #1E1E1E\n"
"}\n"
""));
        PageSwitcher->addWidget(AutoselectionMoviePage);
        MenuButtonAutoselectionMoviePage->raise();
        MenuListAutoselectionMoviePage->raise();
        SearchPage = new QWidget();
        SearchPage->setObjectName("SearchPage");
        SearchFieldSearchPage = new QLineEdit(SearchPage);
        SearchFieldSearchPage->setObjectName("SearchFieldSearchPage");
        SearchFieldSearchPage->setGeometry(QRect(330, 20, 271, 31));
        SearchFieldSearchPage->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"        background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"        color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"        border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"        border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"        padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"    }\n"
"\n"
"QLineEdit:hover {\n"
"		background-color: #1E1E1E\n"
"}\n"
"\n"
"    QLineEdit:focus {\n"
"        border: 2px solid #0056a1; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 \320\277\321\200\320\270 \321\204\320\276\320\272\321\203\321\201\320\265 */\n"
"        background-color: #3E3E3E; /* \320\246\320\262\320\265\321"
                        "\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \321\204\320\276\320\272\321\203\321\201\320\265 */\n"
"    }"));
        MenuListSearchPage = new QListWidget(SearchPage);
        new QListWidgetItem(MenuListSearchPage);
        new QListWidgetItem(MenuListSearchPage);
        new QListWidgetItem(MenuListSearchPage);
        new QListWidgetItem(MenuListSearchPage);
        new QListWidgetItem(MenuListSearchPage);
        MenuListSearchPage->setObjectName("MenuListSearchPage");
        MenuListSearchPage->setGeometry(QRect(-10, 0, 141, 441));
        MenuListSearchPage->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"    border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"}\n"
"\n"
"QScrollBar:vertical, QScrollBar:horizontal {\n"
"    width: 0px; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \321\210\320\270\321\200\320\270\320\275\321\203 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \321\201\320\272\321\200\320\276\320\273\320\273\320\260 */\n"
"    background: transparent; /* \320\224\320\265\320\273\320\260\320\265\320\274 \321"
                        "\204\320\276\320\275 \320\277\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\274 */\n"
"}\n"
"\n"
"QListWidget::item {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"    padding: 10px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\264\320\273\321\217 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 \320\264\320\273\321\217 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 */\n"
"	outline: none;\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"    background-color: #0078d7; /* \320\246\320"
                        "\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\264\320\273\321\217 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 */\n"
"	outline: none;\n"
"}\n"
"\n"
"QListWidget::item:hover {\n"
"    background-color: #1E1E1E; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"    color: #FFFFFF;\n"
"}"));
        MenuButtonSearchPage = new QPushButton(SearchPage);
        MenuButtonSearchPage->setObjectName("MenuButtonSearchPage");
        MenuButtonSearchPage->setGeometry(QRect(20, 20, 75, 31));
        MenuButtonSearchPage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"        color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"        border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"        border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"        padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"    }\n"
"\n"
"QPushButton:hover {\n"
"		background-color: #1E1E1E\n"
"}\n"
""));
        MoviesListSearchPage = new QListWidget(SearchPage);
        MoviesListSearchPage->setObjectName("MoviesListSearchPage");
        MoviesListSearchPage->setGeometry(QRect(145, 71, 451, 351));
        MoviesListSearchPage->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"    border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"}\n"
"\n"
"QScrollBar:vertical, QScrollBar:horizontal {\n"
"    width: 6px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \321\201\320\272\321\200\320\276\320\273\320\273\320\260 */\n"
"    background-color: #1E1E1E; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \321\201\320\272\321\200\320\276\320\273"
                        "\320\273\320\260 */\n"
"}\n"
"\n"
"QScrollBar::handle {\n"
"    background-color: #0078d7; /* \320\246\320\262\320\265\321\202 \320\277\320\276\320\273\320\267\321\203\320\275\320\272\320\260 \321\201\320\272\321\200\320\276\320\273\320\273\320\260 */\n"
"    border-radius: 3px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 \320\277\320\276\320\273\320\267\321\203\320\275\320\272\320\260 */\n"
"}\n"
"\n"
"QScrollBar::add-line, QScrollBar::sub-line {\n"
"    background-color: transparent; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 \320\277\321\200\320\276\320\272\321\200\321\203\321\202\320\272\320\270 */\n"
"}\n"
"\n"
"QListWidget::item {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 */\n"
""
                        "    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"    padding: 10px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 \320\264\320\273\321\217 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 */\n"
"    border: 1px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 \320\264\320\273\321\217 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 */\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"    background-color: #0078d7; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\274\320\265"
                        "\320\275\321\202\320\260 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\264\320\273\321\217 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260 */\n"
"}\n"
"\n"
"QListWidget::item:hover {\n"
"    background-color: #1E1E1E; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
""));
        PageSwitcher->addWidget(SearchPage);
        MenuButtonSearchPage->raise();
        SearchFieldSearchPage->raise();
        MenuListSearchPage->raise();
        MoviesListSearchPage->raise();
        mainwindow->setCentralWidget(centralwidget);

        retranslateUi(mainwindow);

        PageSwitcher->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainwindow)
    {
        mainwindow->setWindowTitle(QCoreApplication::translate("MainWindow", "mainwindow", nullptr));

        const bool __sortingEnabled = MenuListAutoselectionMoviePage->isSortingEnabled();
        MenuListAutoselectionMoviePage->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = MenuListAutoselectionMoviePage->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = MenuListAutoselectionMoviePage->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "Autoselection Movie", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = MenuListAutoselectionMoviePage->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "Liked", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = MenuListAutoselectionMoviePage->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "Tops", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = MenuListAutoselectionMoviePage->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        MenuListAutoselectionMoviePage->setSortingEnabled(__sortingEnabled);

        MenuButtonAutoselectionMoviePage->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        SearchFieldSearchPage->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search", nullptr));

        const bool __sortingEnabled1 = MenuListSearchPage->isSortingEnabled();
        MenuListSearchPage->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem5 = MenuListSearchPage->item(0);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = MenuListSearchPage->item(1);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("MainWindow", "Autoselection Movie", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = MenuListSearchPage->item(2);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("MainWindow", "Liked", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = MenuListSearchPage->item(3);
        ___qlistwidgetitem8->setText(QCoreApplication::translate("MainWindow", "Tops", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = MenuListSearchPage->item(4);
        ___qlistwidgetitem9->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        MenuListSearchPage->setSortingEnabled(__sortingEnabled1);

        MenuButtonSearchPage->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
