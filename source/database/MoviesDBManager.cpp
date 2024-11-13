//
// Created by vova3 on 21.10.2024.
//
#include "../../headers/database/MoviesDBManager.h"
#include "../../headers/map_requests.h"
#include "../../headers/models/Movie.h"

MoviesDBManager::MoviesDBManager(const std::string& db_name) : DBManager<Movie>(db_name) {
    if (sqlite3_open(db_name.c_str(), &(DBManager::db))) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(DBManager::db) << std::endl;
        DBManager::db = nullptr;
    }
    MoviesDBManager::create_table();
}

MoviesDBManager::~MoviesDBManager() { // следить за тем, чтобы перед деструктором вызывался метод сохранения в бд данных
    if (DBManager::db) {
        sqlite3_close(DBManager::db);
    }
}

void MoviesDBManager::create_table() {
    char *errMsg;
    if (sqlite3_exec(DBManager::db, map_sql::sql_requests[map_sql::Movies_create_table].c_str(),
                     nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

std::vector<Movie> MoviesDBManager::load_data_from_DB() {
    std::vector<Movie> movies;
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(DBManager::db, map_sql::sql_requests[map_sql::Movies_select].c_str(),
                       -1, &stmt, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string title = reinterpret_cast<const char*>(sqlite3_column_text(stmt, TITLE));
        std::string description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, DESCRIPTION));
        std::string genre = reinterpret_cast<const char*>(sqlite3_column_text(stmt, GENRE));
        int realease_year = sqlite3_column_int(stmt, REALEASE_YEAR);
        std::string runtime = reinterpret_cast<const char*>(sqlite3_column_text(stmt, RUNTIME));
        float rating = sqlite3_column_double(stmt, RATING);
        std::string age_limit = reinterpret_cast<const char*>(sqlite3_column_text(stmt, AGE_LIMIT));
        int link_id = sqlite3_column_int(stmt, LINK_ID);

        movies.emplace_back(title, description, genre, realease_year, runtime, rating, link_id,
                            age_limit); // Добавление фильма в вектор
    }
    sqlite3_finalize(stmt);

    return movies;
}

void MoviesDBManager::save_data_to_DB(std::vector<Movie> movies) {
    sqlite3_exec(DBManager::db, map_sql::sql_requests[map_sql::Movies_delete].c_str(), nullptr, nullptr, nullptr);
    sqlite3_stmt *stmt = nullptr; // убрать nullptr если надо будет

    for (const auto& movie : movies) {
        sqlite3_prepare_v2(DBManager::db, map_sql::sql_requests[map_sql::Movies_save].c_str(),
                           -1, &stmt, nullptr);
        sqlite3_bind_text(stmt, TITLE, movie.get_title().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, DESCRIPTION, movie.get_description().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, GENRE, movie.get_genre().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt, REALEASE_YEAR, movie.get_release_year());
        sqlite3_bind_text(stmt, RUNTIME, movie.get_runtime().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_double(stmt, RATING, movie.get_rating());
        sqlite3_bind_text(stmt, AGE_LIMIT, movie.get_age_limit().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt, LINK_ID, movie.get_link_id());
        sqlite3_step(stmt);
        sqlite3_reset(stmt);
    }
    sqlite3_finalize(stmt);
}
