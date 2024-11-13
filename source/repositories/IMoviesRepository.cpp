//
// Created by vova3 on 23.10.2024.
//

#include "../../headers/repositories/IMoviesRepository.h"
#include <string_view>

IMoviesRepository::IMoviesRepository(const std::string &db_name) : MoviesDBManager(db_name) {
    movies = MoviesDBManager::load_data_from_DB();
}

IMoviesRepository::~IMoviesRepository() {
    MoviesDBManager::save_data_to_DB(movies);
}

void IMoviesRepository::add_movie(const std::string &title, const std::string &description, const std::string &genre,
                                  int realease_year, const std::string &runtime, float rating, int link_id, std::string& age_limit) {
    movies.emplace_back(title, description, genre, realease_year, runtime, rating, link_id, age_limit);
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

const Movie &IMoviesRepository::operator[](size_t index) const{
    if (index >= movies.size())
        throw std::out_of_range("Index out of range");
    return movies[index];
}
