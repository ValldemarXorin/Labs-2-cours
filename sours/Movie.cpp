#include "..\headers\Movie.h"

Movie::Movie(const std::string &title, int year) : title(title), year(year) {}

const std::string& Movie::getTitle() const {
    return title;
}

int Movie::getYear() const {
    return year;
}

void Movie::display() const {
    std::cout << "Title: " << title << ", Year: " << year << std::endl; // Отображение информации о фильме
}

bool Movie::operator==(const Movie &other) const {
    return title == other.title && year == other.year;
}

Movie& Movie::operator=(const Movie &other) {
    if (this != &other) {
        title = other.title;
        year = other.year;
    }
    return *this;
}

std::ostream& operator<<(std::ostream &os, const Movie &movie) { // Обычный оператор вывода
    os << "Title: " << movie.title << ", Year: " << movie.year;
    return os;
}
