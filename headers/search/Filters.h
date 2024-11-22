//
// Created by vova3 on 17.11.2024.
//

#ifndef LABS_2_COURS_FILTERS_H
#define LABS_2_COURS_FILTERS_H
#include "../models/Movie.h"
#include <map>
#include <vector>
#include <string>
#include <algorithm>

class Filters {
    std::vector<Movie> apply_genre_filter(std::vector<Movie> movies, const std::string& genre);

    std::vector<Movie> apply_year_filter(std::vector<Movie> movies, int release_year);

    std::vector<Movie> apply_runtime_filter(std::vector<Movie> movies, bool isAscending);

    std::vector<Movie> apply_rating_filter(std::vector<Movie> movies, bool isAscending);

    std::vector<Movie> apply_age_limit_filter(std::vector<Movie> movies, const std::string& age_limit);
public:

    std::vector<Movie> apply_filters(std::vector<Movie> movies, const std::vector<std::string>& genres_option = {},
                                     int year_option = -1, bool runtime_option = false, bool runtime_isAscending = true,
                                     bool rating_option = false, bool rating_isAscending = true,
                                     const std::vector<std::string>& age_limits_option = {});
};
#endif //LABS_2_COURS_FILTERS_H
