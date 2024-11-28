//
// Created by vova3 on 28.11.2024.
//
#include "../../headers/search/RatingFilter.h"

RatingFilter::RatingFilter(bool ascending) : isAscending(ascending) {};

std::vector<Movie> RatingFilter::apply(std::vector<Movie> movies) {
    std::vector<Movie> sorted_movies = movies;
    std::sort(sorted_movies.begin(), sorted_movies.end(), [this](const Movie& a, const Movie& b) {
        return isAscending ? a.get_rating() < b.get_rating() : a.get_rating() > b.get_rating();
    });
    return sorted_movies;
}