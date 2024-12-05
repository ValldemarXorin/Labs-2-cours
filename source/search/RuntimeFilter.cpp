//
// Created by vova3 on 28.11.2024.
//
#include "../../headers/search/RuntimeFilter.h"

RuntimeFilter::RuntimeFilter(bool ascending) : isAscending(ascending) {};

MyVector<Movie> RuntimeFilter::apply(MyVector<Movie> movies) {
    std::function<bool(const Movie&, const Movie&)> comp = [this](const Movie& a, const Movie& b) {
        return isAscending ? a.get_runtime() < b.get_runtime() : a.get_runtime() > b.get_runtime();
    };
    movies.sort(comp);
    return movies;
}