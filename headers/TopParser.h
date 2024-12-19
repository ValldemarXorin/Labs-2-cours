//
// Created by vova3 on 13.12.2024.
//

#ifndef LABS_2_COURS_TOPPARSER_H
#define LABS_2_COURS_TOPPARSER_H
#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "models/Movie.h"

using json = nlohmann::json;

class TopParser {
public:
    TopParser();
    ~TopParser();

    std::vector<Movie> fetch_movies(const std::vector<Movie>& all_movies);
    std::string get_last_update_time();

private:
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp);

    std::string perform_request(const std::string& url, const std::string& apiKey);
    std::vector<Movie> parse_movies(const std::string& responseString, const std::vector<Movie>& all_movies);
    void save_movies_to_file(const std::vector<Movie>& movies);
    std::vector<Movie> load_movies_from_file();
    bool is_file_recent();

    const std::string apiUrl = "https://kinopoiskapiunofficial.tech/api/v2.2/films/top?type=TOP_250_BEST_FILMS&page=1";
    const std::string apiKey = "465e660a-218c-4f1b-b072-ac7daa1b6e81";
};

#endif //LABS_2_COURS_TOPPARSER_H
