//
// Created by vova3 on 21.10.2024.
//

#ifndef LABS_2_COURS_MOVIESDBMANAGER_H
#define LABS_2_COURS_MOVIESDBMANAGER_H

#include "DBManager.h"
#include "../../SQLiteLibrary/sqlite3.h"


class MoviesDBManager : protected DBManager<Movie> {
    //static MoviesDBManager* instance;

public:
    explicit MoviesDBManager(std::string &db_name);

    virtual ~MoviesDBManager();

    void create_table() override;

    std::vector<Movie> load_data_from_DB() override; // может уменьшить количесто кода не теряя читаемости. Так же это может улучшить расширяемость проекта
    void save_data_to_DB(std::vector<Movie> movies) override; // то же самое, что в 18 строке надо доделать

    //static MoviesDBManager* get_instance();
};

#endif //LABS_2_COURS_MOVIESDBMANAGER_H
