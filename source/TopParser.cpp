//
// Created by vova3 on 13.12.2024.
//

#include "../headers/TopParser.h"

TopParser::TopParser() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
}

// Деструктор для завершения работы cURL
TopParser::~TopParser() {
    curl_global_cleanup();
}

// Обработчик для записи данных из cURL в строку
size_t TopParser::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    size_t totalSize = size * nmemb;
    userp->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

// Метод для выполнения HTTP-запроса
std::string TopParser::perform_request(const std::string& url, const std::string& apiKey) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        throw std::runtime_error("Failed to initialize CURL");
    }

    std::string responseString;
    CURLcode res;

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "accept: application/json");
    headers = curl_slist_append(headers, ("X-API-KEY: " + apiKey).c_str());

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseString);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
        throw std::runtime_error(std::string("CURL error: ") + curl_easy_strerror(res));
    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    return responseString;
}

std::vector<Movie> TopParser::parse_movies(const std::string& responseString, const std::vector<Movie>& all_movies) {
    std::vector<Movie> movies;

    try {
        auto jsonResponse = json::parse(responseString);

        for (const auto& film : jsonResponse["films"]) {
            std::string title = film.contains("nameRu") && !film["nameRu"].is_null() ? film["nameRu"].get<std::string>() : "N/A";
            int release_year = film.contains("year") && !film["year"].is_null() ? std::stoi(film["year"].get<std::string>()) : 0;

            int id, link_id;
            for (const auto& db_movie : all_movies) {
                if (db_movie.get_title() == title && db_movie.get_release_year() == release_year) {
                    movies.emplace_back(db_movie);
                    break;
                }

            }
        }
    } catch (const std::exception& e) {
        throw std::runtime_error(std::string("JSON parsing error: ") + e.what());
    }

    return movies;
}

std::vector<Movie> TopParser::fetch_movies(const std::vector<Movie>& all_movies) {
    std::string response = perform_request(apiUrl, apiKey);
    return parse_movies(response, all_movies);
}