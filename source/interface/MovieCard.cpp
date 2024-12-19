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
                                    int id, const QString &runtime,
                                    const QString& poster_link, const QString& trailer_link, bool isLiked) {
    std::string normal_rating = rating.toStdString();
    size_t dot_position = normal_rating.find('.');
    normal_rating = normal_rating.substr(0, dot_position + 2);
    ui->TitleMovie->setText(title);
    ui->GenreMovie->setText(genre);
    ui->RatingMovie->setText(QString::fromStdString(normal_rating));
    //ui->YearMovie->setText(release_year);
    ui->AgeLimitMovie->setText(age_limit);
    title_card = title;
    genre_card = genre;
    rating_card = rating;
    release_year_card = release_year;
    age_limit_card = age_limit;
    description_card = description;
    movie_id_card = id;
    runtime_card = runtime;
    poster_link_card = poster_link;
    trailer_link_card = trailer_link;
    isLiked_card = isLiked;
}

QPushButton* MovieCard::getViewDetailsButton() {
    return ui->ViewDetailsButton;
}

MovieCardInfo* MovieCard::getMovieCardInfo() {
    movie_card_info->set_information(title_card, genre_card, rating_card, release_year_card,
                                     runtime_card, age_limit_card, description_card,
                                     movie_id_card, poster_link_card, trailer_link_card, isLiked_card);
    return movie_card_info;
}