#include "../../headers/models/Movie.h"

Movie::Movie(const std::string &title, std::string &short_description, std::string &time,
             std::string &age_limit, int year) : title(title), short_description(short_description),
                                                 time(time), age_limit(age_limit), year(year) {};


const std::string &Movie::get_title() const { return title; }

const std::string &Movie::get_short_description() const { return short_description; }

const std::string &Movie::get_time() const { return time; }

const std::string &Movie::get_age_limit() const { return age_limit; }

int Movie::get_year() const { return year; }














//int Movie::get_Genre_id() const { return Genre_id; }
//int Movie::get_Human_id() const { return Human_id; }
//int Movie::get_Rate_id() const { return Rate_id; }
//int Movie::get_Money_id() const { return Money_id; }
//int Movie::get_Links_id() const { return Links_id; }

// мб тоже переделать
//void Movie::display() const {
//    std::cout << "Title: " << title << ", Year: " << year << ", Genre: "
//              << genre << ", Director: " << director << ", Rating: " << rating << std::endl;
//}



// всё что ниже пересмотреть и переделать

