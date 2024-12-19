//
// Created by vova3 on 21.10.2024.
//

#ifndef LABS_2_COURS_IMOVIESREPOSITORY_H
#define LABS_2_COURS_IMOVIESREPOSITORY_H

#include "../models/Movie.h"
#include "../database/MoviesDBManager.h"
#include "../database/DBManager.h"
#include "../MovieErrorExceptions.h"
#include <vector>
#include <string_view>


//начал делать
class IMoviesRepository : public MovieErrorExceptions {
    std::vector<Movie> movies;
    DBManager<Movie>* movies_db_manager;
    int next_available_id;

public:
    IMoviesRepository();

    ~IMoviesRepository();

    void add_movie(const std::string &title, const std::string &description, const std::string &genre,
                   int realease_year, const std::string &runtime, float rating, const std::string& age_limit,
                   const std::string& poster_link, const std::string& trailer_link);

    void delete_movie(std::string_view title);

    std::vector<Movie> get_movies();

    const Movie &operator[](size_t index) const;

};

#endif //LABS_2_COURS_IMOVIESREPOSITORY_H
