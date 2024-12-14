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
        MovieCardInfo->setStyleSheet(QString::fromUtf8("QWidget {\n"
"                background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, \n"
"                                    stop: 0 #1E1E1E, /* \320\235\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 (\321\202\320\265\320\274\320\275\321\213\320\271) */\n"
"                                    stop: 1 #001f3f); /* \320\232\320\276\320\275\320\265\321\207\320\275\321\213\320\271 \321\206\320\262\320\265\321\202 (\321\202\320\265\320\274\320\275\320\276-\321\201\320\270\320\275\320\270\320\271) */\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216 */\n"
"    }"));
        PosterLink = new QLabel(MovieCardInfo);
        PosterLink->setObjectName("PosterLink");
        PosterLink->setGeometry(QRect(20, 10, 151, 231));
        PosterLink->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        font: bold 16pt; /* \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        PosterLink->setAlignment(Qt::AlignmentFlag::AlignCenter);
        TitleMovie = new QLabel(MovieCardInfo);
        TitleMovie->setObjectName("TitleMovie");
        TitleMovie->setGeometry(QRect(200, 10, 311, 41));
        TitleMovie->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        font: bold 16pt; /* \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        TitleMovie->setAlignment(Qt::AlignmentFlag::AlignCenter);
        GenreText = new QLabel(MovieCardInfo);
        GenreText->setObjectName("GenreText");
        GenreText->setGeometry(QRect(220, 70, 71, 20));
        GenreText->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        font: bold 12pt; /* \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        GenreText->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        Genre = new QLabel(MovieCardInfo);
        Genre->setObjectName("Genre");
        Genre->setGeometry(QRect(307, 70, 280, 20));
        Genre->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"		font-size: 14px;\n"
"		font-weight: 400;\n"
"        /*font: bold 12pt;  \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        Genre->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        YearText = new QLabel(MovieCardInfo);
        YearText->setObjectName("YearText");
        YearText->setGeometry(QRect(220, 90, 71, 20));
        YearText->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        font: bold 12pt; /* \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        YearText->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        Year = new QLabel(MovieCardInfo);
        Year->setObjectName("Year");
        Year->setGeometry(QRect(307, 90, 280, 20));
        Year->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"		font-size: 14px;\n"
"		font-weight: 400;\n"
"        /*font: bold 12pt;  \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        Year->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        RuntimeText = new QLabel(MovieCardInfo);
        RuntimeText->setObjectName("RuntimeText");
        RuntimeText->setGeometry(QRect(220, 110, 71, 20));
        RuntimeText->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        font: bold 12pt; /* \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        RuntimeText->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        AgeLimitText = new QLabel(MovieCardInfo);
        AgeLimitText->setObjectName("AgeLimitText");
        AgeLimitText->setGeometry(QRect(220, 130, 71, 20));
        AgeLimitText->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        font: bold 12pt; /* \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        AgeLimitText->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        Runtime = new QLabel(MovieCardInfo);
        Runtime->setObjectName("Runtime");
        Runtime->setGeometry(QRect(307, 110, 280, 20));
        Runtime->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"		font-size: 14px;\n"
"		font-weight: 400;\n"
"        /*font: bold 12pt;  \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        Runtime->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        AgeLimit = new QLabel(MovieCardInfo);
        AgeLimit->setObjectName("AgeLimit");
        AgeLimit->setGeometry(QRect(307, 130, 280, 20));
        AgeLimit->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"		font-size: 14px;\n"
"		font-weight: 400;\n"
"        /*font: bold 12pt;  \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        AgeLimit->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        TrailerLinkText = new QLabel(MovieCardInfo);
        TrailerLinkText->setObjectName("TrailerLinkText");
        TrailerLinkText->setGeometry(QRect(210, 150, 91, 20));
        TrailerLinkText->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        font: bold 12pt; /* \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        TrailerLinkText->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        TrailerLink = new QLabel(MovieCardInfo);
        TrailerLink->setObjectName("TrailerLink");
        TrailerLink->setGeometry(QRect(307, 150, 280, 20));
        TrailerLink->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"		font-size: 14px;\n"
"		font-weight: 400;\n"
"        /*font: bold 12pt;  \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        TrailerLink->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        DirectorText = new QLabel(MovieCardInfo);
        DirectorText->setObjectName("DirectorText");
        DirectorText->setGeometry(QRect(220, 170, 71, 20));
        DirectorText->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        font: bold 12pt; /* \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        DirectorText->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        Director = new QLabel(MovieCardInfo);
        Director->setObjectName("Director");
        Director->setGeometry(QRect(307, 170, 280, 20));
        Director->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"		font-size: 14px;\n"
"		font-weight: 400;\n"
"        /*font: bold 12pt;  \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        Director->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        Rating = new QLabel(MovieCardInfo);
        Rating->setObjectName("Rating");
        Rating->setGeometry(QRect(500, 10, 91, 41));
        Rating->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        font: bold 14pt; /* \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        Rating->setAlignment(Qt::AlignmentFlag::AlignCenter);
        ActorsText = new QLabel(MovieCardInfo);
        ActorsText->setObjectName("ActorsText");
        ActorsText->setGeometry(QRect(220, 190, 71, 20));
        ActorsText->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        font: bold 12pt; /* \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        ActorsText->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        Actors = new QLabel(MovieCardInfo);
        Actors->setObjectName("Actors");
        Actors->setGeometry(QRect(307, 190, 280, 51));
        Actors->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"		font-size: 14px;\n"
"		font-weight: 400;\n"
"        /*font: bold 12pt;  \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        Actors->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        Description = new QLabel(MovieCardInfo);
        Description->setObjectName("Description");
        Description->setGeometry(QRect(20, 265, 351, 151));
        Description->setStyleSheet(QString::fromUtf8("QLabel {\n"
"		background-color: none;\n"
"        color: #FFFFFF; /* \320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        font: bold 12pt; /* \320\237\321\200\320\276\320\277\320\270\321\201\320\275\320\276\320\271 \321\201\321\202\320\270\320\273\321\214 \321\202\320\265\320\272\321\201\321\202\320\260 */\n"
"        text-align: center; /* \320\222\321\213\321\200\320\260\320\262\320\275\320\270\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\272\321\201\321\202\320\260 \320\277\320\276 \321\206\320\265\320\275\321\202\321\200\321\203 */\n"
"    }"));
        Description->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        Description->setWordWrap(true);
        LikeButton = new QToolButton(MovieCardInfo);
        LikeButton->setObjectName("LikeButton");
        LikeButton->setGeometry(QRect(540, 370, 51, 51));
        LikeButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"    background-color: #2E2E2E; /* \320\242\320\265\320\274\320\275\321\213\320\271 \321\204\320\276\320\275 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 */\n"
"    border: 2px solid #0078d7; /* \320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213 */\n"
"    border-radius: 10px; /* \320\227\320\260\320\272\321\200\321\203\320\263\320\273\320\265\320\275\320\275\321\213\320\265 \321\203\320\263\320\273\321\213 */\n"
"    padding: 5px; /* \320\236\321\202\321\201\321\202\321\203\320\277\321\213 */\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: #1E1E1E; /* \320\221\320\276\320\273\320\265\320\265 \321\201\320\262\320\265\321\202\320\273\321\213\320\271 \321\204\320\276\320\275 \320\277\321\200\320\270 \320\275\320\260\320\262\320\265\320\264\320\265\320\275\320\270\320\270 */\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"    background-color: #0078d7; /* \320\246\320\262\320\265\321\202"
                        " \321\204\320\276\320\275\320\260 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"    color: #FFFFFF; /* \320\221\320\265\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270 */\n"
"}"));

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
