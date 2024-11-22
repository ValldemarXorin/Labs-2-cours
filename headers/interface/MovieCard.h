//
// Created by vova3 on 21.11.2024.
//

#ifndef LABS_2_COURS_MOVIECARD_H
#define LABS_2_COURS_MOVIECARD_H

#include <QWidget>


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
                        const QString& rating, const QString& release_year, const QString& age_limit);

private:
    Ui::MovieCard *ui;
};


#endif //LABS_2_COURS_MOVIECARD_H
