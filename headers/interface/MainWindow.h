//
// Created by vova3 on 20.10.2024.
//

#ifndef LABS_2_COURS_MAINWINDOW_H
#define LABS_2_COURS_MAINWINDOW_H

#include "../repositories/IUsersRepository.h"
#include "../repositories/IMoviesRepository.h"
#include "../search/search_engine.h"
#include "../search/CompositeFilters.h"
#include "../search/GenreFilter.h"
#include "../search/AgeLimitFilter.h"
#include "MovieCard.h"
#include "MovieCardInfo.h"
#include <windows.h>
#include <QMainWindow>
#include <QListView>
#include <QStandardItemModel>
#include <QPropertyAnimation>
#include <QListWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(IMoviesRepository* movies_repository, IUserRepository* users,
                        QWidget *parent = nullptr);

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

    void using_search_enging();

    void add_movie_card(const QString& title, const QString& genre,
                              const QString& rating, const QString& release_year, const QString& age_limit);

private:
    Ui::MainWindow *ui;
    IUserRepository* users;
    IMoviesRepository* movies_repository;
    SearchEngine* search_engine;
    int precurrent_length_text_search_field{0};
    enum pages_ingex {AUTOSELECTION_MOVIE_PAGE_INDEX, SEARCH_PAGE_INDEX,
            LIKED_PAGE_INDEX, TOPS_PAGE_INDEX};
};


#endif //LABS_2_COURS_MAINWINDOW_H
