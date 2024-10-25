//
// Created by vova3 on 19.10.2024.
//

#ifndef LABS_2_COURS_DBMANAGER_H
#define LABS_2_COURS_DBMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include "../models/Movie.h"
#include "../../SQLiteLibrary/sqlite3.h"

template<typename T>
class DBManager {
protected:
    sqlite3 *db;
    std::string db_name;  // если не используется нигде кроме конструктора - убрать

public:
    explicit DBManager(std::string &db_name) : db_name(db_name), db(nullptr) {}

    virtual ~DBManager() = default;

    virtual void create_table() = 0;

    virtual std::vector<T> load_data_from_DB() = 0;

    virtual void save_data_to_DB(std::vector<T> data) = 0;
};

#endif //LABS_2_COURS_DBMANAGER_H
