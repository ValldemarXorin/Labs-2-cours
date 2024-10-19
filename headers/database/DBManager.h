//
// Created by vova3 on 19.10.2024.
//

#ifndef LABS_2_COURS_DBMANAGER_H
#define LABS_2_COURS_DBMANAGER_H

#include <iostream>
#include <string>
#include "../map_requests.h"
#include "../../SQLiteLibrary/sqlite3.h"

class DBManager {
    sqlite3* db;
    std::string db_name;  // если не используется нигде кроме конструктора - убрать

    void CreateTable();
public:
    explicit DBManager(std::string db_name);
    ~DBManager();


};
#endif //LABS_2_COURS_DBMANAGER_H
