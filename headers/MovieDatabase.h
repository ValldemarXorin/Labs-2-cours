
#ifndef CLION_PROJECT_SQLLITEWORK_H
#define CLION_PROJECT_SQLLITEWORK_H
#include <iostream>
#include "../SQLiteLibrary/sqlite3.h"
#include "../headers/Movie.h"
#include <string>
#include <vector>
#include <string_view>


class MovieDatabase {
    sqlite3* db;
    std::string dbName;
    std::vector<Movie> movies;

public:
    explicit MovieDatabase(const std::string &dbName);
    ~MovieDatabase();

    void createTable();
    void addMovie(const Movie &movie);
    void loadMoviesFromDB();
    void saveMoviesToDB();
    const std::vector<Movie>& getMovies() const;
    void findMovieByTitle(std::string_view title) const;
    void updateMovie(const Movie &movie, int id);
    void deleteMovie(int id); // Удаление по ID
    void deleteMovie(const std::string &title); // Перегрузка для удаления по заголовку

};
#endif //CLION_PROJECT_SQLLITEWORK_H
