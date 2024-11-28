//
// Created by vova3 on 28.11.2024.
//
#include "../../headers/search/RuntimeFilter.h"

RuntimeFilter::RuntimeFilter(bool ascending) : isAscending(ascending) {};

std::vector<Movie> RuntimeFilter::apply(std::vector<Movie> movies) {
    std::vector<Movie> sorted_movies = movies;
    std::sort(sorted_movies.begin(), sorted_movies.end(), [this](const Movie& a, const Movie& b) {
        return isAscending ? a.get_runtime() < b.get_runtime() : a.get_runtime() > b.get_runtime();
    });
    return sorted_movies;
}