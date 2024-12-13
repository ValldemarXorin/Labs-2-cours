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
#include "FiltersWindow.h"
#include "MovieCard.h"
#include "MovieCardInfo.h"
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
                              const QString& description, int id);

    void add_movie_card_liked(const QString& title, const QString& genre,
                                    const QString& rating, const QString& release_year, const QString& age_limit,
                                    const QString& description, int id);

    void on_LoadToFileButton_clicked();

    void apply_filters_json(const QString& genre, const QString& age_limit, const QString& rating,
                            const QString& year, const QString& runtime);

private:
    Ui::MainWindow *ui;
    IUserRepository* users;
    IMoviesRepository* movies_repository;
    LikedRepository* liked_movies;
    SearchEngine* search_engine;
    FiltersWindow* filters_window {new FiltersWindow};
    FiltersWindow* filters_window_json {new FiltersWindow};
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
};


#endif //LABS_2_COURS_MAINWINDOW_H
