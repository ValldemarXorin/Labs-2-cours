//
// Created by vova3 on 13.12.2024.
//

#include "../headers/TopParser.h"

#include <fstream>
#include <ctime>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Конструктор TopParser
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
    if (is_file_recent()) {
        return load_movies_from_file();
    }
    std::vector<Movie> movies;
    try {
        std::string response = perform_request(apiUrl, apiKey);
        movies = parse_movies(response, all_movies);
        save_movies_to_file(movies);
    }
    catch (std::runtime_error& e) {
        movies = load_movies_from_file();
    }
    return movies;
}

void TopParser::save_movies_to_file(const std::vector<Movie>& movies) {
    // Получение текущей даты и времени
    std::time_t now = std::time(nullptr);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    std::string current_time(buffer);

    // Подготовка JSON-объекта для сохранения
    json outputJson;
    outputJson["parse_datetime"] = current_time;
    outputJson["movies"] = json::array();

    for (const auto& movie : movies) {
        json movieJson;
        movieJson["title"] = movie.get_title();
        movieJson["description"] = movie.get_description();
        movieJson["genre"] = movie.get_genre();
        movieJson["release_year"] = movie.get_release_year();
        movieJson["runtime"] = movie.get_runtime();
        movieJson["rating"] = movie.get_rating();
        movieJson["age_limit"] = movie.get_age_limit();
        movieJson["poster_link"] = movie.get_poster_link();
        movieJson["trailer_link"] = movie.get_trailer_link();
        outputJson["movies"].push_back(movieJson);
    }

    // Сохранение в файл
    std::ofstream outFile("top_movies.json");
    if (!outFile.is_open()) {
        throw std::runtime_error("Failed to open file for writing");
    }
    outFile << outputJson.dump(4); // Форматирование с отступом в 4 пробела
    outFile.close();
}

std::vector<Movie> TopParser::load_movies_from_file() {
    std::ifstream inFile("top_movies.json");
    if (!inFile.is_open()) {
        throw std::runtime_error("Failed to open file for reading");
    }

    json inputJson;
    inFile >> inputJson;
    inFile.close();

    std::vector<Movie> movies;
    for (const auto& movieJson : inputJson["movies"]) {
        movies.emplace_back(
                movieJson.value("id", 0),
                movieJson.value("title", "N/A"),
                movieJson.value("description", "N/A"),
                movieJson.value("genre", "N/A"),
                movieJson.value("release_year", 0),
                movieJson.value("runtime", "N/A"),
                movieJson.value("rating", 0.0f),
                movieJson.value("age_limit", "N/A"),
                movieJson.value("poster_link", "N/A"),
                movieJson.value("trailer_link", "N/A")
        );
    }

    return movies;
}

bool TopParser::is_file_recent() {
    std::ifstream inFile("top_movies.json");
    if (!inFile.is_open()) {
        return false;
    }

    json inputJson;
    inFile >> inputJson;
    inFile.close();

    std::string lastParseTime = inputJson.value("parse_datetime", "");
    if (lastParseTime.empty()) {
        return false;
    }

    std::tm lastParseTm = {};
    std::istringstream ss(lastParseTime);
    ss >> std::get_time(&lastParseTm, "%Y-%m-%d %H:%M:%S");
    if (ss.fail()) {
        return false;
    }

    std::time_t lastParseEpoch = std::mktime(&lastParseTm);
    std::time_t now = std::time(nullptr);

    return std::difftime(now, lastParseEpoch) <= 86; // 86400 секунд = 1 день
}

std::string TopParser::get_last_update_time() {
    std::ifstream inFile("top_movies.json");
    if (!inFile.is_open()) {
        throw std::runtime_error("Failed to open file for reading");
    }

    json inputJson;
    inFile >> inputJson;
    inFile.close();

    return inputJson.value("parse_datetime", "Unknown");
}
