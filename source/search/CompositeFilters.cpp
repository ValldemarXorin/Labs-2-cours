//
// Created by vova3 on 28.11.2024.
//
#include "../../headers/search/CompositeFilters.h"

std::vector<Movie> CompositeFilter::apply(std::vector<Movie> movies) {
    std::vector<Movie> result = movies;

    for (auto filter : filters) {
        result = filter->apply(result);
    }

    return result;
}

void CompositeFilter::addFilter(IFilter *filter) {
    filters.push_back(filter);
}

void CompositeFilter::removeFilter(IFilter *filter) {
    filters.erase(std::remove(filters.begin(), filters.end(), filter), filters.end());
}

CompositeFilter::~CompositeFilter() noexcept {
    for (auto filter : filters) {
        delete filter;
    }
}