/********************************************************************************
** Form generated from reading UI file 'MovieCardInfo.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIECARDINFO_H
#define UI_MOVIECARDINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MovieCardInfo
{
public:
    QLabel *PosterLink;
    QLabel *TitleMovie;
    QLabel *GenreText;
    QLabel *Genre;
    QLabel *YearText;
    QLabel *Year;
    QLabel *RuntimeText;
    QLabel *AgeLimitText;
    QLabel *Runtime;
    QLabel *AgeLimit;
    QLabel *TrailerLinkText;
    QLabel *TrailerLink;
    QLabel *DirectorText;
    QLabel *Director;
    QLabel *Rating;
    QLabel *ActorsText;
    QLabel *Actors;
    QLabel *Description;
    QToolButton *LikeButton;

    void setupUi(QWidget *MovieCardInfo)
    {
        if (MovieCardInfo->objectName().isEmpty())
            MovieCardInfo->setObjectName("MovieCardInfo");
        MovieCardInfo->resize(615, 445);
        PosterLink = new QLabel(MovieCardInfo);
        PosterLink->setObjectName("PosterLink");
        PosterLink->setGeometry(QRect(20, 10, 151, 231));
        PosterLink->setAlignment(Qt::AlignmentFlag::AlignCenter);
        TitleMovie = new QLabel(MovieCardInfo);
        TitleMovie->setObjectName("TitleMovie");
        TitleMovie->setGeometry(QRect(200, 10, 311, 41));
        TitleMovie->setAlignment(Qt::AlignmentFlag::AlignCenter);
        GenreText = new QLabel(MovieCardInfo);
        GenreText->setObjectName("GenreText");
        GenreText->setGeometry(QRect(220, 70, 71, 20));
        GenreText->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Genre = new QLabel(MovieCardInfo);
        Genre->setObjectName("Genre");
        Genre->setGeometry(QRect(290, 70, 271, 20));
        Genre->setAlignment(Qt::AlignmentFlag::AlignCenter);
        YearText = new QLabel(MovieCardInfo);
        YearText->setObjectName("YearText");
        YearText->setGeometry(QRect(220, 90, 71, 20));
        YearText->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Year = new QLabel(MovieCardInfo);
        Year->setObjectName("Year");
        Year->setGeometry(QRect(290, 90, 271, 20));
        Year->setAlignment(Qt::AlignmentFlag::AlignCenter);
        RuntimeText = new QLabel(MovieCardInfo);
        RuntimeText->setObjectName("RuntimeText");
        RuntimeText->setGeometry(QRect(220, 110, 71, 20));
        RuntimeText->setAlignment(Qt::AlignmentFlag::AlignCenter);
        AgeLimitText = new QLabel(MovieCardInfo);
        AgeLimitText->setObjectName("AgeLimitText");
        AgeLimitText->setGeometry(QRect(220, 130, 71, 20));
        AgeLimitText->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Runtime = new QLabel(MovieCardInfo);
        Runtime->setObjectName("Runtime");
        Runtime->setGeometry(QRect(290, 110, 271, 20));
        Runtime->setAlignment(Qt::AlignmentFlag::AlignCenter);
        AgeLimit = new QLabel(MovieCardInfo);
        AgeLimit->setObjectName("AgeLimit");
        AgeLimit->setGeometry(QRect(290, 130, 271, 20));
        AgeLimit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        TrailerLinkText = new QLabel(MovieCardInfo);
        TrailerLinkText->setObjectName("TrailerLinkText");
        TrailerLinkText->setGeometry(QRect(220, 150, 71, 20));
        TrailerLinkText->setAlignment(Qt::AlignmentFlag::AlignCenter);
        TrailerLink = new QLabel(MovieCardInfo);
        TrailerLink->setObjectName("TrailerLink");
        TrailerLink->setGeometry(QRect(290, 150, 271, 20));
        TrailerLink->setAlignment(Qt::AlignmentFlag::AlignCenter);
        DirectorText = new QLabel(MovieCardInfo);
        DirectorText->setObjectName("DirectorText");
        DirectorText->setGeometry(QRect(220, 170, 71, 20));
        DirectorText->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Director = new QLabel(MovieCardInfo);
        Director->setObjectName("Director");
        Director->setGeometry(QRect(290, 170, 271, 20));
        Director->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Rating = new QLabel(MovieCardInfo);
        Rating->setObjectName("Rating");
        Rating->setGeometry(QRect(530, 10, 61, 41));
        Rating->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ActorsText = new QLabel(MovieCardInfo);
        ActorsText->setObjectName("ActorsText");
        ActorsText->setGeometry(QRect(220, 190, 71, 20));
        ActorsText->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Actors = new QLabel(MovieCardInfo);
        Actors->setObjectName("Actors");
        Actors->setGeometry(QRect(290, 190, 271, 51));
        Actors->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);
        Description = new QLabel(MovieCardInfo);
        Description->setObjectName("Description");
        Description->setGeometry(QRect(20, 265, 351, 151));
        Description->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        Description->setWordWrap(true);
        LikeButton = new QToolButton(MovieCardInfo);
        LikeButton->setObjectName("LikeButton");
        LikeButton->setGeometry(QRect(540, 370, 51, 51));

        retranslateUi(MovieCardInfo);

        QMetaObject::connectSlotsByName(MovieCardInfo);
    } // setupUi

    void retranslateUi(QWidget *MovieCardInfo)
    {
        MovieCardInfo->setWindowTitle(QCoreApplication::translate("MovieCardInfo", "MovieCardInfo", nullptr));
        PosterLink->setText(QCoreApplication::translate("MovieCardInfo", "TextLabel", nullptr));
        TitleMovie->setText(QCoreApplication::translate("MovieCardInfo", "TextLabel", nullptr));
        GenreText->setText(QCoreApplication::translate("MovieCardInfo", "Genre:", nullptr));
        Genre->setText(QCoreApplication::translate("MovieCardInfo", "TextLabel", nullptr));
        YearText->setText(QCoreApplication::translate("MovieCardInfo", "Year:", nullptr));
        Year->setText(QCoreApplication::translate("MovieCardInfo", "TextLabel", nullptr));
        RuntimeText->setText(QCoreApplication::translate("MovieCardInfo", "Runtime:", nullptr));
        AgeLimitText->setText(QCoreApplication::translate("MovieCardInfo", "Age limit:", nullptr));
        Runtime->setText(QCoreApplication::translate("MovieCardInfo", "TextLabel", nullptr));
        AgeLimit->setText(QCoreApplication::translate("MovieCardInfo", "TextLabel", nullptr));
        TrailerLinkText->setText(QCoreApplication::translate("MovieCardInfo", "Trailer link:", nullptr));
        TrailerLink->setText(QCoreApplication::translate("MovieCardInfo", "TextLabel", nullptr));
        DirectorText->setText(QCoreApplication::translate("MovieCardInfo", "Director:", nullptr));
        Director->setText(QCoreApplication::translate("MovieCardInfo", "TextLabel", nullptr));
        Rating->setText(QCoreApplication::translate("MovieCardInfo", "TextLabel", nullptr));
        ActorsText->setText(QCoreApplication::translate("MovieCardInfo", "Actors:", nullptr));
        Actors->setText(QCoreApplication::translate("MovieCardInfo", "TextLabel", nullptr));
        Description->setText(QCoreApplication::translate("MovieCardInfo", "TextLabel", nullptr));
        LikeButton->setText(QCoreApplication::translate("MovieCardInfo", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MovieCardInfo: public Ui_MovieCardInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIECARDINFO_H
