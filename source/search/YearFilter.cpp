//
// Created by vova3 on 28.11.2024.
//
#include "../../headers/search/YearFilter.h"

YearFilter::YearFilter(int y) : release_year(y) {};

std::vector<Movie> YearFilter::apply(std::vector<Movie> movies) {
    std::vector<Movie> filtered_movies;
    for (const auto& movie : movies) {
        if (movie.get_release_year() == release_year) {
            filtered_movies.push_back(movie);
        }
    }
    return filtered_movies;
}