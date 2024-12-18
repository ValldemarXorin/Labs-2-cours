/********************************************************************************
** Form generated from reading UI file 'FiltersWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERSWINDOW_H
#define UI_FILTERSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FiltersWindow
{
public:
    QComboBox *GenreFilter;
    QComboBox *AgeLimitFilter;
    QComboBox *RatingFilter;
    QComboBox *YearFilter;
    QComboBox *RuntimeYear;
    QPushButton *ApplyButton;
    QPushButton *PrepareButton;
    QListWidget *PrepareMovies;

    void setupUi(QWidget *FiltersWindow)
    {
        if (FiltersWindow->objectName().isEmpty())
            FiltersWindow->setObjectName("FiltersWindow");
        FiltersWindow->resize(694, 445);
        FiltersWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, \n"
"                                stop: 0 #1E1E1E, /* \320\235\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 (\321\202\320\265\320\274\320\275\321\213\320\271) */\n"
"                                stop: 1 #001f3f); /* \320\232\320\276\320\275\320\265\321\207\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 (\321\202\320\265\320\274\320\275\320\276-\321\201\320\270\320\275\320\270\320\271) */\n"
"    color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216 */\n"
"}"));
        GenreFilter = new QComboBox(FiltersWindow);
        GenreFilter->addItem(QString());
        GenreFilter->addItem(QString());
        GenreFilter->addItem(QString());
        GenreFilter->addItem(QString());
        GenreFilter->addItem(QString());
        GenreFilter->addItem(QString());
        GenreFilter->addItem(QString());
        GenreFilter->addItem(QString());
        GenreFilter->addItem(QString());
        GenreFilter->addItem(QString());
        GenreFilter->addItem(QString());
        GenreFilter->addItem(QString());
        GenreFilter->addItem(QString());
        GenreFilter->addItem(QString());
        GenreFilter->addItem(QString());
        GenreFilter->addItem(QString());
        GenreFilter->addItem(QString());
        GenreFilter->addItem(QString());
        GenreFilter->setObjectName("GenreFilter");
        GenreFilter->setGeometry(QRect(490, 40, 161, 41));
        GenreFilter->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\272\320\276\320\274\320\261\320\276\320\261\320\276\320\272\321\201\320\260 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"    border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    background-color: #0056a1; /* \320\221\320\276\320\273\320\265\320\265 \321\201\320\264\320\265\321\200\320\266\320\260\320\275\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \320\264\320\273\321\217 \321\201\321\202\321\200\320\265\320\273\320"
                        "\272\320\270 */\n"
"    border: none; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \320\263\321\200\320\260\320\275\320\270\321\206\321\203 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 \320\264\320\273\321\217 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"    width: 30px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 2px solid #0"
                        "056a1; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
""));
        GenreFilter->setEditable(false);
        AgeLimitFilter = new QComboBox(FiltersWindow);
        AgeLimitFilter->addItem(QString());
        AgeLimitFilter->addItem(QString());
        AgeLimitFilter->addItem(QString());
        AgeLimitFilter->addItem(QString());
        AgeLimitFilter->addItem(QString());
        AgeLimitFilter->addItem(QString());
        AgeLimitFilter->addItem(QString());
        AgeLimitFilter->setObjectName("AgeLimitFilter");
        AgeLimitFilter->setGeometry(QRect(490, 110, 161, 41));
        AgeLimitFilter->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\272\320\276\320\274\320\261\320\276\320\261\320\276\320\272\321\201\320\260 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"    border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    background-color: #0056a1; /* \320\221\320\276\320\273\320\265\320\265 \321\201\320\264\320\265\321\200\320\266\320\260\320\275\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \320\264\320\273\321\217 \321\201\321\202\321\200\320\265\320\273\320"
                        "\272\320\270 */\n"
"    border: none; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \320\263\321\200\320\260\320\275\320\270\321\206\321\203 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 \320\264\320\273\321\217 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"    width: 30px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 2px solid #0"
                        "056a1; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
""));
        RatingFilter = new QComboBox(FiltersWindow);
        RatingFilter->addItem(QString());
        RatingFilter->addItem(QString());
        RatingFilter->addItem(QString());
        RatingFilter->setObjectName("RatingFilter");
        RatingFilter->setGeometry(QRect(490, 180, 161, 41));
        RatingFilter->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\272\320\276\320\274\320\261\320\276\320\261\320\276\320\272\321\201\320\260 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"    border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    background-color: #0056a1; /* \320\221\320\276\320\273\320\265\320\265 \321\201\320\264\320\265\321\200\320\266\320\260\320\275\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \320\264\320\273\321\217 \321\201\321\202\321\200\320\265\320\273\320"
                        "\272\320\270 */\n"
