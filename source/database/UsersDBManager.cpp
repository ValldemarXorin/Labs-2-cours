//
// Created by vova3 on 30.10.2024.
//

#include "../../headers/database/UsersDBManager.h"

UsersDBManager::UsersDBManager(): DBManager<User>() {
    UsersDBManager::create_table();
}


void UsersDBManager::create_table() {
    char *errMsg;
    if (sqlite3_exec(Database::get_instance(db_name)->get_db(),
                     "CREATE TABLE IF NOT EXISTS Users ("
                     "id INTEGER PRIMARY KEY,"
                     "email VARCHAR(254),"
                     "`password` VARCHAR(30),"
                     "role VARCHAR(10)"
                     ");",
                     nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

std::vector<User> UsersDBManager::load_data_from_DB() {
    std::vector<User> users;
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(Database::get_instance(db_name)->get_db(),
                       "SELECT * FROM Users",
                       -1,&stmt, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::string email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string password = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string role = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        users.emplace_back(email, password, role); // Добавление фильма в вектор
    }
    sqlite3_finalize(stmt);

    return users;
}

void UsersDBManager::save_data_to_DB(std::vector<User> users) {
    sqlite3_exec(Database::get_instance(db_name)->get_db(),
                 "DELETE FROM Users",
                 nullptr, nullptr, nullptr);
    sqlite3_stmt *stmt = nullptr;

    for (const auto& user : users) {
        sqlite3_prepare_v2(Database::get_instance(db_name)->get_db(),
                           "INSERT INTO Users (email, password, role) VALUES (?, ?, ?);",
                           -1, &stmt, nullptr);
        sqlite3_bind_text(stmt, 1, user.get_email().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 2, user.get_password().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(stmt, 3, user.get_role().c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_step(stmt);
        sqlite3_reset(stmt);
    }
    sqlite3_finalize(stmt);
}