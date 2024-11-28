//
// Created by vova3 on 28.11.2024.
//
#include "../../headers/search/GenreFilter.h"

GenreFilter::GenreFilter(std::string g) : genre(g) {};

std::vector<Movie> GenreFilter::apply(std::vector<Movie> movies) {
    std::vector<Movie> filtered_movies;
    for (const auto& movie : movies) {
        if (movie.get_genre() == genre) {
            filtered_movies.push_back(movie);
        }
    }
    return filtered_movies;
}