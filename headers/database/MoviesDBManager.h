//
// Created by vova3 on 21.10.2024.
//

#ifndef LABS_2_COURS_MOVIESDBMANAGER_H
#define LABS_2_COURS_MOVIESDBMANAGER_H

#include "DBManager.h"
#include "../../SQLiteLibrary/sqlite3.h"
#include <math.h>
#include "Database.h"


class MoviesDBManager : public DBManager<Movie> {
    enum {TITLE = 1, DESCRIPTION, GENRE, REALEASE_YEAR, RUNTIME,
            RATING, AGE_LIMIT, LINK_ID};

public:
    MoviesDBManager();

    ~MoviesDBManager() override = default;

    void create_table() override;

    std::vector<Movie> load_data_from_DB() override; // может уменьшить количесто кода не теряя читаемости. Так же это может улучшить расширяемость проекта
    void save_data_to_DB(std::vector<Movie> movies) override; // то же самое, что в 18 строке надо доделать
};

#endif //LABS_2_COURS_MOVIESDBMANAGER_H
