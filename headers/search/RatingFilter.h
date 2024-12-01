//
// Created by vova3 on 28.11.2024.
//

#ifndef LABS_2_COURS_RATINGFILTER_H
#define LABS_2_COURS_RATINGFILTER_H
#include "IFilter.h"

class RatingFilter : public IFilter {
private:
    bool isAscending;

public:
    RatingFilter(bool ascending);

    std::vector<Movie> apply(std::vector<Movie> movies) override;

    ~RatingFilter() override = default;
};
#endif //LABS_2_COURS_RATINGFILTER_H
