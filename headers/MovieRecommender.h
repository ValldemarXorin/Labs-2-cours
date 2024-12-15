//
// Created by vova3 on 15.12.2024.
//

#ifndef LABS_2_COURS_MOVIERECOMMENDER_H
#define LABS_2_COURS_MOVIERECOMMENDER_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <random>
#include <sstream>
#include <numeric>
#include "models/Movie.h"

class MovieRecommender {
private:
    std::vector<Movie> movies;
    std::unordered_map<std::string, int> genrePreferences;
    int preferredAgeRating = 0;
    int preferredDuration = 0;

    void analyzePreferences(const std::vector<Movie>& liked_movies);

    double calculateProbability(double value, double mean, double stddev) const;

    bool isLiked(const std::vector<Movie>& liked_movies, const Movie& movie) const;

    bool isInRecommendations(const std::vector<Movie>& recommendations, const Movie& movie) const;

    std::vector<Movie> findClosestByCriteria(const std::vector<Movie>& candidates, int target, bool byAge) const;


    void shuffleScores(std::vector<std::pair<Movie, double>>& scoredMovies) const;

public:
    MovieRecommender(const std::vector<Movie>& all_movies);

    std::vector<Movie> recommendMovies(
            const std::vector<Movie>& liked_movies,
            const std::string& genreFilter = "Genre",
            const std::string& ageFilter = "Age limit",
            const std::string& ratingFilter = "Rating",
            const std::string& runtimeFilter = "Runtime",
            const std::string& yearFilter = "Year");
};


#endif //LABS_2_COURS_MOVIERECOMMENDER_H
