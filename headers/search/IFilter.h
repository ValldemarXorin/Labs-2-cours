//
// Created by vova3 on 28.11.2024.
//

#ifndef LABS_2_COURS_IFILTER_H
#define LABS_2_COURS_IFILTER_H
#include "../models/Movie.h"
#include <vector>
#include <algorithm>

class IFilter {
public:
    virtual std::vector<Movie> apply(std::vector<Movie> movies) = 0;
    virtual ~IFilter() {};
};
#endif //LABS_2_COURS_IFILTER_H
