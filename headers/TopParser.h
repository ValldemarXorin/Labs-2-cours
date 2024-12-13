//
// Created by vova3 on 13.12.2024.
//

#ifndef LABS_2_COURS_TOPPARSER_H
#define LABS_2_COURS_TOPPARSER_H
#include <iostream>
#include <curl/curl.h>

class TopParser {
public:
    TopParser();
    void fetch_movies();

private:
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp);
};
#endif //LABS_2_COURS_TOPPARSER_H
