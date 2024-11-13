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

public:
    explicit IMoviesRepository(const std::string &db_name);

    IMoviesRepository(const IMoviesRepository& other) = delete;

    IMoviesRepository& operator=(const IMoviesRepository& other) = delete;

    ~IMoviesRepository() override;

    void add_movie(const std::string &title, const std::string &description, const std::string &genre,
                   int realease_year, const std::string &runtime, float rating, int link_id, std::string& age_limit);

    std::vector<Movie> find_movies_by_autocomplete(const std::string& part_of_autocomplete);

    void delete_movie(std::string_view title);

    const Movie &operator[](size_t index) const;

};

#endif //LABS_2_COURS_IMOVIESREPOSITORY_H
