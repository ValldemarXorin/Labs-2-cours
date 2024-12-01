//
// Created by vova3 on 21.11.2024.
//

#ifndef LABS_2_COURS_MOVIECARD_H
#define LABS_2_COURS_MOVIECARD_H

#include <QWidget>
#include "MovieCardInfo.h"
#include <QPushButton>



QT_BEGIN_NAMESPACE
namespace Ui { class MovieCard; }
QT_END_NAMESPACE

class MovieCard : public QWidget {
Q_OBJECT

public:
    explicit MovieCard(QWidget *parent = nullptr);

    MovieCard(const MovieCard& other) = default;

    ~MovieCard() override;

    void set_movie_card_data(const QString& title, const QString& genre,
                        const QString& rating, const QString& release_year, const QString& age_limit,
                        const QString& description);

    QPushButton* getViewDetailsButton();

    MovieCardInfo* getMovieCardInfo();

private:
    Ui::MovieCard *ui;
    MovieCardInfo* movie_card_info;
};


#endif //LABS_2_COURS_MOVIECARD_H
