//
// Created by vova3 on 24.11.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MovieCardInfo.h" resolved

#include "../../headers/interface/MovieCardInfo.h"
#include "ui_MovieCardInfo.h"


MovieCardInfo::MovieCardInfo(QWidget *parent) : QWidget(parent), ui(new Ui::MovieCardInfo) {
    ui->setupUi(this);

    ui->LikeButton->setIcon(QIcon("D:/Labs-2-cours/Labs-2-cours/images/InActiveLike.png"));
}

MovieCardInfo::~MovieCardInfo() {
    delete ui;
}

void MovieCardInfo::set_information(QString title, QString genre, QString rating, QString release_year,
                               QString runtime, QString age_limit, QString description, int id, QString poster_link,
                               QString trailer_link, bool isLiked) {

    std::string normal_rating = rating.toStdString();
    size_t dot_position = normal_rating.find('.');
    normal_rating = normal_rating.substr(0, dot_position + 2);

    QString html_link = QString(R"(<a href="%1">Трейлер</a>)").arg(trailer_link);

    ui->TitleMovie->setText(title);
    ui->Genre->setText(genre);
    ui->Year->setText(release_year);
    ui->Runtime->setText(runtime);
    ui->AgeLimit->setText(age_limit);
    ui->Description->setText(description);
    ui->Rating->setText(QString::fromStdString(normal_rating));
    ui->TrailerLink->setOpenExternalLinks(true);
    ui->TrailerLink->setText(trailer_link);
    ui->TrailerLink->setText(html_link);
    ui->TrailerLink->setTextFormat(Qt::RichText);
    ui->TrailerLink->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->PosterLink->setPixmap(QPixmap(poster_link));
    ui->PosterLink->setScaledContents(true);
    ui->starIcon->setPixmap(QPixmap("D:/Labs-2-cours/Labs-2-cours/images/star.png"));
    ui->starIcon->setScaledContents(true);


    movie_id = id;
    is_liked = isLiked;


    if (is_liked == true)
        ui->LikeButton->setIcon(QIcon("D:/Labs-2-cours/Labs-2-cours/images/ActiveLike.png"));
    else
        ui->LikeButton->setIcon(QIcon("D:/Labs-2-cours/Labs-2-cours/images/InActiveLike.png"));
}

void MovieCardInfo::OnLikeButtonClicked() {
    if (is_liked == true) {
        is_liked = false;
        ui->LikeButton->setIcon(QIcon("D:/Labs-2-cours/Labs-2-cours/images/InActiveLike.png"));
        emit prepare_to_del_liked_movie(movie_id);
        return;
    }
    else {
        is_liked = true;
        ui->LikeButton->setIcon(QIcon("D:/Labs-2-cours/Labs-2-cours/images/ActiveLike.png"));
        emit prepare_to_add_liked_movie(movie_id);
        return;
    }


}

QToolButton* MovieCardInfo::get_like_button() {
    return ui->LikeButton;
}
