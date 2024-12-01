#ifndef CLION_PROJECT_FILM_H
#define CLION_PROJECT_FILM_H

#include <string>
#include <iostream>


class Movie {
    int id;
    std::string title;
    std::string description;
    std::string genre;
    int release_year;
    std::string runtime;
    float rating;
    int link_id;
    std::string age_limit;

public:
    Movie(int id, const std::string &title, const std::string &description, const std::string &genre,
          int realease_year, const std::string &runtime, float rating, int link_id, std::string& age_limit);

    ~Movie() = default;

    [[nodiscard]] int get_id() const;

    [[nodiscard]] const std::string &get_title() const;

    [[nodiscard]] const std::string &get_description() const;

    [[nodiscard]] const std::string &get_genre() const;

    [[nodiscard]] int get_release_year() const;

    [[nodiscard]] const std::string &get_runtime() const;

    [[nodiscard]] float get_rating() const;

    [[nodiscard]] int get_link_id() const;

    [[nodiscard]] const std::string &get_age_limit() const;

    bool operator==(const Movie &other) const;
};

#endif //CLION_PROJECT_FILM_H

