#include "../../headers/models/Movie.h"

Movie::Movie() {};

Movie::Movie(int id, const std::string &title, const std::string &description, const std::string &genre,
             int realease_year, const std::string &runtime, float rating, const std::string& age_limit, const std::string& poster_link,
             const std::string& trailer_link)
             : id(id), title(title), description(description), genre(genre), release_year(realease_year),
             runtime(runtime), rating(rating), poster_link(poster_link), trailer_link(trailer_link), age_limit(age_limit) {};

Movie::Movie(const Movie &other)
        : id(other.id), title(other.title), description(other.description),
          genre(other.genre), release_year(other.release_year),
          runtime(other.runtime), rating(other.rating),
          poster_link(other.poster_link), trailer_link(other.trailer_link), age_limit(other.age_limit) {};

Movie::Movie(Movie &&other) noexcept
        : id(other.id), title(std::move(other.title)),
          description(std::move(other.description)), genre(std::move(other.genre)),
          release_year(other.release_year), runtime(std::move(other.runtime)),
          rating(other.rating), poster_link(other.poster_link), trailer_link(other.trailer_link),
          age_limit(std::move(other.age_limit)) {
    other.id = 0;
    other.release_year = 0;
    other.rating = 0.0f;
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
        poster_link = other.poster_link;
        trailer_link = other.trailer_link;
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
        poster_link = other.poster_link;
        trailer_link = other.trailer_link;
        age_limit = std::move(other.age_limit);

        other.id = 0;
        other.release_year = 0;
        other.rating = 0.0f;
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

const std::string& Movie::get_poster_link() const { return poster_link; }

const std::string &Movie::get_trailer_link() const { return trailer_link; }

const std::string &Movie::get_age_limit() const { return age_limit; }


int Movie::get_int_age_limit() const {
    return std::stoi(age_limit.substr(0, age_limit.size() - 1));
}

int Movie::get_runtime_minutes() const {
    std::istringstream iss(runtime);
    int hours, minutes, seconds;
    char colon;
    iss >> hours >> colon >> minutes >> colon >> seconds;
    return hours * 60 + minutes;
}

bool Movie::operator==(const Movie &other) const {
    return title == other.title && description == other.description && genre == other.genre &&
    release_year == other.release_year && runtime == other.runtime && rating == other.rating &&
    poster_link == other.poster_link && trailer_link == other.trailer_link && age_limit == other.age_limit;
}