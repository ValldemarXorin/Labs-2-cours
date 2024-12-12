
#include "../headers/UserErrorExceptions.h"

void UserErrorExceptions::email_is_valid(const std::string &email) const {
    std::regex valid_email(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (!std::regex_match(email, valid_email))
        throw std::invalid_argument("Error: check email and password.");
}

void UserErrorExceptions::password_is_vaild(const std::string &password) const {
    std::regex valid_password(R"(^[a-zA-Z0-9_$&%#-]{8,30}$)");
    if (!std::regex_match(password, valid_password))
        throw std::invalid_argument("Error: check email and password.");
}

void UserErrorExceptions::email_exist(const std::string& email, const std::vector<User>& all_users) const {
    for (const User& user: all_users) {
        if (user.get_email() == email)
            throw std::invalid_argument("User already exist.");
    }
}

void
UserErrorExceptions::user_exist(const std::string &email, const std::string &password, const std::string &role,
                                const std::vector<User>& all_users) const {
    for (const User& user: all_users) {
        if (user.get_email() == email && user.get_password() == password &&
            user.get_role() == role)
            return;
    }
    throw std::invalid_argument("User does not exist.");
}