#ifndef CLION_PROJECT_FILM_H
#define CLION_PROJECT_FILM_H

#include <string>
#include <iostream>


class Movie {
    std::string title;
    int year;

public:
    Movie(const std::string &title, int year);
    ~Movie() = default; // Удаляем виртуальный деструктор

    const std::string& getTitle() const;
    int getYear() const;

    void display() const; // Обычная функция для отображения информации о фильме
    bool operator==(const Movie &other) const;
    Movie& operator=(const Movie &other); // Дружественная функция для переопределения оператора присваивания
    friend std::ostream& operator<<(std::ostream &os, const Movie &movie); // Обычный оператор вывода

};


#endif //CLION_PROJECT_FILM_H

