//
// Created by vova3 on 27.10.2024.
//

#ifndef LABS_2_COURS_USERROLE_H
#define LABS_2_COURS_USERROLE_H
#include <string>
#include <string_view>

class UserRole {
protected:
    std::string email;
    std::string password;
    std::string role;

public:

    UserRole(std::string_view email, std::string_view password, std::string_view role)
            : email(email), password(password), role(role) {};

    virtual ~UserRole() = default;

};
#endif //LABS_2_COURS_USERROLE_H
