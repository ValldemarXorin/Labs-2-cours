//
// Created by vova3 on 28.11.2024.
//

#ifndef LABS_2_COURS_GENREFILTER_H
#define LABS_2_COURS_GENREFILTER_H
#include "IFilter.h"
class GenreFilter : public IFilter {
private:
    std::string genre;

public:
    GenreFilter(std::string g);

    std::vector<Movie> apply(std::vector<Movie> movies) override;

    ~GenreFilter() override = default;
};
#endif //LABS_2_COURS_GENREFILTER_H
