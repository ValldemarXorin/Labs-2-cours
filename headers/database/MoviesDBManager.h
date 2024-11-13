//
// Created by vova3 on 21.10.2024.
//

#ifndef LABS_2_COURS_MOVIESDBMANAGER_H
#define LABS_2_COURS_MOVIESDBMANAGER_H

#include "DBManager.h"
#include "../../SQLiteLibrary/sqlite3.h"
#include <math.h>


class MoviesDBManager : protected DBManager<Movie> {

    enum {TITLE = 1, DESCRIPTION, GENRE, REALEASE_YEAR, RUNTIME,
            RATING, AGE_LIMIT, LINK_ID};

public:
    explicit MoviesDBManager(const std::string& db_name);

    MoviesDBManager(const MoviesDBManager& other) = delete;

    MoviesDBManager& operator=(const MoviesDBManager& other) = delete;

    ~MoviesDBManager() override;

    void create_table() override;

    std::vector<Movie> load_data_from_DB() override; // может уменьшить количесто кода не теряя читаемости. Так же это может улучшить расширяемость проекта
    void save_data_to_DB(std::vector<Movie> movies) override; // то же самое, что в 18 строке надо доделать
};

#endif //LABS_2_COURS_MOVIESDBMANAGER_H
