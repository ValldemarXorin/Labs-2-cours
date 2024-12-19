#include <iostream>
#include "../headers/models/Movie.h"
#include "../SQLiteLibrary/sqlite3.h"
#include "../headers/repositories/IMoviesRepository.h"
#include "../headers/repositories/LikedRepository.h"
#include "../headers/interface/MainWindow.h"
#include "../headers/interface/loginwindow.h"
#include "../headers/TopParser.h"
#include <QApplication>
#include <memory>


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    IUserRepository users;
    IMoviesRepository movies;
    LikedRepository liked_movies;

    TopParser parser;

    LoginWindow loginWindow(&movies, &users, &liked_movies);
    loginWindow.show();

    return app.exec();
}


