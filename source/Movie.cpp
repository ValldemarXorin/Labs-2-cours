#include "..\headers\Movie.h"

Movie::Movie(const std::string& title, int year, const std::string& genre,
      const std::string& director, float rating) : title(title),
      year(year), genre(genre), director(director), rating(rating) {}

const std::string& Movie::getTitle() const {
    return title;
}

int Movie::getYear() const {
    return year;
}

const std::string Movie::getGenre() const {
    return genre;
}
const std::string Movie::getDirector() const {
    return director;
}

float Movie::getRating() const {
    return rating;
}

void Movie::display() const {
    std::cout << "Title: " << title << ", Year: " << year << ", Genre: "
              << genre << ", Director: " << director << ", Rating: " << rating << std::endl;
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
