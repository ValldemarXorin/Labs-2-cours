//
// Created by vova3 on 21.10.2024.
//
#include "../../headers/database/MoviesDBManager.h"
#include "../../headers/map_requests.h"
#include "../../headers/models/Movie.h"

MoviesDBManager::MoviesDBManager(std::string& db_name) : DBManager<Movie>(db_name) {
    if (sqlite3_open(db_name.c_str(), &db)) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
    }
    create_table();
}

MoviesDBManager::~MoviesDBManager() { // следить за тем, чтобы перед деструктором вызывался метод сохранения в бд данных
    if (db) {
        sqlite3_close(db);
    }
}

void MoviesDBManager::create_table() {
    char *errMsg;
    if (sqlite3_exec(db, sql_requests[Movies_create_table].c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

std::vector<Movie> MoviesDBManager::load_data_from_DB() {
    std::vector<Movie> movies;
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql_requests[Movies_select].c_str(), -1, &stmt, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string title = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string short_description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string time = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        std::string age_limit = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        int year = sqlite3_column_int(stmt, 5);
        movies.emplace_back(title, short_description, time, age_limit, year); // Добавление фильма в вектор
    }
    sqlite3_finalize(stmt);

    return movies;
}

void MoviesDBManager::save_data_to_DB(std::vector<Movie> movies) {
    sqlite3_exec(db, sql_requests[Movies_delete].c_str(), nullptr, nullptr, nullptr);
    sqlite3_stmt *stmt;

    for (const auto& movie : movies) {
        sqlite3_prepare_v2(db, sql_requests[Movies_save].c_str(), -1, &stmt, nullptr);
        sqlite3_bind_text(stmt, 1, movie.get_title().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, movie.get_short_description().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 3, movie.get_time().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 4, movie.get_age_limit().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(stmt, 5, movie.get_year());
        sqlite3_step(stmt);
        sqlite3_reset(stmt);
    }
    sqlite3_finalize(stmt);
}

//MoviesDBManager* MoviesDBManager::get_instance() {
//    std::string db_name = "MovieDatabase.sqlite";
//    if (MoviesDBManager::instance == nullptr)
//        MoviesDBManager::instance = new MoviesDBManager(db_name);
//    return MoviesDBManager::instance;
//}
