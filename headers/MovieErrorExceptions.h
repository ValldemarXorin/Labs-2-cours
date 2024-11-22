//
// Created by vova3 on 23.10.2024.
//

#ifndef LABS_2_COURS_ERROREXCEPTIONS_H
#define LABS_2_COURS_ERROREXCEPTIONS_H
#include <iostream>
#include <regex>

class MovieErrorExceptions {
public:
    bool validate_time(const std::string& time) const;
    bool validate_age_limit(const std::string& age_limit) const;
    bool validate_year(int year) const;
};
#endif //LABS_2_COURS_ERROREXCEPTIONS_H
