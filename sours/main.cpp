#include <iostream>
#include "..\headers\Movie.h"
#include "..\SQLiteLibrary\sqlite3.h"
#include "..\headers\MovieDatabase.h"
#include <memory>


void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Add movies\n";
    std::cout << "2. Delete movie by ID\n"; // Новый пункт меню
    std::cout << "3. Delete movie by title\n"; // Новый пункт меню
    std::cout << "4. Update a movie\n";
    std::cout << "5. Find a movie by title\n";
    std::cout << "6. Display all movies\n";
    std::cout << "7. Exit\n";
}


int main() {


        std::unique_ptr<MovieDatabase> db = std::make_unique<MovieDatabase>("MovieDatabase.sqlite");
        int choice;

        do {
            displayMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1: {
                    int numMovies;
                    std::cout << "How many movies would you like to add? ";
                    std::cin >> numMovies;

                    for (int i = 0; i < numMovies; ++i) {
                        std::string title;
                        int year;
                        std::cin.ignore();
                        std::cout << "Enter title for movie " << (i + 1) << ": ";
                        std::getline(std::cin, title);
                        std::cout << "Enter year for movie " << (i + 1) << ": ";
                        std::cin >> year;
                        db->addMovie(Movie(title, year));
                    }
                    break;
                }
                case 2: { // Удаление по ID
                    int id;
                    std::cout << "Enter the index of the movie to delete: ";
                    std::cin >> id;
                    db->deleteMovie(id);
                    std::cout << "Movie deleted.\n";
                    break;
                }
                case 3: { // Удаление по заголовку
                    std::string title;
                    std::cout << "Enter the title of the movie to delete: ";
                    std::cin.ignore();
                    std::getline(std::cin, title);
                    db->deleteMovie(title);
                    std::cout << "Movie deleted if it existed.\n";
                    break;
                }
                case 4: {
                    int id;
                    std::cout << "Enter the index of the movie to update: ";
                    std::cin >> id;
                    std::string title;
                    int year;
                    std::cout << "Enter new title: ";
                    std::cin.ignore();
                    std::getline(std::cin, title);
                    std::cout << "Enter new year: ";
                    std::cin >> year;
                    db->updateMovie(Movie(title, year), id);
                    std::cout << "Movie updated.\n";
                    break;
                }
                case 5: {
                    std::string title;
                    std::cout << "Enter the title of the movie to find: ";
                    std::cin.ignore();
                    std::getline(std::cin, title);
                    db->findMovieByTitle(title);
                    break;
                }
                case 6: {
                    std::cout << "All movies:\n";
                    const auto& movies = db->getMovies(); // Получаем все фильмы
                    for (size_t i = 0; i < movies.size(); ++i) {
                        std::cout << i << ": " << movies[i] << std::endl; // Выводим индекс для удобства
                    }
                    break;
                }
                case 7:
                    std::cout << "Exiting the program...\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (choice != 7);

        return 0;
}