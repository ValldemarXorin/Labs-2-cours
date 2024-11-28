//
// Created by vova3 on 28.11.2024.
//

#ifndef LABS_2_COURS_AGELIMITFILTER_H
#define LABS_2_COURS_AGELIMITFILTER_H
#include "IFilter.h"

class AgeLimitFilter : public IFilter {
private:
    std::string age_limit;

public:
    AgeLimitFilter(const std::string& limit);

    std::vector<Movie> apply(std::vector<Movie> movies) override;
};
#endif //LABS_2_COURS_AGELIMITFILTER_H
