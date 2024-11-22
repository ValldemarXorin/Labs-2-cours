//
// Created by vova3 on 17.11.2024.
//
#include "../../headers/search/Filters.h"

std::vector<Movie> Filters::apply_genre_filter(std::vector<Movie> movies, const std::string &genre) {
    std::vector<Movie> filtered_movies;
    for (auto& movie: movies) {
        if (movie.get_genre() == genre)
            filtered_movies.push_back(movie);
    }
    return filtered_movies;
}

std::vector<Movie> Filters::apply_year_filter(std::vector<Movie> movies, int release_year) {
    std::vector<Movie> filtered_movies;
    for (auto& movie: movies) {
        if (movie.get_release_year() == release_year)
            filtered_movies.push_back(movie);
    }
    return filtered_movies;
}

std::vector<Movie> Filters::apply_runtime_filter(std::vector<Movie> movies, bool isAscending) {
    if (isAscending) {
        std::sort(movies.begin(), movies.end(), [](const Movie& a, const Movie& b) {
            return a.get_runtime() < b.get_runtime();
        });
    }
    else {
        std::sort(movies.begin(), movies.end(), [](const Movie& a, const Movie& b) {
            return a.get_runtime() > b.get_runtime();
        });
    }
    return movies;
}

std::vector<Movie> Filters::apply_rating_filter(std::vector<Movie> movies, bool isAscending) {
    if (isAscending) {
        std::sort(movies.begin(), movies.end(), [](const Movie& a, const Movie& b) {
            return a.get_rating() < b.get_rating();
        });
    }
    else {
        std::sort(movies.begin(), movies.end(), [](const Movie& a, const Movie& b) {
            return a.get_rating() > b.get_rating();
        });
    }
    return movies;
}

std::vector<Movie> Filters::apply_age_limit_filter(std::vector<Movie> movies, const std::string& age_limit) {
    std::vector<Movie> filtered_movies;
    for (auto& movie: movies) {
        if (movie.get_age_limit() == age_limit)
            filtered_movies.push_back(movie);
    }
    return filtered_movies;
}

//std::vector<Movie>
//Filters::apply_filters(std::vector<Movie> movies, const std::vector<std::string> &genres_option, int year_option,
//                       bool runtime_option, bool runtime_isAscending, bool rating_option, bool rating_isAscending,
//                       const std::vector<std::string> &age_limits_option) {
//    if (!genres_option.empty()) {
//        movies.erase(std::remove_if(movies.begin(), movies.end(),[&genres_option](const Movie& movie) {
//                                                return std::find(genres_option.begin(), genres_option.end(),
//                                                                 movie.get_genre()) == genres_option.end();
//                                            }), movies.end());
//    }
//
//    // Фильтрация по возрастному лимиту
//    if (year_option != -1) {
//        movies.erase(std::remove_if(movies.begin(), movies.end(),
//                                            [&year_option](const Movie& movie) {
//                                                return movie.get_release_year() == year_option;
//                                            }), movies.end());
//    }
//
//    // Фильтрация по времени
//    if (minRuntime > 0 || maxRuntime > 0) {
//        filteredMovies.erase(std::remove_if(filteredMovies.begin(), filteredMovies.end(),
//                                            [minRuntime, maxRuntime](const Movie& movie) {
//                                                return (minRuntime > 0 && movie.runtime < minRuntime) ||
//                                                       (maxRuntime > 0 && movie.runtime > maxRuntime);
//                                            }), filteredMovies.end());
//    }
//
//    // Фильтрация по рейтингу
//    if (minRating >= 0) {
//        filteredMovies.erase(std::remove_if(filteredMovies.begin(), filteredMovies.end(),
//                                            [minRating](const Movie& movie) {
//                                                return movie.rating < minRating;
//                                            }), filteredMovies.end());
//    }
//
//    // Сортировка по времени, если указан флаг
//    if (isAscending) {
//        std::sort(filteredMovies.begin(), filteredMovies.end(),
//                  [](const Movie& a, const Movie& b) {
//                      return a.runtime < b.runtime;
//                  });
//    } else {
//        std::sort(filteredMovies.begin(), filteredMovies.end(),
//                  [](const Movie& a, const Movie& b) {
//                      return a.runtime > b.runtime;
//                  });
//    }
//
//    return filteredMovies;
//}