//
// Created by vova3 on 08.12.2024.
//

#ifndef LABS_2_COURS_LIKEDMOVIE_H
#define LABS_2_COURS_LIKEDMOVIE_H
#include "Movie.h"

class LikedMovie {
    int liked_id;
    int user_id;
    Movie movie;

public:
    LikedMovie(int liked_id, int user_id, Movie movie);

    ~LikedMovie() = default;

    int get_liked_id() const;

    int get_user_id() const;

    Movie get_movie() const;
};
#endif //LABS_2_COURS_LIKEDREPOSITORY_H
