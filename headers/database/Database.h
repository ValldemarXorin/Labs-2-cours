//
// Created by vova3 on 17.11.2024.
//

#ifndef LABS_2_COURS_DATABASE_H
#define LABS_2_COURS_DATABASE_H

#include "../../SQLiteLibrary/sqlite3.h"
//#include "../map_requests.h"
#include <string>
#include <stdexcept>
#include <string_view>

class Database {
    sqlite3* db;
    static  Database* instance;

public:
    explicit Database(std::string& db_name);

    ~Database();

    static Database* get_instance(std::string& db_name);

    sqlite3* get_db() const;
};
#endif //LABS_2_COURS_DATABASE_H
