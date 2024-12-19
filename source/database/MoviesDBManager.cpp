//
// Created by vova3 on 21.10.2024.
//
#include "../../headers/database/MoviesDBManager.h"

MoviesDBManager::MoviesDBManager() : DBManager<Movie>() {
    MoviesDBManager::create_table();
}

void MoviesDBManager::create_table() {
    char *errMsg;
    if (sqlite3_exec(Database::get_instance(db_name)->get_db(),
                     "CREATE TABLE IF NOT EXISTS Movies ("
                     "id INT PRIMARY KEY,"
                     "title TEXT,"
                     "description TEXT,"
                     "genre TEXT,"
                     "release_year INTEGER,"
                     "runtime VARCHAR(8),"
                     "rating REAL,"
                     "age_limit TEXT,"
                     "poster_link  VARCHAR(255),"
                     "trailer_link  VARCHAR(255)"
                     ");",
                     nullptr, nullptr,&errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

std::vector<Movie> MoviesDBManager::load_data_from_DB() {
    std::vector<Movie> movies;
    sqlite3_stmt *stmt;

    sqlite3_prepare_v2(Database::get_instance(db_name)->get_db(),
                       "SELECT * FROM Movies",
                       -1, &stmt,nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        std::string title = reinterpret_cast<const char*>(sqlite3_column_text(stmt, TITLE));
        std::string description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, DESCRIPTION));
        std::string genre = reinterpret_cast<const char*>(sqlite3_column_text(stmt, GENRE));
        int release_year = sqlite3_column_int(stmt, REALEASE_YEAR);
        std::string runtime = reinterpret_cast<const char*>(sqlite3_column_text(stmt, RUNTIME));
        float rating = sqlite3_column_double(stmt, RATING);
        rating = std::round(rating * 10.0f) / 10.0f;
        std::string age_limit = reinterpret_cast<const char*>(sqlite3_column_text(stmt, AGE_LIMIT));
        std::string poster_link = reinterpret_cast<const char*>(sqlite3_column_text(stmt, POSTER_LINK));
        std::string trailer_link = reinterpret_cast<const char*>(sqlite3_column_text(stmt, TRAILER_LINK));

        movies.emplace_back(id, title, description, genre, release_year, runtime, rating,
                            age_limit, poster_link, trailer_link); // Добавление фильма в вектор
    }
    sqlite3_finalize(stmt);

    return movies;
}

void MoviesDBManager::save_data_to_DB(std::vector<Movie> movies) {
    sqlite3_stmt *stmt = nullptr; // убрать nullptr если надо будет

    sqlite3_exec(Database::get_instance(db_name)->get_db(),
                 "DELETE FROM Movies",
                 nullptr, nullptr, nullptr);

    for (const auto& movie : movies) {
        sqlite3_prepare_v2(Database::get_instance(db_name)->get_db(),
                           "INSERT INTO Movies (movie_id, title, description, genre, release_year, runtime, rating, age_limit, poster_link, trailer_link) "
                           "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)",
                           -1, &stmt, nullptr);

        sqlite3_bind_int(stmt, 1, movie.get_id());
        sqlite3_bind_text(stmt, TITLE + 1, movie.get_title().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, DESCRIPTION + 1, movie.get_description().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, GENRE + 1, movie.get_genre().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt, REALEASE_YEAR + 1, movie.get_release_year());
        sqlite3_bind_text(stmt, RUNTIME + 1, movie.get_runtime().c_str(), -1, SQLITE_TRANSIENT);

        int rounded_rating = movie.get_rating() * 10;
        sqlite3_bind_double(stmt, RATING + 1, rounded_rating / 10.0);
        sqlite3_bind_text(stmt, AGE_LIMIT + 1, movie.get_age_limit().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, POSTER_LINK + 1, movie.get_poster_link().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, TRAILER_LINK + 1, movie.get_trailer_link().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_step(stmt);
        sqlite3_reset(stmt);
    }
    sqlite3_finalize(stmt);
}
