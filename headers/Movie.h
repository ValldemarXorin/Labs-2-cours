#ifndef CLION_PROJECT_FILM_H
#define CLION_PROJECT_FILM_H

#include <string>
#include <iostream>


class Movie {
    std::string title;
    int year;
    std::string genre;
    std::string director;
    float rating;

public:
    Movie(const std::string& title, int year, const std::string& genre,
          const std::string& director, float rating);
    ~Movie() = default;

    [[nodiscard]] const std::string& getTitle() const;
    [[nodiscard]] int getYear() const;
    [[nodiscard]] const std::string getGenre() const;
    [[nodiscard]] const std::string getDirector() const;
    [[nodiscard]] float getRating() const;

    void display() const; // Обычная функция для отображения информации о фильме
    bool operator==(const Movie &other) const;
    Movie& operator=(const Movie &other); // Дружественная функция для переопределения оператора присваивания
    friend std::ostream& operator<<(std::ostream &os, const Movie &movie); // Обычный оператор вывода

};


#endif //CLION_PROJECT_FILM_H

