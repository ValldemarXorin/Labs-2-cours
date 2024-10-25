//
// Created by vova3 on 23.10.2024.
//

#include "../../headers/repositories/IMoviesRepository.h"
#include <string_view>

bool IMoviesRepository::check_arguments(const std::string &time, const std::string &age_limit, int year) const {
    try {
        MovieErrorExceptions::validate_year(year);
    }
    catch (const std::invalid_argument& err) {
        std::cout << "This movie invalid" << err.what() << std::endl;
        return false;
    }
    try {
        MovieErrorExceptions::validate_time(time);
    }
    catch (const std::invalid_argument& err) {
        std::cout << "This movie invalid" << err.what() << std::endl;
        return false;
    }
    try {
        MovieErrorExceptions::validate_age_limit(age_limit);
    }
    catch (const std::invalid_argument& err) {
        std::cout << "This movie invalid" << err.what() << std::endl;
        return false;
    }
    return true;
}

IMoviesRepository::IMoviesRepository(const std::string &db_name) : MoviesDBManager(db_name) {
    movies = MoviesDBManager::load_data_from_DB();
}

IMoviesRepository::~IMoviesRepository() {
    MoviesDBManager::save_data_to_DB(movies);
}

void IMoviesRepository::add_movie(const std::string &title, const std::string &short_description,
                                  const std::string &time, const std::string &age_limit, int year) {
    if (check_arguments(time, age_limit, year))
        movies.emplace_back(Movie(title, short_description, time, age_limit, year));
}

void IMoviesRepository::display_info() {
    for (int i = 0; i < movies.size(); ++i) {
        std::cout << i + 1 << ". " << movies[i] << std::endl;
    }
}

void IMoviesRepository::update_movie(std::string_view title, const std::string &new_title,
                                     const std::string &new_short_description, const std::string &new_time,
                                     const std::string &new_age_limit, int new_year) {
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

void IMoviesRepository::delete_movie(std::string_view title) {
    for (int i = 0; i < movies.size(); ++i) {
        if (movies[i].get_title() == title) {
            movies.erase(movies.begin() + i);
            return;
        }
    }
    std::cout << "This movie doesn't exist." << std::endl;
}

IMoviesRepository* IMoviesRepository::get_instance() {
    std::string db_name = "MovieDatabase.sqlite";
    if (IMoviesRepository::instance == nullptr)
        IMoviesRepository::instance = new IMoviesRepository(db_name);
    return IMoviesRepository::instance;
}