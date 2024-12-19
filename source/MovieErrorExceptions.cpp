//
// Created by vova3 on 24.10.2024.
//
#include "../headers/MovieErrorExceptions.h"

bool MovieErrorExceptions::validate_runtime(const std::string &time) const {
    std::regex time_regex(R"(^([01]\d|2[0-3]):([0-5]\d):([0-5]\d)$)");
    if (!std::regex_match(time, time_regex))
        return false;
    return true;
}

bool MovieErrorExceptions::validate_age_limit(const std::string &age_limit) const {
    std::regex ageRegex(R"(^(0\+|3\+|6\+|12\+|16\+|18\+)$)");
    return std::regex_match(age_limit, ageRegex);
}

bool MovieErrorExceptions::validate_year(int year) const {
    if (year <= 1850)
        return false;
    return true;
}

bool MovieErrorExceptions::is_exist_genre(const std::string& genre) const {
   return validGenres.contains(genre);
}

bool MovieErrorExceptions::validate_genre(const std::string& genres) const {
    if (genres.empty() || genres.front() == ' ' || genres.back() == ' ')
        return false;

    std::istringstream stream(genres);
    std::string genre;
    std::vector<std::string> valid_genres;
    size_t pos = 0;
    int count_genres = 0;

    // Проверяем каждый жанр, разделенный ", "
    while (true) {
        size_t comma = genres.find(", ", pos);

        // Последний жанр (после последней запятой)
        if (comma == std::string::npos) {
            genre = genres.substr(pos);

            // Проверка пустого жанра или существования
            if (genre.empty() || !is_exist_genre(genre))
                return false;

            valid_genres.push_back(genre);
            count_genres++;
            break;
        }

        // Промежуточные жанры
        genre = genres.substr(pos, comma - pos);

        // Проверка пустого жанра или существования
        if (genre.empty() || !is_exist_genre(genre))
            return false;

        valid_genres.push_back(genre);
        pos = comma + 2; // Переход на следующий жанр (учитываем ", ")
        count_genres++;
    }

    // Убедиться, что количество жанров равно строго 3
    if (count_genres != 3)
        return false;

    return true;
}

bool MovieErrorExceptions::validate_rating(const std::string &rating) const {
    std::regex decimalRegex(R"(^(10\.0|[0-9]\.[0-9])$)");
    return std::regex_match(rating, decimalRegex);
}

bool MovieErrorExceptions::validate_trailer(const std::string &trailer) const {
    std::regex trailerRegex(R"(^(https:\/\/www\.youtube\.com\/).*)");
    return std::regex_match(trailer, trailerRegex);
}

bool MovieErrorExceptions::validate_poster(const std::string &poster) const {
    std::regex path_regex(R"(^D:/Labs-2-cours/Labs-2-cours/images/)");
    return std::regex_search(poster, path_regex);
}
