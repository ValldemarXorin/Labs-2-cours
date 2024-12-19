//
// Created by vova3 on 23.10.2024.
//

#include "../../headers/repositories/IMoviesRepository.h"
#include <string_view>

IMoviesRepository::IMoviesRepository() : movies_db_manager(new MoviesDBManager) {
    movies = movies_db_manager->load_data_from_DB();
    next_available_id = movies[movies.size() - 1].get_id() + 1;
}

IMoviesRepository::~IMoviesRepository() {
    movies_db_manager->save_data_to_DB(movies);
}

void IMoviesRepository::add_movie(const std::string &title, const std::string &description, const std::string &genre,
                                  int realease_year, const std::string &runtime, float rating, const std::string& age_limit,
                                  const std::string& poster_link, const std::string& trailer_link) {
    movies.emplace_back(next_available_id, title, description, genre, realease_year, runtime, rating, age_limit,
                        poster_link, trailer_link);

    ++next_available_id;
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

std::vector<Movie> IMoviesRepository::get_movies() { return movies; }

const Movie &IMoviesRepository::operator[](size_t index) const{
    if (index >= movies.size())
        throw std::out_of_range("Index out of range");
    return movies[index];
}
