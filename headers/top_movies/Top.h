//
// Created by vova3 on 03.12.2024.
//

#ifndef LABS_2_COURS_TOP_H
#define LABS_2_COURS_TOP_H

#include <curl/curl.h>
#include <nlohmann/json.hpp>

#include <iostream>
#include <string>

class HttpClient {
public:
    explicit HttpClient(const std::string& apiKey);

    ~HttpClient();

    std::string get(const std::string& url);

private:
    CURL* curl;
    std::string apiKey;

    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp);
};
#endif //LABS_2_COURS_TOP_H
