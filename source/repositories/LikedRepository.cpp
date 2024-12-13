//
// Created by vova3 on 10.12.2024.
//



#include "../../headers/repositories/LikedRepository.h"

LikedRepository::LikedRepository() : liked_movies_db_manager(new LikedDBManager) {
    liked_movies = liked_movies_db_manager->load_data_from_DB();
    if (liked_movies.size() > 0)
        next_available_id = liked_movies[liked_movies.size() - 1].get_liked_id() + 1;
    else
        next_available_id = 1;
}

LikedRepository::~LikedRepository() {
    liked_movies_db_manager->save_data_to_DB(liked_movies);
}

void LikedRepository::add_liked_movie(int user_id, int movie_id, std::vector<Movie> all_movies) {
    Movie movie_to_add;
    for (auto& movie: all_movies) {
        if (movie.get_id() == movie_id) {
            movie_to_add = movie;
            break;
        }
    }
    liked_movies.emplace_back(LikedMovie(next_available_id, user_id, movie_to_add));
    ++next_available_id;
}

void LikedRepository::delete_liked_movie(int user_id, int movie_id) {
    for (auto it = liked_movies.begin(); it != liked_movies.end(); ) {
        if (it->get_user_id() == user_id && it->get_movie().get_id() == movie_id)
            it = liked_movies.erase(it);
        else
            ++it;
    }
}

std::vector<Movie> LikedRepository::get_liked_movies(int user_id) {
    std::vector<Movie> user_liked_movie;
    for (auto& liked_movie: liked_movies) {
        if (liked_movie.get_user_id() == user_id)
            user_liked_movie.emplace_back(liked_movie.get_movie());
    }
    return  user_liked_movie;
}

