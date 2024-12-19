//
// Created by vova3 on 20.10.2024.
//

#ifndef LABS_2_COURS_MAINWINDOW_H
#define LABS_2_COURS_MAINWINDOW_H

#include "../repositories/IUsersRepository.h"
#include "../repositories/IMoviesRepository.h"
#include "../repositories/LikedRepository.h"
#include "../search/search_engine.h"
#include "../search/CompositeFilters.h"
#include "../search/GenreFilter.h"
#include "../search/AgeLimitFilter.h"
#include "../search/RatingFilter.h"
#include "../search/YearFilter.h"
#include "../search/RuntimeFilter.h"
#include "../MyVector.h"
#include "../JSONMovieCollection.h"
#include "../MovieRecommender.h"
#include "../TopParser.h"
#include "FiltersWindow.h"
#include "MovieCard.h"
#include "MovieCardInfo.h"
#include "AdminWindow.h"
#include <windows.h>
#include <QMainWindow>
#include <QListView>
#include <QStandardItemModel>
#include <QPropertyAnimation>
#include <QListWidget>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(IMoviesRepository* movies_repository, IUserRepository* users, LikedRepository* liked_movies,
                        User* current_user, QWidget *parent = nullptr);

    ~MainWindow() override;

private slots:
    void on_MenuButtonAutoselectionMoviePage_clicked();

    void on_MenuButtonSearchPage_clicked();

    void on_MenuButtonLikedPage_clicked();

    void on_MenuButtonTopsPage_clicked();

    void on_MenuListAutoselectionMoviePage_itemClicked(QListWidgetItem *item);

    void on_MenuListSearchPage_itemClicked(QListWidgetItem *item);

    void on_MenuListLikedPage_itemClicked(QListWidgetItem *item);

    void on_MenuListTopsPage_itemClicked(QListWidgetItem *item);

    void on_FiltersButtonSearchPage_clicked();

    void show_liked_movies();

    void add_liked_movie(int movie_id);

    void delete_liked_movie(int movie_id);

    void get_filters(const QString& genre, const QString& age_limit, const QString& rating,
                     const QString& year, const QString& runtime);

    void apply_filters();

    void using_search_enging();

    void add_movie_card_search_page(const QString& title, const QString& genre,
                              const QString& rating, const QString& release_year, const QString& age_limit,
                              const QString& description, int id, const QString& poster_link, const QString& trailer_link,
                              const QString& runtime);

    void add_movie_card_liked(const QString& title, const QString& genre,
                                    const QString& rating, const QString& release_year, const QString& age_limit,
                                    const QString& description, const QString &runtime, const QString &poster_link,
                                    const QString &trailer_link, int id);

    void add_movie_card_autoselection_favorites(const QString& title, const QString& genre,
                                      const QString& rating, const QString& release_year, const QString& age_limit,
                                      const QString& description, const QString &runtime, const QString &poster_link,
                                      const QString &trailer_link, int id);

    void add_movie_card_autoselection_random(const QString& title, const QString& genre,
                                                const QString& rating, const QString& release_year, const QString& age_limit,
                                                const QString& description, const QString &runtime, const QString &poster_link,
                                                const QString &trailer_link, int id);

    void apply_filters_json(const QString& genre, const QString& age_limit, const QString& rating,
                            const QString& year, const QString& runtime);

    void on_AutoselectionButton_clicked();

    void on_LoadToFileButton_clicked();

    void on_FiltersButtonAutoselectionMoviePage_clicked();

    void recommend_movies_method(const QString& genre = "Genre", const QString& age_limit = "Age limit", const QString& rating = "Rating",
                                 const QString& year = "Year", const QString& runtime = "Runtime");

    void get_filters_autoselection(const QString& genre, const QString& age_limit, const QString& rating,
                                    const QString& year, const QString& runtime);

    void get_top_kinopoisk();

    void add_movie_card_top(const QString& title, const QString& genre,
                        const QString& rating, const QString& release_year, const QString& age_limit,
                        const QString& description, const QString &runtime, const QString &poster_link,
                        const QString &trailer_link, int id);

    void on_AdminButton_clicked();

private:
    Ui::MainWindow *ui;
    IUserRepository* users;
    IMoviesRepository* movies_repository;
    LikedRepository* liked_movies;
    SearchEngine* search_engine;
    FiltersWindow* filters_window {new FiltersWindow};
    FiltersWindow* filters_window_json {new FiltersWindow};
    FiltersWindow* filters_window_autoselection {new FiltersWindow};
    MyVector<Movie> liked_movies_for_json;
    User* current_user;
    int precurrent_length_text_search_field{0};
    std::vector<Movie> movies_for_search_list;
    bool is_filter_apply {false};
    enum pages_ingex {AUTOSELECTION_MOVIE_PAGE_INDEX, SEARCH_PAGE_INDEX,
            LIKED_PAGE_INDEX, TOPS_PAGE_INDEX};
    QString genre_filter;
    QString age_limit_filter;
    QString rating_filter;
    QString year_filter;
    QString runtime_filter;
    JSONMovieCollection* json_movie_collection;
    MovieRecommender* recommend;
    QString genre_filter_autoselection {"Любой жанр"};
    QString age_limit_filter_autoselection {"Любой возраст"};
    QString rating_filter_autoselection {"Любой рейтинг"};
    QString year_filter_autoselection {"Любой год"};
    QString runtime_filter_autoselection {"Любая длительность"};
    TopParser* parser {new TopParser};
    AdminWindow* admin_window;
};


#endif //LABS_2_COURS_MAINWINDOW_H
