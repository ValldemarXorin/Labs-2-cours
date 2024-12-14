//
// Created by vova3 on 13.12.2024.
//

#include "../headers/TopParser.h"

TopParser::TopParser() {
    curl_global_init(CURL_GLOBAL_DEFAULT); // Инициализация cURL
}


size_t TopParser::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    size_t totalSize = size * nmemb;
    userp->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

void TopParser::fetch_movies() {
    CURL* curl = curl_easy_init();
    if (curl) {
        std::string readBuffer;
        curl_easy_setopt(curl, CURLOPT_URL, "https://kinopoiskapiunofficial.tech/api/v2.2/films/top?type=TOP_100_POPULAR_FILMS&page=1");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Установка заголовков
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "X-API-KEY: 465e660a-218c-4f1b-b072-ac7daa1b6e81");
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "Response: " << readBuffer << std::endl;

//            // Десериализация JSON
//            try {
//                json jsonResponse = json::parse(readBuffer);
//                // Обработка данных из jsonResponse
//                for (const auto& film : jsonResponse["films"]) {
//                    std::cout << "Film: " << film["name"] << ", Rating: " << film["rating"] << std::endl;
//                }
//            } catch (json::parse_error& e) {
//                std::cerr << "Ошибка парсинга JSON: " << e.what() << std::endl;
//            }
//        }
        }

        // Очистка
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}