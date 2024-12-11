//
// Created by vova3 on 09.12.2024.
//

#ifndef LABS_2_COURS_LIKEDREPOSITORY_H
#define LABS_2_COURS_LIKEDREPOSITORY_H
#include "../database/DBManager.h"
#include "../database/LikedDBManager.h"
#include "../auth_models/User.h"

class LikedRepository {
    DBManager<LikedMovie>* liked_movies_db_manager;
    std::vector<LikedMovie> liked_movies;
    int next_available_id;

public:
    LikedRepository();

    ~LikedRepository();

    void add_liked_movie(int user_id, int movie_id, std::vector<Movie> all_movies);

    void delete_liked_movie(int user_id, int movie_id);

    std::vector<Movie> get_liked_movies(int user_id);
};
#endif //LABS_2_COURS_LIKEDREPOSITORY_H
