//
// Created by vova3 on 17.11.2024.
//
#include "../../headers/search/search_engine.h"

SearchEngine::SearchEngine(IMoviesRepository movies_repository) : movies_repository(movies_repository),
                                                                    movies(movies_repository.get_movies()){}

std::vector<Movie> SearchEngine::search_by_fragment(std::string title_fragment, bool get_back) {
    std::string title_movie;
    if (get_back) {
        movies = movies_repository.get_movies();
    }
    std::vector<Movie> result_movies;
    for(auto& movie: movies) {
        title_movie = movie.get_title();
        std::transform(title_movie.begin(), title_movie.end(), title_movie.begin(), ::tolower);
        std::transform(title_fragment.begin(), title_fragment.end(), title_fragment.begin(), ::tolower);
        if (title_movie.find(title_fragment) == 0)
            result_movies.push_back(movie);
    }
    movies = result_movies;
    return result_movies;
}