//
// Created by vova3 on 28.11.2024.
//
#include "../../headers/search/YearFilter.h"

YearFilter::YearFilter(bool ascending) : isAscending(ascending) {};

std::vector<Movie> YearFilter::apply(std::vector<Movie> movies) {
    std::vector<Movie> sorted_movies = movies;
    std::sort(sorted_movies.begin(), sorted_movies.end(), [this](const Movie& a, const Movie& b) {
        return isAscending ? a.get_release_year() < b.get_release_year() : a.get_release_year() > b.get_release_year();
    });
    return sorted_movies;
}