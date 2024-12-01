//
// Created by vova3 on 23.10.2024.
//

#include "../../headers/repositories/IMoviesRepository.h"
#include <string_view>

IMoviesRepository::IMoviesRepository() : MoviesDBManager() {
    movies = MoviesDBManager::load_data_from_DB();
}

IMoviesRepository::~IMoviesRepository() {
    MoviesDBManager::save_data_to_DB(movies);
}

void IMoviesRepository::add_movie(const std::string &title, const std::string &description, const std::string &genre,
                                  int realease_year, const std::string &runtime, float rating, int link_id, std::string& age_limit) {
    if (!validate_time(runtime)) {
        std::cout << "Incorrect input runtime. Template of correct input: HH:MM:SS" << std::endl;
        return;
    }
    if (!validate_year(realease_year)) {
        std::cout << "Incorrect input year. Template of correct input: year > 1800" << std::endl;
        return;
    }
    if (!validate_age_limit(age_limit)) {
        std::cout << "Incorrect input age limit. Template of correct input: 0+, 3+, 6+, 12+, 16+, 18+" << std::endl;
        return;
    }
    movies.emplace_back(movies.size() + 1, title, description, genre, realease_year, runtime, rating, link_id, age_limit);
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

void IMoviesRepository::display_info() const {
    for (auto& movie: movies) {
        std::cout << "Title: " << movie.get_title() << ", description: " << movie.get_description() <<
        ", Genre: " << movie.get_genre() << ", release year: " << movie.get_release_year() << ", runtime: " <<
        movie.get_runtime() << ", rating: " << movie.get_rating() << ", age limit: " << movie.get_age_limit() <<
        ", link id: " << movie.get_link_id() << std::endl;
    }
}
