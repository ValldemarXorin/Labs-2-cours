//
// Created by vova3 on 21.11.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MovieCard.h" resolved

#include "../../headers/interface/MovieCard.h"
#include "ui_MovieCard.h"

MovieCard::MovieCard(QWidget *parent) :
        QWidget(parent), ui(new Ui::MovieCard) {
    ui->setupUi(this);

    connect(movie_card_info->get_like_button(), &QToolButton::clicked,
            movie_card_info, &MovieCardInfo::OnLikeButtonClicked);
}

MovieCard::~MovieCard() {
    delete ui;
}

void MovieCard::set_movie_card_data(const QString &title, const QString &genre, const QString &rating,
                                    const QString &release_year, const QString &age_limit, const QString& description,
                                    int id, bool isLiked) {
    ui->TitleMovie->setText(title);
    ui->GenreMovie->setText(genre);
    ui->RatingMovie->setText(rating);
    ui->YearMovie->setText(release_year);
    ui->AgeLimitMovie->setText(age_limit);
    movie_card_info->set_information(title, genre, rating, release_year, "01:00:55", age_limit, description, id, isLiked);
}

QPushButton* MovieCard::getViewDetailsButton() {
    return ui->ViewDetailsButton;
}

MovieCardInfo* MovieCard::getMovieCardInfo() {
    return movie_card_info;
}