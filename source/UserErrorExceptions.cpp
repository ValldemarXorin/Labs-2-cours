//
// Created by vova3 on 30.10.2024.
//

#include "../headers/UserErrorExceptions.h"

bool UserErrorExceptions::email_is_valid(const std::string &email) const {
    std::regex valid_email(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return std::regex_match(email, valid_email);
}

bool UserErrorExceptions::password_is_vaild(const std::string &password) const {
    std::regex valid_password(R"(^[a-zA-Z0-9_$&%#-]{8,30}$)");
    return std::regex_match(password, valid_password);
}