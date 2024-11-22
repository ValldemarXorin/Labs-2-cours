//
// Created by vova3 on 17.11.2024.
//

#ifndef LABS_2_COURS_SEARCH_ENGINE_H
#define LABS_2_COURS_SEARCH_ENGINE_H
#include "../repositories/IMoviesRepository.h"
#include "Filters.h"
#include <vector>
#include <algorithm>

class SearchEngine {
    std::vector<Movie> movies;
    //Filters filters;
    IMoviesRepository movies_repository;
    //bool isFilterExecute;
    //bool isFilterActive;
public:
    SearchEngine(IMoviesRepository movies_repository);

    std::vector<Movie> search_by_fragment(std::string title_fragment, bool get_back);
};
#endif //LABS_2_COURS_SEARCH_ENGINE_H