"    border: none; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \320\263\321\200\320\260\320\275\320\270\321\206\321\203 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 \320\264\320\273\321\217 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"    width: 30px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 2px solid #0"
                        "056a1; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));
        YearFilter = new QComboBox(FiltersWindow);
        YearFilter->addItem(QString());
        YearFilter->addItem(QString());
        YearFilter->addItem(QString());
        YearFilter->setObjectName("YearFilter");
        YearFilter->setGeometry(QRect(490, 250, 161, 41));
        YearFilter->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\272\320\276\320\274\320\261\320\276\320\261\320\276\320\272\321\201\320\260 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"    border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    background-color: #0056a1; /* \320\221\320\276\320\273\320\265\320\265 \321\201\320\264\320\265\321\200\320\266\320\260\320\275\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \320\264\320\273\321\217 \321\201\321\202\321\200\320\265\320\273\320"
                        "\272\320\270 */\n"
"    border: none; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \320\263\321\200\320\260\320\275\320\270\321\206\321\203 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 \320\264\320\273\321\217 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"    width: 30px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 2px solid #0"
                        "056a1; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));
        RuntimeYear = new QComboBox(FiltersWindow);
        RuntimeYear->addItem(QString());
        RuntimeYear->addItem(QString());
        RuntimeYear->addItem(QString());
        RuntimeYear->setObjectName("RuntimeYear");
        RuntimeYear->setGeometry(QRect(490, 320, 161, 41));
        RuntimeYear->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\272\320\276\320\274\320\261\320\276\320\261\320\276\320\272\321\201\320\260 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"    border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    background-color: #0056a1; /* \320\221\320\276\320\273\320\265\320\265 \321\201\320\264\320\265\321\200\320\266\320\260\320\275\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 \320\264\320\273\321\217 \321\201\321\202\321\200\320\265\320\273\320"
                        "\272\320\270 */\n"
