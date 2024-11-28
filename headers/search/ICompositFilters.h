//
// Created by vova3 on 28.11.2024.
//

#ifndef LABS_2_COURS_ICOMPOSITFILTERS_H
#define LABS_2_COURS_ICOMPOSITFILTERS_H
#include "IFilter.h"
class ICompositFilters {
public:
    virtual void addFilter(IFilter* filter) = 0;
    virtual void removeFilter(IFilter* filter) = 0;
};
#endif //LABS_2_COURS_ICOMPOSITFILTERS_H
