#include "../../headers/models/Movie.h"

Movie::Movie() {};

Movie::Movie(int id, const std::string &title, const std::string &description, const std::string &genre,
             int realease_year, const std::string &runtime, float rating, int link_id, std::string& age_limit)
             : id(id), title(title), description(description), genre(genre), release_year(realease_year),
             runtime(runtime), rating(rating), link_id(link_id), age_limit(age_limit) {};

Movie::Movie(const Movie &other)
        : id(other.id), title(other.title), description(other.description),
          genre(other.genre), release_year(other.release_year),
          runtime(other.runtime), rating(other.rating),
          link_id(other.link_id), age_limit(other.age_limit) {};

Movie::Movie(Movie &&other) noexcept
        : id(other.id), title(std::move(other.title)),
          description(std::move(other.description)), genre(std::move(other.genre)),
          release_year(other.release_year), runtime(std::move(other.runtime)),
          rating(other.rating), link_id(other.link_id),
          age_limit(std::move(other.age_limit)) {
    other.id = 0;
    other.release_year = 0;
    other.rating = 0.0f;
    other.link_id = 0;
};

Movie &Movie::operator=(const Movie &other)  {
    if (this != &other) {
        id = other.id;
        title = other.title;
        description = other.description;
        genre = other.genre;
        release_year = other.release_year;
        runtime = other.runtime;
        rating = other.rating;
        link_id = other.link_id;
        age_limit = other.age_limit;
    }
    return *this;
}

Movie &Movie::operator=(Movie &&other) noexcept  {
    if (this != &other) {
        id = other.id;
        title = std::move(other.title);
        description = std::move(other.description);
        genre = std::move(other.genre);
        release_year = other.release_year;
        runtime = std::move(other.runtime);
        rating = other.rating;
        link_id = other.link_id;
        age_limit = std::move(other.age_limit);

        other.id = 0;
        other.release_year = 0;
        other.rating = 0.0f;
        other.link_id = 0;
    }
    return *this;
}

int Movie::get_id() const { return id; }

const std::string &Movie::get_title() const { return title; }

const std::string &Movie::get_description() const { return description; }

const std::string &Movie::get_genre() const { return genre; }

int Movie::get_release_year() const { return release_year; }

const std::string &Movie::get_runtime() const { return runtime; }

float Movie::get_rating() const { return rating; }

int Movie::get_link_id() const { return link_id; }

const std::string &Movie::get_age_limit() const { return age_limit; }

bool Movie::operator==(const Movie &other) const {
    return title == other.title && description == other.description && genre == other.genre &&
    release_year == other.release_year && runtime == other.runtime && rating == other.rating &&
    link_id == other.link_id && age_limit == other.age_limit;
}