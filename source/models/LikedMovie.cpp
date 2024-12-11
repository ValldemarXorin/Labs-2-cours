//
// Created by vova3 on 08.12.2024.
//

#include "../../headers/models/LikedMovie.h"

LikedMovie::LikedMovie(int liked_id, int user_id, Movie movie) : liked_id(liked_id),
                                                                  user_id(user_id), movie(movie) {};

int LikedMovie::get_liked_id() const { return liked_id; }

Movie LikedMovie::get_movie() const { return movie; }

int LikedMovie::get_user_id() const { return user_id; }

