//
// Created by vova3 on 30.10.2024.
//

#ifndef LABS_2_COURS_USERSDBMANAGER_H
#define LABS_2_COURS_USERSDBMANAGER_H

#include "DBManager.h"
#include "../auth_models/User.h"
#include "../../SQLiteLibrary/sqlite3.h"


class UsersDBManager : public DBManager<User> {
public:
    explicit UsersDBManager(const std::string& db_name);

    ~UsersDBManager() override;

    void create_table() override;

    std::vector<User> load_data_from_DB() override;

    void save_data_to_DB(std::vector<User> users) override;
};
#endif //LABS_2_COURS_USERSDBMANAGER_H
