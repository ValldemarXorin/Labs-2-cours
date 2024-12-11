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
                               QString runtime, QString age_limit, QString description, int id) {
    ui->TitleMovie->setText(title);
    ui->Genre->setText(genre);
    ui->Year->setText(release_year);
    ui->Runtime->setText(runtime);
    ui->AgeLimit->setText(age_limit);
    ui->Description->setText(description);
    ui->Rating->setText(rating);
    movie_id = id;
}

void MovieCardInfo::OnLikeButtonClicked() {
    emit prepare_to_add_liked_movie(movie_id);
}

QToolButton* MovieCardInfo::get_like_button() {
    return ui->LikeButton;
}
