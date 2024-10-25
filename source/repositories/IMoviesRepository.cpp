//
// Created by vova3 on 23.10.2024.
//

#include "../../headers/repositories/IMoviesRepository.h"

bool IMoviesRepository::check_arguments(std::string &time, std::string &age_limit, int year) {
    try {
        MovieErrorExceptions::validate_year(year);
    }
    catch (const std::invalid_argument& err) {
        std::cout << "This movie invalid" << std::endl;
        return false;
    }
    try {
        MovieErrorExceptions::validate_time(time);
    }
    catch (const std::invalid_argument& err) {
        std::cout << "This movie invalid" << std::endl;
        return false;
    }
    try {
        MovieErrorExceptions::validate_age_limit(age_limit);
    }
    catch (const std::invalid_argument& err) {
        std::cout << "This movie invalid" << std::endl;
        return false;
    }
    return true;
}

IMoviesRepository::IMoviesRepository(std::string &db_name) : MoviesDBManager(db_name) {
    movies = MoviesDBManager::load_data_from_DB();
}

IMoviesRepository::~IMoviesRepository() {
    MoviesDBManager::save_data_to_DB(movies);
}

void IMoviesRepository::add_movie(std::string &title, std::string &short_description,
                                  std::string &time, std::string &age_limit, int year) {
    if (check_arguments(time, age_limit, year))
        movies.push_back(Movie(title, short_description, time, age_limit, year));
}

void IMoviesRepository::display_info() {
    for (int i = 0; i < movies.size(); ++i) {
        std::cout << i + 1 << ". " << movies[i] << std::endl;
    }
}

void IMoviesRepository::update_movie(std::string &title, std::string &new_title,
                                     std::string &new_short_description, std::string &new_time,
                                     std::string &new_age_limit, int new_year) {
    if (!check_arguments(new_time, new_age_limit, new_year))
        return;
    for (int i = 0; i < movies.size(); ++i) {
        if (movies[i].get_title() == title) {
            movies[i] = Movie(new_title, new_short_description, new_time, new_age_limit, new_year);
            return;
        }
    }
    std::cout << "This movie doesn't exist." << std::endl;
}

void IMoviesRepository::delete_movie(std::string title) {
    for (int i = 0; i < movies.size(); ++i) {
        if (movies[i].get_title() == title) {
            movies.erase(movies.begin() + i);
            return;
        }
    }
    std::cout << "This movie doesn't exist." << std::endl;
}