//
// Created by vova3 on 28.11.2024.
//

#ifndef LABS_2_COURS_COMPOSITEFILTERS_H
#define LABS_2_COURS_COMPOSITEFILTERS_H
#include "IFilter.h"
#include "ICompositFilters.h"
#include "../MyVector.h"

class CompositeFilter : public IFilter, public ICompositFilters {
private:
    MyVector<IFilter*> filters;

public:
    void addFilter(IFilter* filter);

    MyVector<Movie> apply(MyVector<Movie> movies) override;

    void removeFilter(IFilter* filter) override;

    ~CompositeFilter() override;
};
#endif //LABS_2_COURS_COMPOSITEFILTERS_H
