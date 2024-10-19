//
// Created by vova3 on 19.10.2024.
//
#include "../../headers/database/DBManager.h"

//DBManager::DBManager(std::string db_name): db_name(db_name) {
//    if (sqlite3_open(db_name.c_str(), &db)) {
//        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
//        db = nullptr;
//    }
//    createTable();
//    loadMoviesFromDB();
//}
//
//DBManager::~DBManager()  {
//    saveMoviesToDB();
//    if (db) {
//        sqlite3_close(db);
//    }
//}