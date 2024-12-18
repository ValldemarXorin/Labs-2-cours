//
// Created by vova3 on 23.10.2024.
//

#ifndef LABS_2_COURS_ERROREXCEPTIONS_H
#define LABS_2_COURS_ERROREXCEPTIONS_H
#include <iostream>
#include <unordered_set>
#include <regex>

class MovieErrorExceptions {

    const std::unordered_set<std::string> validGenres = {
            "триллер", "драма", "боевик", "криминал", "исторический",
            "приключенческий", "комедия", "семейный", "фантастика", "анимация",
            "биография", "военный", "романтика", "вестерн", "детектив",
            "научный", "спорт"
    };
public:
    bool validate_runtime(const std::string& time) const;
    bool validate_age_limit(const std::string& age_limit) const;
    bool validate_year(int year) const;
    bool validate_genre(const std::string& genre) const;
    bool is_exist_genre(const std::string& genre) const;
    bool validate_rating(const std::string& rating) const;
    bool validate_trailer(const std::string& trailer) const;
    bool validate_poster(const std::string& poster) const;
};
#endif //LABS_2_COURS_ERROREXCEPTIONS_H
