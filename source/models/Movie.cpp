#include "../../headers/models/Movie.h"

Movie::Movie(const std::string &title, const std::string &short_description, const std::string &time,
             const std::string &age_limit, int year) : title(title), short_description(short_description),
                                                 time(time), age_limit(age_limit), year(year) {};


const std::string &Movie::get_title() const { return title; }

const std::string &Movie::get_short_description() const { return short_description; }

const std::string &Movie::get_time() const { return time; }

const std::string &Movie::get_age_limit() const { return age_limit; }

int Movie::get_year() const { return year; }

