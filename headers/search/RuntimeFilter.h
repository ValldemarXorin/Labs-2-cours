//
// Created by vova3 on 28.11.2024.
//

#ifndef LABS_2_COURS_RUNTIMEFILTER_H
#define LABS_2_COURS_RUNTIMEFILTER_H
#include "IFilter.h"
class RuntimeFilter : public IFilter {
private:
    bool isAscending;

public:
    RuntimeFilter(bool ascending);

    std::vector<Movie> apply(std::vector<Movie> movies) override;

    ~RuntimeFilter() override = default;
};
#endif //LABS_2_COURS_RUNTIMEFILTER_H
