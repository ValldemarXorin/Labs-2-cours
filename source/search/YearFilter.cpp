//
// Created by vova3 on 28.11.2024.
//
#include "../../headers/search/YearFilter.h"

YearFilter::YearFilter(bool ascending) : isAscending(ascending) {};

MyVector<Movie> YearFilter::apply(MyVector<Movie> movies) {
    std::function<bool(const Movie&, const Movie&)> comp = [this](const Movie& a, const Movie& b) {
        return isAscending ? a.get_release_year() < b.get_release_year() : a.get_release_year() > b.get_release_year();
    };
    movies.sort(comp);
    return movies;
}