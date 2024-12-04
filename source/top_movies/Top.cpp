//
// Created by vova3 on 04.12.2024.
//
#include "../../headers/top_movies/Top.h"

HttpClient::HttpClient(const std::string &apiKey) : apiKey(apiKey) {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
}

HttpClient::~HttpClient() {
    if (curl) {
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

std::string HttpClient::get(const std::string &url) {
    if (!curl) return "";

    std::string readBuffer;

    // Укажите URL для запроса
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    // Установите заголовки
    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Accept: application/json");
    std::string apiKeyHeader = "X-API-KEY: " + apiKey;
    headers = curl_slist_append(headers, apiKeyHeader.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // Установите функцию обратного вызова для записи ответа
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    // Выполните запрос
    CURLcode res = curl_easy_perform(curl);

    // Очистка заголовков
    curl_slist_free_all(headers);

    // Проверьте ошибки
    if (res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        return "";
    }

    return readBuffer;
}

size_t HttpClient::WriteCallback(void *contents, size_t size, size_t nmemb, std::string *userp) {
    size_t totalSize = size * nmemb;
    userp->append((char*)contents, totalSize);
    return totalSize;
}