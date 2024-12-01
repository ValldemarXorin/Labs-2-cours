//
// Created by vova3 on 30.10.2024.
//

#ifndef LABS_2_COURS_IUSERSREPOSITORY_H
#define LABS_2_COURS_IUSERSREPOSITORY_H

#include "../auth_models/User.h"
#include "../database/UsersDBManager.h"
#include "../UserErrorExceptions.h"
#include <vector>

class IUserRepository : public UserErrorExceptions {
    std::vector<User> users;
    DBManager<User>* user_db_manager;

public:
    IUserRepository();

    ~IUserRepository();

    void add_user(const std::string& new_email, const std::string& new_password,
                  const std::string& new_role);

    void delete_user(const std::string& email, const std::string& password,
                     const std::string& role);

    bool user_exist(const std::string& email, const std::string& password,
                    const std::string& role) const;

    bool email_exist(const std::string& email);
};
#endif //LABS_2_COURS_IUSERSREPOSITORY_H
