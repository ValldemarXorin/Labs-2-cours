#include <iostream>
#include "../headers/models/Movie.h"
#include "../SQLiteLibrary/sqlite3.h"
#include "../headers/repositories/IMoviesRepository.h"
#include "../headers/repositories/LikedRepository.h"
#include "../headers/interface/MainWindow.h"
#include "../headers/interface/loginwindow.h"
#include <QApplication>
#include <memory>




#include "../headers/TopParser.h"


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    IUserRepository users;
    IMoviesRepository movies;
    LikedRepository liked_movies;

    LoginWindow loginWindow(&movies, &users, &liked_movies);
    loginWindow.show();

    return app.exec();

//    TopParser parser; // Создание объекта парсера
//    parser.fetch_movies(); // Запуск функции для получения фильмов
//    return 0; // Запуск цикла событий
}