"    border: none; /* \320\243\320\261\320\270\321\200\320\260\320\265\320\274 \320\263\321\200\320\260\320\275\320\270\321\206\321\203 */\n"
"    border-radius: 5px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 \320\264\320\273\321\217 \321\201\321\202\321\200\320\265\320\273\320\272\320\270 */\n"
"    width: 30px; /* \320\250\320\270\321\200\320\270\320\275\320\260 \320\272\320\275\320\276\320\277\320\272\320\270 */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\262\321\213\320\277\320\260\320\264\320\260\321\216\321\211\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 2px solid #0"
                        "056a1; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));
        RuntimeYear->setEditable(false);
        ApplyButton = new QPushButton(FiltersWindow);
        ApplyButton->setObjectName("ApplyButton");
        ApplyButton->setGeometry(QRect(350, 400, 101, 31));
        ApplyButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"    border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1E1E1E; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));
        PrepareButton = new QPushButton(FiltersWindow);
        PrepareButton->setObjectName("PrepareButton");
        PrepareButton->setGeometry(QRect(30, 400, 101, 31));
        PrepareButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"    border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1E1E1E; /* \320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}"));
        PrepareMovies = new QListWidget(FiltersWindow);
        PrepareMovies->setObjectName("PrepareMovies");
        PrepareMovies->setGeometry(QRect(30, 40, 415, 321));
        PrepareMovies->setStyleSheet(QString::fromUtf8("QListWidget {\n"
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

        retranslateUi(FiltersWindow);

        QMetaObject::connectSlotsByName(FiltersWindow);
    } // setupUi

    void retranslateUi(QWidget *FiltersWindow)
    {
        FiltersWindow->setWindowTitle(QCoreApplication::translate("FiltersWindow", "FiltersWindow", nullptr));
        GenreFilter->setItemText(0, QCoreApplication::translate("FiltersWindow", "\320\233\321\216\320\261\320\276\320\271 \320\266\320\260\320\275\321\200", nullptr));
        GenreFilter->setItemText(1, QCoreApplication::translate("FiltersWindow", "\321\202\321\200\320\270\320\273\320\273\320\265\321\200", nullptr));
        GenreFilter->setItemText(2, QCoreApplication::translate("FiltersWindow", "\320\264\321\200\320\260\320\274\320\260", nullptr));
        GenreFilter->setItemText(3, QCoreApplication::translate("FiltersWindow", "\320\261\320\276\320\265\320\262\320\270\320\272", nullptr));
        GenreFilter->setItemText(4, QCoreApplication::translate("FiltersWindow", "\320\272\321\200\320\270\320\274\320\270\320\275\320\260\320\273", nullptr));
        GenreFilter->setItemText(5, QCoreApplication::translate("FiltersWindow", "\320\270\321\201\321\202\320\276\321\200\320\270\321\207\320\265\321\201\320\272\320\270\320\271", nullptr));
        GenreFilter->setItemText(6, QCoreApplication::translate("FiltersWindow", "\320\277\321\200\320\270\320\272\320\273\321\216\321\207\320\265\320\275\321\207\320\265\321\201\320\272\320\270\320\271", nullptr));
        GenreFilter->setItemText(7, QCoreApplication::translate("FiltersWindow", "\320\272\320\276\320\274\320\265\320\264\320\270\321\217", nullptr));
        GenreFilter->setItemText(8, QCoreApplication::translate("FiltersWindow", "\321\201\320\265\320\274\320\265\320\271\320\275\321\213\320\271", nullptr));
        GenreFilter->setItemText(9, QCoreApplication::translate("FiltersWindow", "\321\204\320\260\320\275\321\202\320\260\321\201\321\202\320\270\320\272\320\260", nullptr));
        GenreFilter->setItemText(10, QCoreApplication::translate("FiltersWindow", "\320\260\320\275\320\270\320\274\320\260\321\206\320\270\321\217", nullptr));
        GenreFilter->setItemText(11, QCoreApplication::translate("FiltersWindow", "\320\261\320\270\320\276\320\263\321\200\320\260\321\204\320\270\321\217", nullptr));
        GenreFilter->setItemText(12, QCoreApplication::translate("FiltersWindow", "\320\262\320\276\320\265\320\275\320\275\321\213\320\271", nullptr));
        GenreFilter->setItemText(13, QCoreApplication::translate("FiltersWindow", "\321\200\320\276\320\274\320\260\320\275\321\202\320\270\320\272\320\260", nullptr));
        GenreFilter->setItemText(14, QCoreApplication::translate("FiltersWindow", "\320\264\320\265\321\202\320\265\320\272\321\202\320\270\320\262", nullptr));
        GenreFilter->setItemText(15, QCoreApplication::translate("FiltersWindow", "\320\262\320\265\321\201\321\202\320\265\321\200\320\275", nullptr));
        GenreFilter->setItemText(16, QCoreApplication::translate("FiltersWindow", "\320\275\320\260\321\203\321\207\320\275\321\213\320\271", nullptr));
        GenreFilter->setItemText(17, QCoreApplication::translate("FiltersWindow", "\321\201\320\277\320\276\321\200\321\202", nullptr));

        GenreFilter->setPlaceholderText(QCoreApplication::translate("FiltersWindow", "\320\226\320\260\320\275\321\200", nullptr));
        AgeLimitFilter->setItemText(0, QCoreApplication::translate("FiltersWindow", "\320\233\321\216\320\261\320\276\320\271 \320\262\320\276\320\267\321\200\320\260\321\201\321\202", nullptr));
        AgeLimitFilter->setItemText(1, QCoreApplication::translate("FiltersWindow", "0+", nullptr));
        AgeLimitFilter->setItemText(2, QCoreApplication::translate("FiltersWindow", "3+", nullptr));
        AgeLimitFilter->setItemText(3, QCoreApplication::translate("FiltersWindow", "6+", nullptr));
        AgeLimitFilter->setItemText(4, QCoreApplication::translate("FiltersWindow", "12+", nullptr));
        AgeLimitFilter->setItemText(5, QCoreApplication::translate("FiltersWindow", "16+", nullptr));
        AgeLimitFilter->setItemText(6, QCoreApplication::translate("FiltersWindow", "18+", nullptr));

        AgeLimitFilter->setPlaceholderText(QString());
        RatingFilter->setItemText(0, QCoreApplication::translate("FiltersWindow", "\320\233\321\216\320\261\320\276\320\271 \321\200\320\265\320\271\321\202\320\270\320\275\320\263", nullptr));
        RatingFilter->setItemText(1, QCoreApplication::translate("FiltersWindow", "\320\222\321\213\321\210\320\265", nullptr));
        RatingFilter->setItemText(2, QCoreApplication::translate("FiltersWindow", "\320\235\320\270\320\266\320\265", nullptr));

        RatingFilter->setPlaceholderText(QString());
        YearFilter->setItemText(0, QCoreApplication::translate("FiltersWindow", "\320\233\321\216\320\261\320\276\320\271 \320\263\320\276\320\264", nullptr));
        YearFilter->setItemText(1, QCoreApplication::translate("FiltersWindow", "\320\235\320\276\320\262\321\213\320\265", nullptr));
        YearFilter->setItemText(2, QCoreApplication::translate("FiltersWindow", "\320\241\321\202\320\260\321\200\321\213\320\265", nullptr));

        YearFilter->setPlaceholderText(QString());
        RuntimeYear->setItemText(0, QCoreApplication::translate("FiltersWindow", "\320\233\321\216\320\261\320\260\321\217 \320\264\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        RuntimeYear->setItemText(1, QCoreApplication::translate("FiltersWindow", "\320\224\320\273\320\270\320\275\320\275\320\265\320\265", nullptr));
        RuntimeYear->setItemText(2, QCoreApplication::translate("FiltersWindow", "\320\232\320\276\321\200\320\276\321\207\320\265", nullptr));

        RuntimeYear->setCurrentText(QCoreApplication::translate("FiltersWindow", "\320\233\321\216\320\261\320\260\321\217 \320\264\320\273\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        RuntimeYear->setPlaceholderText(QString());
        ApplyButton->setText(QCoreApplication::translate("FiltersWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        PrepareButton->setText(QCoreApplication::translate("FiltersWindow", "\320\237\320\276\320\264\320\263\320\276\321\202\320\276\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FiltersWindow: public Ui_FiltersWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERSWINDOW_H
