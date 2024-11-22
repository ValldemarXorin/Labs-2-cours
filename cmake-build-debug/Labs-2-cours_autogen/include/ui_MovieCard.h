/********************************************************************************
** Form generated from reading UI file 'MovieCard.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIECARD_H
#define UI_MOVIECARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MovieCard
{
public:
    QLabel *TitleMovie;
    QLabel *RatingMovie;
    QLabel *YearMovie;
    QLabel *GenreMovie;
    QLabel *AgeLimitMovie;

    void setupUi(QWidget *MovieCard)
    {
        if (MovieCard->objectName().isEmpty())
            MovieCard->setObjectName("MovieCard");
        MovieCard->resize(451, 90);
        MovieCard->setStyleSheet(QString::fromUtf8("MovieCard {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 \320\264\320\273\321\217 \320\272\320\260\321\200\321\202\320\276\321\207\320\272\320\270 */\n"
"    border: 1px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 \320\272\320\260\321\200\321\202\320\276\321\207\320\272\320\270 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 10px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"}\n"
"\n"
"MovieCard QLabel {\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\264\320\273\321\217 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 \320\262 \320\272\320\260\321\200\321\202\320\276\321\207\320\272\320\265 */\n"
"}\n"
"\n"
"MovieCard QLabel#TitleMovie "
                        "{\n"
"    font-size: 16px; /* \320\243\320\262\320\265\320\273\320\270\321\207\320\265\320\275\320\275\321\213\320\271 \321\200\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 \320\264\320\273\321\217 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\217 */\n"
"    font-weight: bold; /* \320\226\320\270\321\200\320\275\321\213\320\271 \321\210\321\200\320\270\321\204\321\202 \320\264\320\273\321\217 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\217 */\n"
"}\n"
"\n"
"MovieCard QLabel#RatingMovie,\n"
"MovieCard QLabel#GenreMovie,\n"
"MovieCard QLabel#AgeLimitMovie {\n"
"    font-size: 14px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 \320\264\320\273\321\217 \320\264\321\200\321\203\320\263\320\270\321\205 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 */\n"
"}"));
        TitleMovie = new QLabel(MovieCard);
        TitleMovie->setObjectName("TitleMovie");
        TitleMovie->setGeometry(QRect(10, 0, 181, 71));
        TitleMovie->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white; /* \320\221\320\265\320\273\321\213\320\271 \321\206\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    background-color: transparent; /* \320\237\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"    font-size: 14px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"	qproperty-wordWrap: true;\n"
"    qproperty-scaledContents: true;\n"
"}"));
        TitleMovie->setAlignment(Qt::AlignmentFlag::AlignCenter);
        RatingMovie = new QLabel(MovieCard);
        RatingMovie->setObjectName("RatingMovie");
        RatingMovie->setGeometry(QRect(340, 40, 91, 41));
        RatingMovie->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white; /* \320\221\320\265\320\273\321\213\320\271 \321\206\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    background-color: transparent; /* \320\237\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"    font-size: 14px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"	qproperty-wordWrap: true;\n"
"    qproperty-scaledContents: true;\n"
"}"));
        RatingMovie->setAlignment(Qt::AlignmentFlag::AlignCenter);
        YearMovie = new QLabel(MovieCard);
        YearMovie->setObjectName("YearMovie");
        YearMovie->setGeometry(QRect(250, 50, 81, 21));
        YearMovie->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white; /* \320\221\320\265\320\273\321\213\320\271 \321\206\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    background-color: transparent; /* \320\237\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"    font-size: 14px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"	qproperty-wordWrap: true;\n"
"    qproperty-scaledContents: true;\n"
"}"));
        YearMovie->setAlignment(Qt::AlignmentFlag::AlignCenter);
        GenreMovie = new QLabel(MovieCard);
        GenreMovie->setObjectName("GenreMovie");
        GenreMovie->setGeometry(QRect(240, 0, 101, 41));
        GenreMovie->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white; /* \320\221\320\265\320\273\321\213\320\271 \321\206\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    background-color: transparent; /* \320\237\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"    font-size: 14px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"	qproperty-wordWrap: true;\n"
"    qproperty-scaledContents: true;\n"
"}"));
        GenreMovie->setAlignment(Qt::AlignmentFlag::AlignCenter);
        AgeLimitMovie = new QLabel(MovieCard);
        AgeLimitMovie->setObjectName("AgeLimitMovie");
        AgeLimitMovie->setGeometry(QRect(350, 10, 71, 21));
        AgeLimitMovie->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white; /* \320\221\320\265\320\273\321\213\320\271 \321\206\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"    background-color: transparent; /* \320\237\321\200\320\276\320\267\321\200\320\260\321\207\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"    font-size: 14px; /* \320\240\320\260\320\267\320\274\320\265\321\200 \321\210\321\200\320\270\321\204\321\202\320\260 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"	qproperty-wordWrap: true;\n"
"    qproperty-scaledContents: true;\n"
"}"));

        retranslateUi(MovieCard);

        QMetaObject::connectSlotsByName(MovieCard);
    } // setupUi

    void retranslateUi(QWidget *MovieCard)
    {
        MovieCard->setWindowTitle(QCoreApplication::translate("MovieCard", "MovieCard", nullptr));
        TitleMovie->setText(QCoreApplication::translate("MovieCard", "TextLabel", nullptr));
        RatingMovie->setText(QCoreApplication::translate("MovieCard", "TextLabel", nullptr));
        YearMovie->setText(QCoreApplication::translate("MovieCard", "TextLabel", nullptr));
        GenreMovie->setText(QCoreApplication::translate("MovieCard", "TextLabel", nullptr));
        AgeLimitMovie->setText(QCoreApplication::translate("MovieCard", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MovieCard: public Ui_MovieCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIECARD_H
