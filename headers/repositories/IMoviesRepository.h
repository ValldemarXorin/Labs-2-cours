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
class IMoviesRepository : public MoviesDBManager, public MovieErrorExceptions {
    std::vector<Movie> movies;

    bool check_arguments(const std::string &time, const std::string &age_limit, int year) const;

public:
    explicit IMoviesRepository(const std::string &db_name);

    IMoviesRepository(const IMoviesRepository& other) = delete;

    IMoviesRepository& operator=(const IMoviesRepository& other) = delete;

    ~IMoviesRepository() override;

    void add_movie(const std::string &title, const std::string &short_description,
                   const std::string &time, const std::string &age_limit, int year);

    void display_info();

    void update_movie(std::string_view title, const std::string &new_title, const std::string &new_short_description,
                      std::string &new_time, std::string &new_age_limit, int new_year);

    void delete_movie(std::string_view title);

    const Movie &operator[](size_t index) const {
        if (index >= movies.size())
            throw std::out_of_range("Index out of range");
        return movies[index];
    }
};

#endif //LABS_2_COURS_IMOVIESREPOSITORY_H
