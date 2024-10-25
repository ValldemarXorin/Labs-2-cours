#ifndef CLION_PROJECT_FILM_H
#define CLION_PROJECT_FILM_H

#include <string>
#include <iostream>


class Movie {
    std::string title;
    std::string short_description;
    std::string time;
    std::string age_limit;
    int year;

public:
    Movie(const std::string &title, const std::string &short_description, const std::string &time,
          const std::string &age_limit, int year);

    ~Movie() = default;

    [[nodiscard]] const std::string &get_title() const;

    [[nodiscard]] const std::string &get_short_description() const;

    [[nodiscard]] const std::string &get_time() const;

    [[nodiscard]] const std::string &get_age_limit() const;

    [[nodiscard]] int get_year() const;

    bool operator==(const Movie &other) const {
        return title == other.title && short_description == other.short_description &&
               time == other.time && age_limit == other.age_limit && year == other.year;
    }

    Movie &operator<<(const Movie &other); // Пересмотреть
    friend std::ostream &operator<<(std::ostream &os, const Movie &movie) {
        os << "Title: " << movie.get_title() << ", year: " << movie.get_year() <<
           ", time: " << movie.get_time() << ", age limit: " << movie.get_age_limit() <<
           std::endl << "Short description: " << movie.get_short_description();
        return os;
    }
};

#endif //CLION_PROJECT_FILM_H

