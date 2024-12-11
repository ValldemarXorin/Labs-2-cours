//
// Created by vova3 on 07.12.2024.
//

#include "../../headers/database/LikedDBManager.h"

void LikedDBManager::create_table() {
    char* errMsg;
    if (sqlite3_exec(Database::get_instance(db_name)->get_db(),
                     "CREATE TABLE IF NOT EXISTS Movies ("
                     "liked_id INT AUTOINCREMENT,"
                     "user_id INT,"
                     "movie_id INT"
                     ");",
                     nullptr, nullptr,&errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

std::vector<LikedMovie> LikedDBManager::load_data_from_DB() {
    std::vector<LikedMovie> liked_movies;
    sqlite3_stmt *stmt;
    std::string sql = "SELECT Liked.liked_id, Liked.user_id, Liked.movie_id, Movies.movie_id, Movies.title, "
                      "Movies.description, Movies.genre, Movies.release_year, Movies.runtime, "
                      "Movies.rating, Movies.age_limit, Movies.link_id "
                      "FROM Liked "
                      "JOIN Movies ON Movies.movie_id=Liked.movie_id";

    sqlite3_prepare_v2(Database::get_instance(db_name)->get_db(),
                       sql.c_str(),-1, &stmt,nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int liked_id = sqlite3_column_int(stmt, 0);
        int user_id = sqlite3_column_int(stmt, 1);
        int movie_id = sqlite3_column_int(stmt, 3);
        std::string title = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        std::string description = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        std::string genre = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
        int release_year = sqlite3_column_int(stmt, 7);
        std::string runtime = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8));
        float rating = sqlite3_column_double(stmt, 9);
        std::string age_limit = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 10));
        int link_id = sqlite3_column_int(stmt, 11);

        liked_movies.emplace_back(liked_id, user_id, Movie(movie_id, title, description, genre,
                                                           release_year, runtime, rating, link_id,
                                                           age_limit));
    }
    sqlite3_finalize(stmt);

    return liked_movies;
}

void LikedDBManager::save_data_to_DB(std::vector<LikedMovie> liked_movies) {
    sqlite3_stmt *stmt = nullptr; // убрать nullptr если надо будет

    sqlite3_exec(Database::get_instance(db_name)->get_db(),
                 "DELETE FROM Liked",
                 nullptr, nullptr, nullptr);

    for (const auto& liked_movie : liked_movies) {
        sqlite3_prepare_v2(Database::get_instance(db_name)->get_db(),
                           "INSERT INTO Liked (liked_id, user_id, movie_id)"
                           "VALUES (?, ?, ?)",
                           -1, &stmt, nullptr);

        sqlite3_bind_int(stmt, 1, liked_movie.get_liked_id());
        sqlite3_bind_int(stmt, 2 , liked_movie.get_user_id());
        sqlite3_bind_int(stmt, 3, liked_movie.get_movie().get_id());

        //sqlite3_step(stmt);
        int rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
            std::cerr << "Error: " << sqlite3_errmsg(Database::get_instance(db_name)->get_db()) << std::endl;
        }

        sqlite3_reset(stmt);
    }
    sqlite3_finalize(stmt);
}
