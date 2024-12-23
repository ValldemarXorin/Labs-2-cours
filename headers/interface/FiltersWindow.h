//
// Created by vova3 on 28.11.2024.
//

#ifndef LABS_2_COURS_FILTERSWINDOW_H
#define LABS_2_COURS_FILTERSWINDOW_H

#include <QWidget>
#include <QScrollBar>
#include "MovieCard.h"
#include "../repositories/LikedRepository.h"
#include <string>


QT_BEGIN_NAMESPACE
namespace Ui { class FiltersWindow; }
QT_END_NAMESPACE

class FiltersWindow : public QWidget {
Q_OBJECT

public:
    explicit FiltersWindow(QWidget *parent = nullptr);

    ~FiltersWindow() override;

public slots:
    void onApplyButtonClicked();

    void closeEvent(QCloseEvent *event) override;

    void onPrepareButtonClicked();

    void add_movie_cards_json(std::vector<Movie> liked_movies, std::vector<Movie> json_movies);

    void add_liked_movie_prepare(int movie_id);

    void delete_liked_movie_prepare(int movie_id);

    void loadNextBatch(int batchSize = 5);

    signals:
    void filters_applied(const QString& genre, const QString& age_limit, const QString& rating,
                         const QString& year, const QString& runtime);

    void filters_window_close();

    void filters_prepare(const QString& genre, const QString& age_limit, const QString& rating,
                         const QString& year, const QString& runtime);

    void add_liked_movie(int movie_id);

    void delete_liked_movie(int movie_id);

private:
    Ui::FiltersWindow *ui;
    std::vector<Movie> liked_movies;
    std::vector<Movie> json_movies;
    int currentBatchIndex;
};


#endif //LABS_2_COURS_FILTERSWINDOW_H
