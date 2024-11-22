//
// Created by vova3 on 20.10.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "../../headers/interface/MainWindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(IMoviesRepository* movies, IUserRepository* users,
                       QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow), movies_repository(movies_repository), users(users),
        search_engine(new SearchEngine(*movies)) {

    ui->setupUi(this);

    ui->PageSwitcher->setCurrentIndex(AUTOSELECTION_MOVIE_PAGE_INDEX);
    ui->MenuListAutoselectionMoviePage->setFixedWidth(0);

    connect(ui->SearchFieldSearchPage, &QLineEdit::textChanged, this,
            &MainWindow::using_search_enging);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_MenuButtonAutoselectionMoviePage_clicked() {
    if (ui->MenuListAutoselectionMoviePage->maximumWidth() == 0) {
        ui->MenuListAutoselectionMoviePage->setFixedWidth(118);
    }
    else
        ui->MenuListAutoselectionMoviePage->setFixedWidth(0);
    ui->MenuButtonAutoselectionMoviePage->setVisible(false);
}

void MainWindow::on_MenuListAutoselectionMoviePage_itemClicked(QListWidgetItem *item) {
    if (item->text() == "Back") {
        ui->MenuListAutoselectionMoviePage->setFixedWidth(0);
        ui->MenuButtonAutoselectionMoviePage->setVisible(true);
        return;
    }

    ui->PageSwitcher->setCurrentIndex(pages[item->text()]);
    ui->MenuListAutoselectionMoviePage->setFixedWidth(0);
    ui->MenuButtonSearchPage->setVisible(true);
}

void MainWindow::using_search_enging() {
    ui->MoviesListSearchPage->clear();
    std::vector<Movie> movies;
    if (ui->SearchFieldSearchPage->text().toStdString().length() < precurrent_length_text_search_field) {
        movies = search_engine->search_by_fragment(ui->SearchFieldSearchPage->text().toStdString(), false);
    }
    else {
        movies = search_engine->search_by_fragment(ui->SearchFieldSearchPage->text().toStdString(), true);
    }

    for (auto& movie: movies) {
        add_movie_card(QString::fromStdString(movie.get_title()), QString::fromStdString(movie.get_genre()),
                       QString::fromStdString("9.0"), QString::fromStdString("2005"),
                       QString::fromStdString(movie.get_age_limit()));
    }
}

void MainWindow::add_movie_card(const QString &title, const QString &genre, const QString &rating,
                                      const QString &release_year, const QString &age_limit) {
    auto movie_card = new MovieCard();
    movie_card->set_movie_card_data(title, genre, rating, release_year, age_limit);

    auto item = new QListWidgetItem(ui->MoviesListSearchPage);
    item->setSizeHint(QSize(440, 90));
    ui->MoviesListSearchPage->addItem(item);
    ui->MoviesListSearchPage->setItemWidget(item, movie_card);
}


