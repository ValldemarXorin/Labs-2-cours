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
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FiltersWindow
{
public:
    QLabel *GenreText;
    QLabel *AgeLimitText;
    QRadioButton *isHorror;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;

    void setupUi(QWidget *FiltersWindow)
    {
        if (FiltersWindow->objectName().isEmpty())
            FiltersWindow->setObjectName("FiltersWindow");
        FiltersWindow->resize(400, 300);
        GenreText = new QLabel(FiltersWindow);
        GenreText->setObjectName("GenreText");
        GenreText->setGeometry(QRect(10, 20, 49, 16));
        AgeLimitText = new QLabel(FiltersWindow);
        AgeLimitText->setObjectName("AgeLimitText");
        AgeLimitText->setGeometry(QRect(290, 20, 49, 16));
        isHorror = new QRadioButton(FiltersWindow);
        isHorror->setObjectName("isHorror");
        isHorror->setGeometry(QRect(10, 66, 81, 20));
        radioButton_2 = new QRadioButton(FiltersWindow);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(10, 100, 92, 20));
        radioButton_3 = new QRadioButton(FiltersWindow);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(260, 60, 92, 20));
        radioButton_4 = new QRadioButton(FiltersWindow);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(260, 90, 92, 20));
        radioButton_5 = new QRadioButton(FiltersWindow);
        radioButton_5->setObjectName("radioButton_5");
        radioButton_5->setGeometry(QRect(260, 120, 92, 20));

        retranslateUi(FiltersWindow);

        QMetaObject::connectSlotsByName(FiltersWindow);
    } // setupUi

    void retranslateUi(QWidget *FiltersWindow)
    {
        FiltersWindow->setWindowTitle(QCoreApplication::translate("FiltersWindow", "FiltersWindow", nullptr));
        GenreText->setText(QCoreApplication::translate("FiltersWindow", "Genre", nullptr));
        AgeLimitText->setText(QCoreApplication::translate("FiltersWindow", "Age Limit", nullptr));
        isHorror->setText(QCoreApplication::translate("FiltersWindow", "horror", nullptr));
        radioButton_2->setText(QCoreApplication::translate("FiltersWindow", "drama", nullptr));
        radioButton_3->setText(QCoreApplication::translate("FiltersWindow", "18+", nullptr));
        radioButton_4->setText(QCoreApplication::translate("FiltersWindow", "12+", nullptr));
        radioButton_5->setText(QCoreApplication::translate("FiltersWindow", "16+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FiltersWindow: public Ui_FiltersWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERSWINDOW_H
