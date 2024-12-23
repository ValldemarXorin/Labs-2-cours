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

    std::wstring to_lower_case(const std::wstring& input);

public:
    explicit SearchEngine(IMoviesRepository movies_repository);

    std::vector<Movie>& search_by_fragment(std::string title_fragment, IMoviesRepository& movies_repository,
                                           std::vector<Movie>& movies,
                                          bool get_back, bool change_filters);
};
#endif //LABS_2_COURS_SEARCH_ENGINE_H
