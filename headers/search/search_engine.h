//
// Created by vova3 on 17.11.2024.
//

#ifndef LABS_2_COURS_SEARCH_ENGINE_H
#define LABS_2_COURS_SEARCH_ENGINE_H
#include "../repositories/IMoviesRepository.h"
#include <vector>
#include <algorithm>
#include <codecvt>
#include <locale>

class SearchEngine {
    //std::vector<Movie> movies;
    IMoviesRepository movies_repository;

    std::wstring to_lower_case(const std::wstring& input) {
        std::wstring result = input;
        std::transform(result.begin(), result.end(), result.begin(), [](wchar_t c) -> wchar_t {  // Указываем явно тип возвращаемого значения
            if (c >= L'A' && c <= L'Z') {
                return c + (L'a' - L'A');
            } else if (c >= L'А' && c <= L'Я') {
                return c + (L'а' - L'А');
            }
            return c;
        });
        return result;
    }

public:
    explicit SearchEngine(IMoviesRepository movies_repository);

    std::vector<Movie>& search_by_fragment(std::string title_fragment, std::vector<Movie>& movies,
                                          bool get_back, bool change_filters);
};
#endif //LABS_2_COURS_SEARCH_ENGINE_H
