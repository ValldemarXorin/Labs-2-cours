//
// Created by vova3 on 06.10.2024.
//

#include "../headers/MovieDatabase.h"
#include "../SQLiteLibrary/sqlite3.h"
#include <algorithm>

MovieDatabase::MovieDatabase(const std::string &dbName) : dbName(dbName) {
    if (sqlite3_open(dbName.c_str(), &db)) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
    }
    createTable();
    loadMoviesFromDB();
}

MovieDatabase::~MovieDatabase() {
    saveMoviesToDB();
    if (db) {
        sqlite3_close(db);
    }
}

void MovieDatabase::createTable() {
    const char *sql = "CREATE TABLE IF NOT EXISTS movies ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "title VARCHAR(50), "
                      "year INTEGER, "
                      "genre VARCHAR(30), "
                      "director VARCHAR(50), "
                      "rating NUMERIC(3, 1)"
                      ");";
    char *errMsg;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

void MovieDatabase::addMovie(const Movie &movie) {
    movies.push_back(movie); // Добавление фильма в вектор
}

void MovieDatabase::loadMoviesFromDB() {
    const char *sql = "SELECT title, year, genre, director, rating FROM movies;";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string title = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        int year = sqlite3_column_int(stmt, 1);
        std::string genre = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string director = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        auto rating = static_cast<float> (sqlite3_column_double(stmt, 4));  // записывает в таблицу movie в колонку rating большую точность нежели нужна
        movies.emplace_back(title, year, genre, director, rating); // Добавление фильма в вектор
    }

    sqlite3_finalize(stmt);
}

void MovieDatabase::saveMoviesToDB() {
    const char *deleteSql = "DELETE FROM movies;";
    sqlite3_exec(db, deleteSql, nullptr, nullptr, nullptr);

    for (const auto& movie : movies) {
        const char *sql = "INSERT INTO movies (title, year, genre, director, rating) VALUES (?, ?, ?, ?, ?);";
        sqlite3_stmt *stmt;
        sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        sqlite3_bind_text(stmt, 1, movie.getTitle().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, movie.getYear());
        sqlite3_bind_text(stmt, 3, movie.getGenre().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, movie.getDirector().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_double(stmt, 5, movie.getRating());
        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }
}

const std::vector<Movie>& MovieDatabase::getMovies() const {
    return movies; // Возвращение вектора фильмов
}

void MovieDatabase::findMovieByTitle(std::string_view  title) const {
    for (const auto& movie : movies) {
        if (movie.getTitle() == title) {
            movie.display(); // Используем обычную функцию для отображения
            return;
        }
    }
    std::cout << "Movie not found." << std::endl;
}

void MovieDatabase::updateMovie(const Movie &movie, int id) {
    if (id >= 0 && id < movies.size()) {
        movies[id] = movie; // Обновление фильма по индексу
    }
}

void MovieDatabase::deleteMovie(int id) { // Удаление по ID
    if (id >= 0 && id < movies.size()) {
        movies.erase(movies.begin() + id); // Удаление фильма из вектора
    }
}

void MovieDatabase::deleteMovie(const std::string &title) { // Удаление по заголовку
    auto it = std::remove_if(movies.begin(), movies.end(), [&title](const Movie &movie) {
        return movie.getTitle() == title;
    });
    movies.erase(it, movies.end()); // Удаление фильмов из вектора
}