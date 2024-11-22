//
// Created by vova3 on 24.10.2024.
//
#include "../headers/MovieErrorExceptions.h"

bool MovieErrorExceptions::validate_time(const std::string &time) const {
    std::regex time_regex(R"(^([01]\d|2[0-3]):([0-5]\d):([0-5]\d)$)");
    if (!std::regex_match(time, time_regex))
        return false;
    return true;
}

bool MovieErrorExceptions::validate_age_limit(const std::string &age_limit) const {
    std::regex age_limit_regex(R"(^(0\+|3\+|6\+|12\+|18\+)$)");
    if (!std::regex_match(age_limit, age_limit_regex))
        return false;
    return  true;
}

bool MovieErrorExceptions::validate_year(int year) const {
    if (year <= 1850)
        return false;
    return true;
}
