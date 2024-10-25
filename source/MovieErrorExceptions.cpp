//
// Created by vova3 on 24.10.2024.
//
#include "../headers/MovieErrorExceptions.h"

void MovieErrorExceptions::validate_time(const std::string &time) {
    std::regex time_regex(R"(^([01]\d|2[0-3]):([0-5]\d):([0-5]\d)$)");
    if (!std::regex_match(time, time_regex))
        throw std::invalid_argument("Invalid time format. Expected HH:MM:SS");
}

void MovieErrorExceptions::validate_age_limit(const std::string &age_limit) {
    std::regex age_limit_regex(R"(^(0\+|3\+|6\+|12\+|18\+)$)");
    if (!std::regex_match(age_limit, age_limit_regex))
        throw std::invalid_argument("Invalid age limit format. Expected N+ or NN+");
}

void MovieErrorExceptions::validate_year(int year) {
    if (year <= 1850) {
        throw std::invalid_argument("Year must be a positive integer greater than 1850.");
    }
}
