//
// Created by vova3 on 12.12.2024.
//

#ifndef LABS_2_COURS_JSONMOVIECOLLECTION_H
#define LABS_2_COURS_JSONMOVIECOLLECTION_H
#include <vector>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDebug>
#include "models/Movie.h"


class JSONMovieCollection {
    QString filename;
public:

    JSONMovieCollection(QString filename);

    QJsonArray prepare_json(const std::vector<Movie>& filtered_movies);

    void export_to_json(QJsonArray json_array);
};
#endif //LABS_2_COURS_JSONMOVIECOLLECTION_H
