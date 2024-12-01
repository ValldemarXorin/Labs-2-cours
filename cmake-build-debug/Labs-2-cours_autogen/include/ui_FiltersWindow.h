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
    QPushButton *ClearAllButton;

    void setupUi(QWidget *FiltersWindow)
    {
        if (FiltersWindow->objectName().isEmpty())
            FiltersWindow->setObjectName("FiltersWindow");
        FiltersWindow->resize(589, 377);
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
        GenreFilter->setObjectName("GenreFilter");
        GenreFilter->setGeometry(QRect(20, 20, 101, 31));
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
"}"));
        AgeLimitFilter = new QComboBox(FiltersWindow);
        AgeLimitFilter->addItem(QString());
        AgeLimitFilter->addItem(QString());
        AgeLimitFilter->addItem(QString());
        AgeLimitFilter->addItem(QString());
        AgeLimitFilter->addItem(QString());
        AgeLimitFilter->addItem(QString());
        AgeLimitFilter->setObjectName("AgeLimitFilter");
        AgeLimitFilter->setGeometry(QRect(130, 20, 101, 31));
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
        RatingFilter->setObjectName("RatingFilter");
        RatingFilter->setGeometry(QRect(240, 20, 101, 31));
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
        YearFilter->setObjectName("YearFilter");
        YearFilter->setGeometry(QRect(350, 20, 101, 31));
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
        RuntimeYear->setObjectName("RuntimeYear");
        RuntimeYear->setGeometry(QRect(460, 20, 101, 31));
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
        ApplyButton = new QPushButton(FiltersWindow);
        ApplyButton->setObjectName("ApplyButton");
        ApplyButton->setGeometry(QRect(460, 330, 101, 31));
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
        ClearAllButton = new QPushButton(FiltersWindow);
        ClearAllButton->setObjectName("ClearAllButton");
        ClearAllButton->setGeometry(QRect(350, 330, 101, 31));
        ClearAllButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(FiltersWindow);

        QMetaObject::connectSlotsByName(FiltersWindow);
    } // setupUi

    void retranslateUi(QWidget *FiltersWindow)
    {
        FiltersWindow->setWindowTitle(QCoreApplication::translate("FiltersWindow", "FiltersWindow", nullptr));
        GenreFilter->setItemText(0, QCoreApplication::translate("FiltersWindow", "horror", nullptr));
        GenreFilter->setItemText(1, QCoreApplication::translate("FiltersWindow", "drama", nullptr));
        GenreFilter->setItemText(2, QCoreApplication::translate("FiltersWindow", "sci-fi", nullptr));

        GenreFilter->setPlaceholderText(QCoreApplication::translate("FiltersWindow", "Genre", nullptr));
        AgeLimitFilter->setItemText(0, QCoreApplication::translate("FiltersWindow", "0+", nullptr));
        AgeLimitFilter->setItemText(1, QCoreApplication::translate("FiltersWindow", "3+", nullptr));
        AgeLimitFilter->setItemText(2, QCoreApplication::translate("FiltersWindow", "6+", nullptr));
        AgeLimitFilter->setItemText(3, QCoreApplication::translate("FiltersWindow", "12+", nullptr));
        AgeLimitFilter->setItemText(4, QCoreApplication::translate("FiltersWindow", "16+", nullptr));
        AgeLimitFilter->setItemText(5, QCoreApplication::translate("FiltersWindow", "18+", nullptr));

        AgeLimitFilter->setPlaceholderText(QCoreApplication::translate("FiltersWindow", "Age limit", nullptr));
        RatingFilter->setItemText(0, QCoreApplication::translate("FiltersWindow", "Increase", nullptr));
        RatingFilter->setItemText(1, QCoreApplication::translate("FiltersWindow", "Decrease", nullptr));

        RatingFilter->setPlaceholderText(QCoreApplication::translate("FiltersWindow", "Rating", nullptr));
        YearFilter->setItemText(0, QCoreApplication::translate("FiltersWindow", "Increase", nullptr));
        YearFilter->setItemText(1, QCoreApplication::translate("FiltersWindow", "Decrease", nullptr));

        YearFilter->setPlaceholderText(QCoreApplication::translate("FiltersWindow", "Year", nullptr));
        RuntimeYear->setItemText(0, QCoreApplication::translate("FiltersWindow", "Increase", nullptr));
        RuntimeYear->setItemText(1, QCoreApplication::translate("FiltersWindow", "Decrease", nullptr));

        RuntimeYear->setPlaceholderText(QCoreApplication::translate("FiltersWindow", "Runtime", nullptr));
        ApplyButton->setText(QCoreApplication::translate("FiltersWindow", "Apply", nullptr));
        ClearAllButton->setText(QCoreApplication::translate("FiltersWindow", "Clear All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FiltersWindow: public Ui_FiltersWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERSWINDOW_H
