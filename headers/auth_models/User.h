//
// Created by vova3 on 28.10.2024.
//

#ifndef LABS_2_COURS_USER_H
#define LABS_2_COURS_USER_H

#include "UserRole.h"
#include "../UserErrorExceptions.h"
#include <string>
#include <string_view>

class User: public UserRole, public UserErrorExceptions {
public:
    User(std::string_view email, std::string_view password, std::string_view role);

    ~User() override = default;

    std::string get_email() const;

    std::string get_password() const;

    std::string get_role() const;

    void set_email(std::string& new_email);

    void set_password(std::string& new_password);

    void set_role(std::string_view new_role);

    bool operator==(const User& other) const;
};

#endif //LABS_2_COURS_USER_H
