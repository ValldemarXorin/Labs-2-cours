//
// Created by vova3 on 28.11.2024.
//

#ifndef LABS_2_COURS_IFILTER_H
#define LABS_2_COURS_IFILTER_H
#include "../models/Movie.h"
#include "../MyVector.h"
#include <vector>
#include <algorithm>
#include <functional>

class IFilter {
public:
    virtual MyVector<Movie> apply(MyVector<Movie> movies) = 0;
    virtual ~IFilter() {};
};
#endif //LABS_2_COURS_IFILTER_H
