//
// Created by vova3 on 28.11.2024.
//
#include "../../headers/search/CompositeFilters.h"

MyVector<Movie> CompositeFilter::apply(MyVector<Movie> movies) {
    MyVector<Movie> result = movies;

    for (auto filter : filters) {
        result = filter->apply(result);
    }

    return result;
}

void CompositeFilter::addFilter(IFilter *filter) {
    filters.push_back(filter);
}

void CompositeFilter::removeFilter(IFilter *filter) {
    filters.remove(filter);
}

CompositeFilter::~CompositeFilter() noexcept {
    for (auto filter : filters) {
        delete filter;
    }
}