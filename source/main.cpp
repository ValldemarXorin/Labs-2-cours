#include <iostream>
#include "../headers/models/Movie.h"
#include "..\SQLiteLibrary\sqlite3.h"
#include "..\headers\repositories\IMoviesRepository.h"
#include "..\headers\interface\MainWindow.h"
#include "..\headers\interface\loginwindow.h"
#include <QApplication>
#include <memory>


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    IUserRepository users;
    IMoviesRepository movies;

    LoginWindow loginWindow(&movies, &users);
    loginWindow.show();

    return app.exec();
}



//void displayMenu() {
//    std::cout << "\nMenu:\n";
//    std::cout << "1. Add movies\n";
//    std::cout << "2. Delete movie by title\n"; // Новый пункт меню
//    std::cout << "3. Update a movie\n";
//    std::cout << "4. Display all movies\n";
//    std::cout << "5. Exit\n";
//}

//std::string db_name = "MovieDatabase.sqlite";
//auto movies_repos = std::make_unique<IMoviesRepository> (db_name);
//
//bool end_prog = false;
//short cont_func;
//short choose;
//while (!end_prog) {
//displayMenu();
//std::cin >> choose;
//std::cin.ignore();
//cont_func = 1;
//switch (choose) {
//case 1:
//while (cont_func == 1) {
//std::string title, age_limit, description, runtime, genre;
//int release_year, link_id;
//float rating;
//std::cout << "Enter title of movie: " << std::endl;
//std::getline(std::cin, title);
//std::cout << "Enter description of " << title << ": " << std::endl;
//std::getline(std::cin, description);
//std::cout << "Enter genre of " << title << ": " << std::endl;
//std::getline(std::cin, genre);
//std::cout << "Enter release year of " << title << ": " << std::endl;
//std::cin >> release_year; // переделать проверку на вводимый тип данных
//std::cout << "Enter runtime of " << title << ": " << std::endl;
//std::cin.ignore();
//std::getline(std::cin, runtime);
//std::cout << "Enter rating of " << title << ": " << std::endl;
//std::cin >> rating;
//std::cout << "Enter age limit of " << title << ": " << std::endl;
//std::cin.ignore();
//std::getline(std::cin, age_limit);
//std::cout << "Enter links id of " << title << ": " << std::endl;
//std::cin >> link_id;
//std::cin.ignore();
//movies_repos->add_movie(title, description, genre, release_year,
//        runtime, rating, link_id, age_limit);
//std::cout << "Enter 1 to add another movie and 0 to back menu:" << std::endl;
//std::cin >> cont_func;
//std::cin.ignore();
//}
//break;
//case 2:
//while (cont_func == 1) {
//std::string title;
//std::cout << "Enter title of movie: " << std::endl;
//std::getline(std::cin, title);
//movies_repos->delete_movie(title);
//std::cout << "Enter 1 to delete another movie and 0 to back menu:" << std::endl;
//std::cin >> cont_func;
//std::cin.ignore();
//}
//break;
//case 3:
//while (cont_func == 1) {
//std::string title, new_title;
//std::string age_limit, description, runtime, genre;
//int release_year, link_id;
//float rating;
//std::cout << "Enter title of movie to update: " << std::endl;
//std::getline(std::cin, title);
//std::cout << "Enter new title of movie: " << std::endl;
//std::getline(std::cin, new_title);
//std::cout << "Enter description of " << new_title << ": " << std::endl;
//std::getline(std::cin, description);
//std::cout << "Enter genre of " << new_title << ": " << std::endl;
//std::getline(std::cin, genre);
//std::cout << "Enter release year of " << new_title << ": " << std::endl;
//std::cin >> release_year; // переделать проверку на вводимый тип данных
//std::cout << "Enter runtime of " << new_title << ": " << std::endl;
//std::cin.ignore();
//std::getline(std::cin, runtime);
//std::cout << "Enter rating of " << new_title << ": " << std::endl;
//std::cin >> rating;
//std::cout << "Enter age limit of " << new_title << ": " << std::endl;
//std::cin.ignore();
//std::getline(std::cin, age_limit);
//std::cout << "Enter links id of " << new_title << ": " << std::endl;
//std::cin >> link_id;
//std::cin.ignore();
//movies_repos->delete_movie(title);
//movies_repos->add_movie(new_title, description, genre, release_year,
//        runtime, rating, link_id, age_limit);
//std::cout << "Enter 1 to update another movie and 0 to back menu:" << std::endl;
//std::cin >> cont_func;
//std::cin.ignore();
//}
//break;
//case 4:
//movies_repos->display_info();
//std::cin.ignore();
//break;
//default:
//std::cout << "Exit..." << std::endl;
//end_prog = true;
//break;
//}
//std::system("cls");
//}
//return 0;