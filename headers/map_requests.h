//
// Created by vova3 on 19.10.2024.
//

#ifndef LABS_2_COURS_MAP_REQUESTS_H
#define LABS_2_COURS_MAP_REQUESTS_H

#include <string>
#include <map>  // [[rewrite]] написать свой контейнер map
enum { Movies_create_table, Movies_select, Movies_delete, Movies_save,
        Genres_create_table, Genres_select, Genres_delete, Genres_save,
        Favorites_create_table, Favorites_select, Favorites_delete, Favorites_save,
        Users_create_table, Users_select, Users_delete, Users_save,
        Humans_create_table, Humans_select, Humans_delete, Humans_save,
        Links_create_table, Links_select, Links_delete, Links_save,
        Rate_create_table, Rate_select, Rate_delete, Rate_save,
        Money_create_table, Money_select, Money_delete, Money_save};

// ключ хранится в виде НазваниеТаблицы_Команда пробелы заменяются на '_'
std::map<int, std::string> sql_requests = {

        {Movies_create_table, "CREATE TABLE IF NOT EXISTS Movies ("
                                    "id INT PRIMARY KEY,"
                                    "title VARCHAR(255),"
                                    "short_description TEXT,"
                                    "`time` VARCHAR(10),"
                                    "age_limit VARCHAR(3),"
                                    "Genre_id INT,"
                                    "Human_id INT,"
                                    "Rate_id INT,"
                                    "Money_id INT,"
                                    "Links_id INT,"
                                    "FOREIGN KEY (Genre_id) REFERENCES Genres(id),"
                                    "FOREIGN KEY (Human_id) REFERENCES Humans(id),"
                                    "FOREIGN KEY (Rate_id) REFERENCES Rate(id),"
                                    "FOREIGN KEY (Money_id) REFERENCES Money(id),"
                                    "FOREIGN KEY (Links_id) REFERENCES Links(id)"
                                    ");"},

        {Movies_select, "SELECT * FROM Movies"},
        {Movies_delete, "DELETE FROM Movies"},
        {Movies_save, "INSERT INTO movies (title, short_description, time, age_limit,"
                            "Genre_id, Human_id, Rate_id, Money_id, Links_id) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?);"},

        {Genres_create_table, "CREATE TABLE IF NOT EXISTS Genres ("
                                    "id INT PRIMARY KEY,"
                                    "genre VARCHAR(255),"
                                    "Movie_id INT"
                                    ");"},

        {Genres_select, "SELECT * FROM Genres"},
        {Genres_delete, "DELETE FROM Genres"},
        {Genres_save, "INSERT INTO Genres (genre, Movie_id) VALUES (?, ?);"},

        {Favorites_create_table, "CREATE TABLE IF NOT EXISTS Favorites ("
                                        "id INT PRIMARY KEY,"
                                        "Movie_id INT,"
                                        "User_id INT,"
                                        "FOREIGN KEY (Movie_id) REFERENCES Movies(id),"
                                        "FOREIGN KEY (User_id) REFERENCES Users(id)"
                                        ");"},

        {Favorites_select, "SELECT * FROM Favorites"},
        {Favorites_delete, "DElETE FROM Favorites"},
        {Favorites_save, "INSERT INTO Favorites (Movie_id, User_id) VALUES (?, ?);"},

        {Users_create_table, "CREATE TABLE IF NOT EXISTS Users ("
                                    "id INT PRIMARY KEY,"
                                    "email VARCHAR(255),"
                                    "`password` VARCHAR(255)"
                                    ");"},

        {Users_select, "SELECT * FROM Users"},
        {Users_delete, "DELETE FROM Users"},
        {Users_save, "INSERT INTO Users (email, password) VALUES (?, ?);"},

        {Humans_create_table, "CREATE TABLE IF NOT EXISTS Humans ("
                                    "id INT PRIMARY KEY,"
                                    "FIC VARCHAR(255),"
                                    "professions VARCHAR(255),"
                                    "movies_id INT,"
                                    "FOREIGN KEY (movies_id) REFERENCES Movies(id)"
                                    ");"},

        {Humans_select, "SELECT * FROM Humans"},
        {Humans_delete, "DELETE FROM Humans"},
        {Humans_save, "INSERT INTO Humans (FIO, professions, movies_id) VALUES (?, ?, ?);"},

        {Links_create_table,  "CREATE TABLE IF NOT EXISTS Links ("
                                    "id INT PRIMARY KEY,"
                                    "trailer_link VARCHAR(255),"
                                    "poster_link VARCHAR(255)"
                                    ");"},

        {Links_select, "SELECT * FROM Links"},
        {Links_delete, "DELETE FROM Links"},
        {Links_save, "INSERT INTO (trailer_link, poster_link) VALUES (?, ?);"},

        {Rate_create_table,   "CREATE TABLE IF NOT EXISTS Rate ("
                                    "id INT PRIMARY KEY,"
                                    "rating_IMDB DECIMAL(3,1),"
                                    "rating_Kinopoisc DECIMAL(3,1),"
                                    "average_rating DECIMAL(3,1)"
                                    ");"},

        {Rate_select, "SELECT * FROM Rate"},
        {Rate_delete, "DELETE FROM Rate"},
        {Rate_save, "INSERT INTO Rate (rating_IMDB, rating_Kinopoisk, average_rating) VALUES (?, ?, ?);"},

        {Money_create_table,  "CREATE TABLE IF NOT EXISTS Money ("
                                    "id INT PRIMARY KEY,"
                                    "budget INT,"
                                    "world_fees INT"
                                    ");"},

        {Money_select, "SELECT * FROM Money"},
        {Money_delete, "DELETE FROM Money"},
        {Money_save, "INSERT INTO Money (budget, world_fees) VALUES (?, ?);"}
};

#endif //LABS_2_COURS_MAP_REQUESTS_H
