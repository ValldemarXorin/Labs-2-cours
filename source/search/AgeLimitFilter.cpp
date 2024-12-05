//
// Created by vova3 on 28.11.2024.
//
#include "../../headers/search/AgeLimitFilter.h"

AgeLimitFilter::AgeLimitFilter(const std::string &limit) : age_limit(limit) {}

MyVector<Movie> AgeLimitFilter::apply(MyVector<Movie> movies) {
    MyVector<Movie> filtered_movies;
    for (const auto& movie : movies) {
        if (movie.get_age_limit() == age_limit) {
            filtered_movies.push_back(movie);
        }
    }
    return filtered_movies;
}