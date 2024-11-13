//
// Created by vova3 on 29.10.2024.
//

#ifndef LABS_2_COURS_USERERROREXCEPTIONS_H
#define LABS_2_COURS_USERERROREXCEPTIONS_H

#include <string>
#include <regex>

class UserErrorExceptions {
public:

    bool email_is_valid(const std::string& email) const;

    bool password_is_vaild(const std::string& password) const;
};
#endif //LABS_2_COURS_USERERROREXCEPTIONS_H
