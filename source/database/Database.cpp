//
// Created by vova3 on 17.11.2024.
//
#include "../../headers/database/Database.h"

Database* Database::instance = nullptr;

Database::Database(std::string& db_name) {
    if (sqlite3_open(db_name.c_str(), &db) != SQLITE_OK)
        throw std::runtime_error("Cannot open database: " + std::string(sqlite3_errmsg(db)));
}

Database::~Database() {
    if (db)
        sqlite3_close(db);
}

Database* Database::get_instance(std::string& db_name) {
    if (!instance)
        instance = new Database(db_name);
    return instance;
}

sqlite3* Database::get_db() const {
    return db;
}