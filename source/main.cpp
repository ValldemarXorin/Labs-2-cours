#include <iostream>
#include "../headers/models/Movie.h"
#include "..\SQLiteLibrary\sqlite3.h"
#include "..\headers\repositories\IMoviesRepository.h"
#include "..\headers\interface\MainWindow.h"
#include <QLabel>
#include <QApplication>
#include <memory>


void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Add movies\n";
    std::cout << "2. Delete movie by title\n"; // Новый пункт меню
    std::cout << "3. Update a movie\n";
    std::cout << "4. Display all movies\n";
    std::cout << "5. Exit\n";
}


int main(int argc, char* argv[]) {
    std::string db_name = "MovieDatabase.sqlite";
    auto movies_repos = std::make_unique<IMoviesRepository> (db_name);

    bool end_prog = false;
    short cont_func;
    short choose;
    while (!end_prog) {
        displayMenu();
        std::cin >> choose;
        std::cin.ignore();
        cont_func = 1;
        switch (choose) {
            case 1:
                while (cont_func == 1) {
                    std::string title, age_limit, short_description, time;
                    int year;
                    std::cout << "Enter title of movie: " << std::endl;
                    std::getline(std::cin, title);
                    std::cout << "Enter short description of " << title << ": " << std::endl;
                    std::getline(std::cin, short_description);
                    std::cout << "Enter year of " << title << ": " << std::endl;
                    std::cin >> year; // переделать проверку на вводимый тип данных
                    std::cout << "Enter time of " << title << ": " << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, time);
                    std::cout << "Enter age limit of " << title << ": " << std::endl;
                    std::getline(std::cin, age_limit);
                    movies_repos->add_movie(title, short_description, time,
                                            age_limit, year);
                    std::cout << "Enter 1 to add another movie and 0 to back menu:" << std::endl;
                    std::cin >> cont_func;
                }
                break;
            case 2:
                while (cont_func == 1) {
                    std::string title;
                    std::cout << "Enter title of movie: " << std::endl;
                    std::getline(std::cin, title);
                    movies_repos->delete_movie(title);
                    std::cout << "Enter 1 to delete another movie and 0 to back menu:" << std::endl;
                    std::cin >> cont_func;
                }
                break;
            case 3:
                while (cont_func == 1) {
                    std::string title, new_title, new_age_limit, new_short_description, new_time;
                    int new_year;
                    std::cout << "Enter title of movie to update: " << std::endl;
                    std::getline(std::cin, title);
                    std::cout << "Enter new title of movie: " << std::endl;
                    std::getline(std::cin, new_title);
                    std::cout << "Enter short description of " << new_title << ": " << std::endl;
                    std::getline(std::cin, new_short_description);
                    std::cout << "Enter year of " << new_title << ": " << std::endl;
                    std::cin >> new_year; // переделать проверку на вводимый тип данных
                    std::cin.ignore();
                    std::cout << "Enter time of " << new_title << ": " << std::endl;
                    std::getline(std::cin, new_time);
                    std::cout << "Enter age limit of " << new_title << ": "<< std::endl;
                    std::getline(std::cin, new_age_limit);
                    movies_repos->update_movie(title, new_title, new_short_description,
                                               new_time, new_age_limit, new_year);
                    std::cout << "Enter 1 to update another movie and 0 to back menu:" << std::endl;
                    std::cin >> cont_func;
                }
                break;
            case 4:
                movies_repos->display_info();
                std::cin.ignore();
                break;
            case 5:
                std::cout << "Exit..." << std::endl;
                end_prog = true;
                break;
        }
        std::system("cls");
    }
    return 0;
}