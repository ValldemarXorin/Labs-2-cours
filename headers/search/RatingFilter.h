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
    explicit RatingFilter(bool ascending);

    MyVector<Movie> apply(MyVector<Movie> movies) override;

    ~RatingFilter() override = default;
};
#endif //LABS_2_COURS_RATINGFILTER_H
