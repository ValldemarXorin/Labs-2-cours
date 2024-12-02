//
// Created by vova3 on 28.11.2024.
//

#ifndef LABS_2_COURS_YEARFILTER_H
#define LABS_2_COURS_YEARFILTER_H
#include "IFilter.h"
class YearFilter : public IFilter {
private:
    int release_year;

public:
    explicit YearFilter(int y);

    std::vector<Movie> apply(std::vector<Movie> movies) override;

    ~YearFilter() override = default;
};
#endif //LABS_2_COURS_YEARFILTER_H
