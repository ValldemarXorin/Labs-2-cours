//
// Created by vova3 on 20.10.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "../../headers/interface/MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(IMoviesRepository* movies, IUserRepository* users, LikedRepository* liked_movies, User* current_user,
                       QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow), movies_repository(movies), users(users), liked_movies(liked_movies),
        search_engine(new SearchEngine(*movies)), movies_for_search_list(movies->get_movies()),
        current_user(current_user), json_movie_collection(new JSONMovieCollection("MyLiked")),
        recommend(new MovieRecommender(movies_repository->get_movies())){

    ui->setupUi(this);

    ui->PageSwitcher->setCurrentIndex(AUTOSELECTION_MOVIE_PAGE_INDEX);
    ui->MenuListAutoselectionMoviePage->setFixedWidth(0);

    ui->ErrorAutoselectionMoviePage->setVisible(false);

    connect(ui->SearchFieldSearchPage, &QLineEdit::textChanged, this,
            &MainWindow::using_search_enging);

    get_top_kinopoisk();
    show_liked_movies();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_MenuButtonAutoselectionMoviePage_clicked() {
    ui->MenuListAutoselectionMoviePage->setFixedWidth(118);
    ui->MenuButtonAutoselectionMoviePage->setVisible(false);
}

void MainWindow::on_MenuButtonSearchPage_clicked() {
    ui->MenuListSearchPage->setFixedWidth(118);
    ui->MenuButtonSearchPage->setVisible(false);
}

void MainWindow::on_MenuButtonLikedPage_clicked() {
    ui->MenuListLikedPage->setFixedWidth(118);
    ui->MenuButtonLikedPage->setVisible(false);
}

void MainWindow::on_MenuButtonTopsPage_clicked() {
    ui->MenuListTopsPage->setFixedWidth(118);
    ui->MenuButtonTopsPage->setVisible(false);
}

void MainWindow::on_MenuListAutoselectionMoviePage_itemClicked(QListWidgetItem *item) {
    if (item->text() == "Back" || item->text() == "Autoselection Movie") {
        ui->MenuListAutoselectionMoviePage->setFixedWidth(0);
        ui->MenuButtonAutoselectionMoviePage->setVisible(true);
        return;
    }

    if (item->text() == "Search") {
        ui->PageSwitcher->setCurrentIndex(SEARCH_PAGE_INDEX);
        ui->MenuListAutoselectionMoviePage->setFixedWidth(0);
        ui->MenuListSearchPage->setFixedWidth(0);
        ui->MenuButtonSearchPage->setVisible(true);
        return;
    }

    if (item->text() == "Liked") {
        ui->PageSwitcher->setCurrentIndex(LIKED_PAGE_INDEX);
        ui->MenuListAutoselectionMoviePage->setFixedWidth(0);
        ui->MenuListLikedPage->setFixedWidth(0);
        ui->MenuButtonLikedPage->setVisible(true);
        return;
    }

    if (item->text() == "Tops") {
        ui->PageSwitcher->setCurrentIndex(TOPS_PAGE_INDEX);
        ui->MenuListAutoselectionMoviePage->setFixedWidth(0);
        ui->MenuListTopsPage->setFixedWidth(0);
        ui->MenuButtonTopsPage->setVisible(true);
        return;
    }
}

void MainWindow::on_MenuListSearchPage_itemClicked(QListWidgetItem *item) {
    if (item->text() == "Back" || item->text() == "Search") {
        ui->MenuListSearchPage->setFixedWidth(0);
        ui->MenuButtonSearchPage->setVisible(true);
        return;
    }

    if (item->text() == "Autoselection Movie") {
        ui->PageSwitcher->setCurrentIndex(AUTOSELECTION_MOVIE_PAGE_INDEX);
        ui->MenuListSearchPage->setFixedWidth(0);
        ui->MenuListAutoselectionMoviePage->setFixedWidth(0);
        ui->MenuButtonAutoselectionMoviePage->setVisible(true);
        return;
    }

    if (item->text() == "Liked") {
        ui->PageSwitcher->setCurrentIndex(LIKED_PAGE_INDEX);
        ui->MenuListSearchPage->setFixedWidth(0);
        ui->MenuListLikedPage->setFixedWidth(0);
        ui->MenuButtonLikedPage->setVisible(true);
        return;
    }

    if (item->text() == "Tops") {
        ui->PageSwitcher->setCurrentIndex(TOPS_PAGE_INDEX);
        ui->MenuListSearchPage->setFixedWidth(0);
        ui->MenuListTopsPage->setFixedWidth(0);
        ui->MenuButtonTopsPage->setVisible(true);
        return;
    }
}

void MainWindow::on_MenuListTopsPage_itemClicked(QListWidgetItem *item) {
    if (item->text() == "Back" || item->text() == "Tops") {
        ui->MenuListTopsPage->setFixedWidth(0);
        ui->MenuButtonTopsPage->setVisible(true);
        return;
    }

    if (item->text() == "Search") {
        ui->PageSwitcher->setCurrentIndex(SEARCH_PAGE_INDEX);
        ui->MenuListTopsPage->setFixedWidth(0);
        ui->MenuListSearchPage->setFixedWidth(0);
        ui->MenuButtonSearchPage->setVisible(true);
        return;
    }

    if (item->text() == "Liked") {
        ui->PageSwitcher->setCurrentIndex(LIKED_PAGE_INDEX);
        ui->MenuListTopsPage->setFixedWidth(0);
        ui->MenuListLikedPage->setFixedWidth(0);
        ui->MenuButtonLikedPage->setVisible(true);
        return;
    }

    if (item->text() == "Autoselection Movie") {
        ui->PageSwitcher->setCurrentIndex(AUTOSELECTION_MOVIE_PAGE_INDEX);
        ui->MenuListTopsPage->setFixedWidth(0);
        ui->MenuListAutoselectionMoviePage->setFixedWidth(0);
        ui->MenuButtonAutoselectionMoviePage->setVisible(true);
        return;
    }
}

void MainWindow::on_MenuListLikedPage_itemClicked(QListWidgetItem *item) {
    if (item->text() == "Back" || item->text() == "Liked") {
        ui->MenuListLikedPage->setFixedWidth(0);
        ui->MenuButtonLikedPage->setVisible(true);
        return;
    }

    if (item->text() == "Search") {
        ui->PageSwitcher->setCurrentIndex(SEARCH_PAGE_INDEX);
        ui->MenuListLikedPage->setFixedWidth(0);
        ui->MenuListSearchPage->setFixedWidth(0);
        ui->MenuButtonSearchPage->setVisible(true);
        return;
    }

    if (item->text() == "Autoselection Movie") {
        ui->PageSwitcher->setCurrentIndex(AUTOSELECTION_MOVIE_PAGE_INDEX);
        ui->MenuListLikedPage->setFixedWidth(0);
        ui->MenuListAutoselectionMoviePage->setFixedWidth(0);
        ui->MenuButtonAutoselectionMoviePage->setVisible(true);
        return;
    }

    if (item->text() == "Tops") {
        ui->PageSwitcher->setCurrentIndex(TOPS_PAGE_INDEX);
        ui->MenuListLikedPage->setFixedWidth(0);
        ui->MenuListTopsPage->setFixedWidth(0);
        ui->MenuButtonTopsPage->setVisible(true);
        return;
    }
}

void MainWindow::on_FiltersButtonSearchPage_clicked() {
    filters_window->show();

    connect(filters_window, &FiltersWindow::filters_applied,
            this, &MainWindow::get_filters);
}

void MainWindow::get_filters(const QString &genre, const QString &age_limit, const QString &rating, const QString &year,
                             const QString &runtime) {
    genre_filter = genre;
    age_limit_filter = age_limit;
    rating_filter = rating;
    year_filter = year;
    runtime_filter = runtime;

    is_filter_apply = true;

    using_search_enging();
}

void
MainWindow::apply_filters() {

    auto compositeFilter = new CompositeFilter;
    if (genre_filter != "Любой жанр")
        compositeFilter->addFilter(new GenreFilter(genre_filter.toStdString()));
    if (age_limit_filter != "Любой возраст")
        compositeFilter->addFilter(new AgeLimitFilter(age_limit_filter.toStdString()));
    if (rating_filter == "Выше")
        compositeFilter->addFilter((new RatingFilter(true)));
    if (rating_filter == "Ниже")
        compositeFilter->addFilter((new RatingFilter(false)));
    if (runtime_filter == "Длиннее")
        compositeFilter->addFilter(new RuntimeFilter(true));
    if (runtime_filter == "Короче")
        compositeFilter->addFilter(new RuntimeFilter(false));
    if (year_filter == "Новые")
        compositeFilter->addFilter(new YearFilter(true));
    if (year_filter == "Старые")
        compositeFilter->addFilter(new YearFilter(false));

    MyVector<Movie> temp_movies_for_search_list;
    temp_movies_for_search_list.fromStdVector(movies_for_search_list);
    movies_for_search_list = compositeFilter->apply(temp_movies_for_search_list).toStdVector();
}

void MainWindow::using_search_enging() {
    ui->MoviesListSearchPage->clear();
    if (ui->SearchFieldSearchPage->text().toStdString().length() < precurrent_length_text_search_field)
        movies_for_search_list = search_engine->search_by_fragment(ui->SearchFieldSearchPage->text().toStdString(),
                                                                   movies_for_search_list, false, is_filter_apply);
    else
        movies_for_search_list = search_engine->search_by_fragment(ui->SearchFieldSearchPage->text().toStdString(),
                                                                   movies_for_search_list, true, is_filter_apply);

    if (is_filter_apply)
        apply_filters();

    for (auto& movie: movies_for_search_list) {
        add_movie_card_search_page(QString::fromStdString(movie.get_title()), QString::fromStdString(movie.get_genre()),
                       QString::fromStdString(std::to_string(movie.get_rating())),
                       QString::fromStdString(std::to_string(movie.get_release_year())),
                       QString::fromStdString(movie.get_age_limit()), QString::fromStdString(movie.get_description()),
                       movie.get_id());
    }
}

void MainWindow::add_movie_card_search_page(const QString &title, const QString &genre, const QString &rating,
                                      const QString &release_year, const QString &age_limit, const QString &description,
                                      int id) {
    auto movie_card = new MovieCard();

    bool is_liked = false;
    for (auto& like_movie: liked_movies->get_liked_movies(current_user->get_id())) {
        if (like_movie.get_id() == id) {
            is_liked = true;
            break;
        }
    }

    movie_card->set_movie_card_data(title, genre, rating, release_year, age_limit, description, id, is_liked);

    auto item = new QListWidgetItem(ui->MoviesListSearchPage);
    item->setSizeHint(QSize(440, 127));
    ui->MoviesListSearchPage->addItem(item);
    ui->MoviesListSearchPage->setItemWidget(item, movie_card);

    connect(movie_card->getViewDetailsButton(), &QPushButton::clicked,
            movie_card->getMovieCardInfo(), &MovieCardInfo::show);

    connect(movie_card->getMovieCardInfo(), &MovieCardInfo::prepare_to_add_liked_movie,
            this, &MainWindow::add_liked_movie);

    connect(movie_card->getMovieCardInfo(), &MovieCardInfo::prepare_to_del_liked_movie,
            this, &MainWindow::delete_liked_movie);
}

void MainWindow::add_liked_movie(int movie_id) {
    bool is_exist = false;
    for (auto& liked_movie: liked_movies->get_liked_movies(current_user->get_id())) {
        if (movie_id == liked_movie.get_id()) {
            is_exist = true;
            break;
        }
    }
    if (!is_exist)
        liked_movies->add_liked_movie(current_user->get_id(), movie_id, movies_repository->get_movies());
    show_liked_movies();
}

void MainWindow::delete_liked_movie(int movie_id) {
    liked_movies->delete_liked_movie(current_user->get_id(), movie_id);
    show_liked_movies();
}

void MainWindow::add_movie_card_liked(const QString &title, const QString &genre, const QString &rating,
                                      const QString &release_year, const QString &age_limit, const QString &description,
                                      int id) {
    auto movie_card = new MovieCard();

    bool is_liked = false;
    for (auto& like_movie: liked_movies->get_liked_movies(current_user->get_id())) {
        if (like_movie.get_id() == id) {
            is_liked = true;
            break;
        }
    }
    movie_card->set_movie_card_data(title, genre, rating, release_year, age_limit, description, id, is_liked);

    auto item = new QListWidgetItem(ui->MoviesListLikedPage);
    item->setSizeHint(QSize(440, 127));
    ui->MoviesListLikedPage->addItem(item);
    ui->MoviesListLikedPage->setItemWidget(item, movie_card);

    connect(movie_card->getViewDetailsButton(), &QPushButton::clicked,
            movie_card->getMovieCardInfo(), &MainWindow::show);

    connect(movie_card->getMovieCardInfo(), &MovieCardInfo::prepare_to_add_liked_movie,
            this, &MainWindow::add_liked_movie);

    connect(movie_card->getMovieCardInfo(), &MovieCardInfo::prepare_to_del_liked_movie,
           this, &MainWindow::delete_liked_movie);
}

void MainWindow::show_liked_movies() {
    ui->MoviesListLikedPage->clear();
    for (auto& liked_movie: liked_movies->get_liked_movies(current_user->get_id())) {
        add_movie_card_liked(QString::fromStdString(liked_movie.get_title()), QString::fromStdString(liked_movie.get_genre()), QString::fromStdString(std::to_string(liked_movie.get_rating())),
                             QString::fromStdString(std::to_string(liked_movie.get_release_year())), QString::fromStdString(liked_movie.get_age_limit()), QString::fromStdString(liked_movie.get_description()),
                             liked_movie.get_id());
    }
}

void MainWindow::on_LoadToFileButton_clicked() {
    filters_window_json->show();

    connect(filters_window_json, &FiltersWindow::filters_applied,
            this, &MainWindow::apply_filters_json);
}

void MainWindow::apply_filters_json(const QString &genre, const QString &age_limit, const QString &rating,
                                    const QString &year, const QString &runtime) {
    auto compositeFilter = new CompositeFilter;
    if (genre_filter != "Любой жанр")
        compositeFilter->addFilter(new GenreFilter(genre_filter.toStdString()));
    if (age_limit_filter != "Любой возраст")
        compositeFilter->addFilter(new AgeLimitFilter(age_limit_filter.toStdString()));
    if (rating_filter == "Выше")
        compositeFilter->addFilter((new RatingFilter(true)));
    if (rating_filter == "Ниже")
        compositeFilter->addFilter((new RatingFilter(false)));
    if (runtime_filter == "Длиннее")
        compositeFilter->addFilter(new RuntimeFilter(true));
    if (runtime_filter == "Короче")
        compositeFilter->addFilter(new RuntimeFilter(false));
    if (year_filter == "Новые")
        compositeFilter->addFilter(new YearFilter(true));
    if (year_filter == "Старые")
        compositeFilter->addFilter(new YearFilter(false));

    liked_movies_for_json.fromStdVector(liked_movies->get_liked_movies(current_user->get_id()));
    liked_movies_for_json = compositeFilter->apply(liked_movies_for_json);

    for (auto& temp: liked_movies_for_json) {
        qDebug() << temp.get_rating();
    }

    QJsonArray json_array_to_load_data;

    json_array_to_load_data = json_movie_collection->prepare_json(liked_movies_for_json.toStdVector());
    json_movie_collection->export_to_json(json_array_to_load_data);
}

void MainWindow::add_movie_card_autoselection_favorites(const QString &title, const QString &genre, const QString &rating,
                                              const QString &release_year, const QString &age_limit,
                                              const QString &description, int id) {
    auto movie_card = new MovieCard();

    bool is_liked = false;
    for (auto& like_movie: liked_movies->get_liked_movies(current_user->get_id())) {
        if (like_movie.get_id() == id) {
            is_liked = true;
            break;
        }
    }
    movie_card->set_movie_card_data(title, genre, rating, release_year, age_limit, description, id, is_liked);

    auto item = new QListWidgetItem(ui->FavoritesAutoselectionMoviePage);
    item->setSizeHint(QSize(440, 127));
    ui->FavoritesAutoselectionMoviePage->addItem(item);
    ui->FavoritesAutoselectionMoviePage->setItemWidget(item, movie_card);

    connect(movie_card->getViewDetailsButton(), &QPushButton::clicked,
            movie_card->getMovieCardInfo(), &MovieCardInfo::show);

    connect(movie_card->getMovieCardInfo(), &MovieCardInfo::prepare_to_add_liked_movie,
            this, &MainWindow::add_liked_movie);

    connect(movie_card->getMovieCardInfo(), &MovieCardInfo::prepare_to_del_liked_movie,
            this, &MainWindow::delete_liked_movie);
}

void MainWindow::add_movie_card_autoselection_random(const QString &title, const QString &genre, const QString &rating,
                                                     const QString &release_year, const QString &age_limit,
                                                     const QString &description, int id) {

    auto movie_card = new MovieCard();

    bool is_liked = false;
    for (auto& like_movie: liked_movies->get_liked_movies(current_user->get_id())) {
        if (like_movie.get_id() == id) {
            is_liked = true;
            break;
        }
    }
    movie_card->set_movie_card_data(title, genre, rating, release_year, age_limit, description, id, is_liked);

    auto item = new QListWidgetItem(ui->RandomAutoselectionMoviePage);
    item->setSizeHint(QSize(440, 127));
    ui->RandomAutoselectionMoviePage->addItem(item);
    ui->RandomAutoselectionMoviePage->setItemWidget(item, movie_card);

    connect(movie_card->getViewDetailsButton(), &QPushButton::clicked,
            movie_card->getMovieCardInfo(), &MovieCardInfo::show);

    connect(movie_card->getMovieCardInfo(), &MovieCardInfo::prepare_to_add_liked_movie,
            this, &MainWindow::add_liked_movie);

    connect(movie_card->getMovieCardInfo(), &MovieCardInfo::prepare_to_del_liked_movie,
            this, &MainWindow::delete_liked_movie);
}

void MainWindow::on_FiltersButtonAutoselectionMoviePage_clicked() {
    filters_window_autoselection->show();

    connect(filters_window_autoselection, &FiltersWindow::filters_applied,
            this, &MainWindow::get_filters_autoselection);

    connect(filters_window_autoselection, &FiltersWindow::filters_applied,
                this, &MainWindow::recommend_movies_method);

    ui->ErrorAutoselectionMoviePage->setVisible(false);
}

void MainWindow::on_AutoselectionButtonAutoselectionMoviePage_clicked() {
    recommend_movies_method(genre_filter_autoselection, age_limit_filter_autoselection, rating_filter,
                            year_filter_autoselection, runtime_filter_autoselection);
    ui->ErrorAutoselectionMoviePage->setVisible(false);
}

void MainWindow::get_filters_autoselection(const QString &genre, const QString &age_limit, const QString &rating,
                                            const QString &year, const QString &runtime) {
    genre_filter_autoselection = genre;
    age_limit_filter_autoselection = age_limit;
    rating_filter_autoselection = rating;
    year_filter_autoselection = year;
    runtime_filter_autoselection = runtime;
}


void MainWindow::recommend_movies_method(const QString &genre, const QString &age_limit, const QString &rating,
                                         const QString &year, const QString &runtime) {

    ui->FavoritesAutoselectionMoviePage->clear();
    ui->RandomAutoselectionMoviePage->clear();

    std::vector<Movie> recommend_movies;
    try {
        recommend_movies = recommend->recommendMovies(liked_movies->get_liked_movies(current_user->get_id()),
                                                      genre.toStdString(), age_limit.toStdString(),
                                                      rating.toStdString(), runtime.toStdString(), year.toStdString());

        for (int i = 0; i < recommend_movies.size() - 2; ++i)
            add_movie_card_autoselection_favorites(QString::fromStdString(recommend_movies[i].get_title()),
                                                   QString::fromStdString(recommend_movies[i].get_genre()),
                                                   QString::fromStdString(std::to_string(recommend_movies[i].get_rating())),
                                                   QString::fromStdString(std::to_string(recommend_movies[i].get_release_year())),
                                                   QString::fromStdString(recommend_movies[i].get_age_limit()),
                                                   QString::fromStdString(recommend_movies[i].get_description()),
                                                   recommend_movies[i].get_id());

        for (int i = recommend_movies.size() - 2; i < recommend_movies.size(); ++i)
            add_movie_card_autoselection_random(QString::fromStdString(recommend_movies[i].get_title()),
                                                QString::fromStdString(recommend_movies[i].get_genre()),
                                                QString::fromStdString(std::to_string(recommend_movies[i].get_rating())),
                                                QString::fromStdString(std::to_string(recommend_movies[i].get_release_year())),
                                                QString::fromStdString(recommend_movies[i].get_age_limit()),
                                                QString::fromStdString(recommend_movies[i].get_description()),
                                                recommend_movies[i].get_id());
    }
    catch (std::runtime_error& e) {
        ui->ErrorAutoselectionMoviePage->setText("остальные  фильмы вы уже добавили в понравившиеся");
        ui->ErrorAutoselectionMoviePage->setVisible(true);
    }
    catch (std::bad_alloc& e) {
        ui->ErrorAutoselectionMoviePage->setText("остальные  фильмы вы уже добавили в понравившиеся");
        ui->ErrorAutoselectionMoviePage->setVisible(true);
    }
}

void MainWindow::get_top_kinopoisk() {
    std::vector<Movie> temp_movies = parser->fetch_movies(movies_repository->get_movies());

    for (const auto& movie: temp_movies)
        add_movie_card_top(QString::fromStdString(movie.get_title()),
                                            QString::fromStdString(movie.get_genre()),
                                            QString::fromStdString(std::to_string(movie.get_rating())),
                                            QString::fromStdString(std::to_string(movie.get_release_year())),
                                            QString::fromStdString(movie.get_age_limit()),
                                            QString::fromStdString(movie.get_description()),
                                            movie.get_id());
}

void MainWindow::add_movie_card_top(const QString &title, const QString &genre, const QString &rating,
                                const QString &release_year, const QString &age_limit, const QString &description,
                                int id) {
    auto movie_card = new MovieCard();

    bool is_liked = false;
    for (auto& like_movie: liked_movies->get_liked_movies(current_user->get_id())) {
        if (like_movie.get_id() == id) {
            is_liked = true;
            break;
        }
    }
    movie_card->set_movie_card_data(title, genre, rating, release_year, age_limit, description, id, is_liked);

    auto item = new QListWidgetItem(ui->TopMoviesListTopsPage);
    item->setSizeHint(QSize(440, 127));
    ui->TopMoviesListTopsPage->addItem(item);
    ui->TopMoviesListTopsPage->setItemWidget(item, movie_card);

    connect(movie_card->getViewDetailsButton(), &QPushButton::clicked,
            movie_card->getMovieCardInfo(), &MainWindow::show);

    connect(movie_card->getMovieCardInfo(), &MovieCardInfo::prepare_to_add_liked_movie,
            this, &MainWindow::add_liked_movie);

    connect(movie_card->getMovieCardInfo(), &MovieCardInfo::prepare_to_del_liked_movie,
            this, &MainWindow::delete_liked_movie);
}



