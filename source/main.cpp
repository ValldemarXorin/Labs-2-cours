#include <iostream>
#include "../headers/models/Movie.h"
#include "../SQLiteLibrary/sqlite3.h"
#include "../headers/repositories/IMoviesRepository.h"
#include "../headers/interface/MainWindow.h"
#include "../headers/interface/loginwindow.h"
#include <QApplication>
#include <memory>

#include "../headers/top_movies/Top.h"


int main(int argc, char* argv[]) {
//    QApplication app(argc, argv);
//
//    IUserRepository users;
//    IMoviesRepository movies;
//
//    LoginWindow loginWindow(&movies, &users);
//    loginWindow.show();
//
//    return app.exec();

    std::string api_key = "45e266b6-12c2-431b-9d70-2a1cae165a8f";
    HttpClient client(api_key); // Ваш API ключ

    std::string url = "https://kinopoiskapiunofficial.tech/api/v2.2/films/collection?type=TOP_POPULAR_MOVIES&page=1";
    std::string response = client.get(url);

    // Вывод полученного ответа
    std::cout << "Response from server:\n" << response << std::endl;

    return 0;
}