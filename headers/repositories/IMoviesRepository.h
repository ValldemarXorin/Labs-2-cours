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


//начал делать
class IMoviesRepository : public MoviesDBManager, public MovieErrorExceptions {
    std::vector<Movie> movies;

    bool check_arguments(std::string &time, std::string &age_limit, int year);

public:
    explicit IMoviesRepository(std::string &db_name);

    ~IMoviesRepository() override;

    void add_movie(std::string &title, std::string &short_description,
                   std::string &time, std::string &age_limit, int year);

    void display_info();

    void update_movie(std::string &title, std::string &new_title, std::string &new_short_description,
                      std::string &new_time, std::string &new_age_limit, int new_year);

    void delete_movie(std::string title);

    const Movie &operator[](size_t index) const {
        if (index >= movies.size())
            throw std::out_of_range("Index out of range");
        return movies[index];
    }
};

#endif //LABS_2_COURS_IMOVIESREPOSITORY_H
