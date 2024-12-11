//
// Created by vova3 on 24.11.2024.
//

#ifndef LABS_2_COURS_MOVIECARDINFO_H
#define LABS_2_COURS_MOVIECARDINFO_H

#include <QWidget>
#include <QToolButton>
#include "../models/Movie.h"
#include "../MyVector.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MovieCardInfo; }
QT_END_NAMESPACE

class MovieCardInfo : public QWidget {
Q_OBJECT

public:
    explicit MovieCardInfo(QWidget *parent = nullptr);

    ~MovieCardInfo() override;

    void SetIconLikeButton();

    void set_information(QString title, QString genre, QString rating, QString release_year, QString runtime,
                         QString age_limit, QString description, int id);

    void OnLikeButtonClicked();

    QToolButton* get_like_button();

    signals:
    void prepare_to_add_liked_movie(int movie_id_to_add);

private:
    Ui::MovieCardInfo *ui;
    int movie_id;
};


#endif //LABS_2_COURS_MOVIECARDINFO_H
