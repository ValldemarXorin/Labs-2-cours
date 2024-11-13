#include "../../headers/models/Movie.h"

Movie::Movie(const std::string &title, const std::string &description, const std::string &genre,
             int realease_year, const std::string &runtime, float rating, int link_id, std::string& age_limit)
             : title(title), description(description), genre(genre), release_year(realease_year),
             runtime(runtime), rating(rating), link_id(link_id), age_limit(age_limit) {};


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