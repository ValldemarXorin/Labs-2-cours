//
// Created by vova3 on 28.11.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FiltersWindow.h" resolved

#include "../../headers/interface/FiltersWindow.h"
#include "ui_FiltersWindow.h"


FiltersWindow::FiltersWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::FiltersWindow) {
    ui->setupUi(this);

    ui->ApplyButton->setEnabled(false);

    connect(ui->ApplyButton, &QPushButton::clicked,
            this, &FiltersWindow::onApplyButtonClicked);

    connect(ui->PrepareButton, &QPushButton::clicked,
            this, &FiltersWindow::onPrepareButtonClicked);

    connect(ui->PrepareMovies->verticalScrollBar(), &QScrollBar::valueChanged, this, [this]() {
        if (ui->PrepareMovies->verticalScrollBar()->value() ==
            ui->PrepareMovies->verticalScrollBar()->maximum()) {
            loadNextBatch();
        }
    });
}

FiltersWindow::~FiltersWindow() {
    delete ui;
}

void FiltersWindow::onApplyButtonClicked() {
    QString genre = ui->GenreFilter->currentText();
    QString age_limit = ui->AgeLimitFilter->currentText();
    QString rating = ui->RatingFilter->currentText();
    QString year = ui->YearFilter->currentText();
    QString runtime = ui->RuntimeYear->currentText();
    this->close();
    ui->ApplyButton->setEnabled(false);
    emit FiltersWindow::filters_applied(genre, age_limit, rating, year, runtime);
}

void FiltersWindow::closeEvent(QCloseEvent *event) {
    emit filters_window_close();
}

void FiltersWindow::onPrepareButtonClicked() {
    QString genre = ui->GenreFilter->currentText();
    QString age_limit = ui->AgeLimitFilter->currentText();
    QString rating = ui->RatingFilter->currentText();
    QString year = ui->YearFilter->currentText();
    QString runtime = ui->RuntimeYear->currentText();
    ui->ApplyButton->setEnabled(true);
    emit FiltersWindow::filters_prepare(genre, age_limit, rating, year, runtime);
}

void FiltersWindow::add_movie_cards_json(std::vector<Movie> liked_movies, std::vector<Movie> json_movies) {
    this->liked_movies = std::move(liked_movies);
    this->json_movies = std::move(json_movies);

    ui->PrepareMovies->clear();
    currentBatchIndex = 0;
    loadNextBatch();
}

void FiltersWindow::loadNextBatch(int batchSize) {
    int start = currentBatchIndex * batchSize;
    int end = std::min(start + batchSize, static_cast<int>(json_movies.size()));

    for (int i = start; i < end; ++i) {
        const auto& json_movie = json_movies[i];
        auto movie_card = new MovieCard();

        bool is_liked = std::any_of(liked_movies.begin(), liked_movies.end(),
                                    [&json_movie](const Movie& like_movie) {
                                        return like_movie.get_id() == json_movie.get_id();
                                    });

        movie_card->set_movie_card_data(QString::fromStdString(json_movie.get_title()),
                                        QString::fromStdString(json_movie.get_genre()),
                                        QString::number(json_movie.get_rating()),
                                        QString::number(json_movie.get_release_year()),
                                        QString::fromStdString(json_movie.get_age_limit()),
                                        QString::fromStdString(json_movie.get_description()),
                                        json_movie.get_id(),
                                        QString::fromStdString(json_movie.get_runtime()),
                                        QString::fromStdString(json_movie.get_poster_link()),
                                        QString::fromStdString(json_movie.get_trailer_link()), is_liked);

        auto item = new QListWidgetItem(ui->PrepareMovies);
        item->setSizeHint(QSize(440, 127));
        ui->PrepareMovies->addItem(item);
        ui->PrepareMovies->setItemWidget(item, movie_card);

        connect(movie_card->getViewDetailsButton(), &QPushButton::clicked,
                movie_card->getMovieCardInfo(), &MovieCardInfo::show);

        connect(movie_card->getMovieCardInfo(), &MovieCardInfo::prepare_to_add_liked_movie,
                this, &FiltersWindow::add_liked_movie_prepare);

        connect(movie_card->getMovieCardInfo(), &MovieCardInfo::prepare_to_del_liked_movie,
                this, &FiltersWindow::delete_liked_movie_prepare);
    }

    currentBatchIndex++;
}

void FiltersWindow::add_liked_movie_prepare(int movie_id) {
    emit add_liked_movie(movie_id);
}

void FiltersWindow::delete_liked_movie_prepare(int movie_id) {
    emit delete_liked_movie(movie_id);
}