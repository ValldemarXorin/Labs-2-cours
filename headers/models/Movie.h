#ifndef CLION_PROJECT_FILM_H
#define CLION_PROJECT_FILM_H

#include <string>
#include <iostream>
#include <sstream>


class Movie {
    int id;
    std::string title;
    std::string description;
    std::string genre;
    int release_year;
    std::string runtime;
    float rating;
    std::string poster_link;
    std::string trailer_link;
    std::string age_limit;

public:
    Movie();

    Movie(int id, const std::string &title, const std::string &description, const std::string &genre,
          int realease_year, const std::string &runtime, float rating, const std::string& age_limit, const std::string& poster_link,
          const std::string& trailer_link);

    // Копирующий конструктор
    Movie(const Movie& other);

    // Перемещающий конструктор
    Movie(Movie&& other) noexcept;

    // Копирующий оператор присваивания
    Movie& operator=(const Movie& other);

    // Перемещающий оператор присваивания
    Movie& operator=(Movie&& other) noexcept;


    ~Movie() = default;

    [[nodiscard]] int get_id() const;

    [[nodiscard]] const std::string &get_title() const;

    [[nodiscard]] const std::string &get_description() const;

    [[nodiscard]] const std::string &get_genre() const;

    [[nodiscard]] int get_release_year() const;

    [[nodiscard]] const std::string &get_runtime() const;

    [[nodiscard]] float get_rating() const;

    [[nodiscard]] const std::string& get_poster_link() const;

    [[nodiscard]] const std::string& get_trailer_link() const;

    [[nodiscard]] const std::string &get_age_limit() const;

    int get_int_age_limit() const;

    int get_runtime_minutes() const;

    bool operator==(const Movie &other) const;
};

#endif //CLION_PROJECT_FILM_H

