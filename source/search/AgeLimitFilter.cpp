//
// Created by vova3 on 28.11.2024.
//
#include "../../headers/search/AgeLimitFilter.h"

AgeLimitFilter::AgeLimitFilter(const std::string &limit) : age_limit(limit) {}

std::vector<Movie> AgeLimitFilter::apply(std::vector<Movie> movies) {
    std::vector<Movie> filtered_movies;
    for (const auto& movie : movies) {
        if (movie.get_age_limit() == age_limit) {
            filtered_movies.push_back(movie);
        }
    }
    return filtered_movies;
}