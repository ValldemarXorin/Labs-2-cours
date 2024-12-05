//
// Created by vova3 on 28.11.2024.
//
#include "../../headers/search/RatingFilter.h"

RatingFilter::RatingFilter(bool ascending) : isAscending(ascending) {};

MyVector<Movie> RatingFilter::apply(MyVector<Movie> movies) {
    std::function<bool(const Movie&, const Movie&)> comp = [this](const Movie& a, const Movie& b) {
        return isAscending ? a.get_runtime() < b.get_runtime() : a.get_runtime() > b.get_runtime();
    };
    movies.sort(comp);
    return movies;
}