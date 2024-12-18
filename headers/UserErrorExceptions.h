//
// Created by vova3 on 29.10.2024.
//

#ifndef LABS_2_COURS_USERERROREXCEPTIONS_H
#define LABS_2_COURS_USERERROREXCEPTIONS_H

#include "auth_models/User.h"
#include <string>
#include <regex>
#include <stdexcept>
#include <vector>

class UserErrorExceptions {
public:

    void email_is_valid(const std::string& email) const;

    void password_is_vaild(const std::string& password) const;

    bool password_administrator_is_valid(const std::string& password_administrator) const;

    void email_exist(const std::string& email, const std::vector<User>& all_users) const;

    void user_exist(const std::string& email, const std::string& password, const std::string& role,
                    const std::vector<User>& all_users) const;
};
#endif //LABS_2_COURS_USERERROREXCEPTIONS_H
