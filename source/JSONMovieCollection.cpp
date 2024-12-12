//
// Created by vova3 on 12.12.2024.
//

#include "../headers/JSONMovieCollection.h"

JSONMovieCollection::JSONMovieCollection(QString filename) : filename(filename) {}

QJsonArray JSONMovieCollection::prepare_json(const std::vector<Movie> &filtered_movies) {
    QJsonArray jsonArray;
    for (const Movie& movie : filtered_movies) {
        QJsonObject jsonObject;
        jsonObject["title"] = QString::fromStdString(movie.get_title());
        jsonObject["description"] = QString::fromStdString(movie.get_description());
        jsonObject["genre"] = QString::fromStdString(movie.get_genre());
        jsonObject["release year"] = QString::fromStdString(std::to_string(movie.get_release_year()));
        jsonObject["runtime"] = QString::fromStdString(movie.get_runtime());
        jsonObject["rating"] = QString::fromStdString(std::to_string(movie.get_rating()));
        jsonObject["age_limit"] = QString::fromStdString(movie.get_age_limit());
        jsonArray.append(jsonObject);
    }
    return jsonArray;
}

void JSONMovieCollection::export_to_json(QJsonArray json_array) {
    QJsonDocument jsonDoc(json_array);
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(jsonDoc.toJson());
        file.close();
        qDebug() << "File written successfully to" << filename;
    } else {
        qWarning("Could not open file for writing");
    }
}