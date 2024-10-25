//
// Created by vova3 on 23.10.2024.
//

#ifndef LABS_2_COURS_ERROREXCEPTIONS_H
#define LABS_2_COURS_ERROREXCEPTIONS_H
#include <stdio.h>
#include <regex>

class MovieErrorExceptions {
public:
    void validate_time(const std::string& time);
    void validate_age_limit(const std::string& age_limit);
    void validate_year(int year);
};
#endif //LABS_2_COURS_ERROREXCEPTIONS_H
