//
// Created by vova3 on 15.12.2024.
//

#include "../headers/MovieRecommender.h"

void MovieRecommender::analyzePreferences(const std::vector<Movie> &liked_movies)  {
    int totalAge = 0;
    int totalDuration = 0;

    for (const auto& movie : liked_movies) {
        genrePreferences[movie.get_genre()]++;
        totalAge += movie.get_int_age_limit();
        totalDuration += movie.get_runtime_minutes();
    }

    if (!liked_movies.empty()) {
        preferredAgeRating = totalAge / liked_movies.size();
        preferredDuration = totalDuration / liked_movies.size();
    }
}

double MovieRecommender::calculateProbability(double value, double mean, double stddev) const {
    double exponent = std::exp(-0.5 * std::pow((value - mean) / stddev, 2));
    return (1.0 / (stddev * std::sqrt(2 * M_PI))) * exponent;
}

bool MovieRecommender::isLiked(const std::vector<Movie> &liked_movies, const Movie &movie) const {
    return std::any_of(liked_movies.begin(), liked_movies.end(), [&movie](const Movie& liked) {
        return liked.get_id() == movie.get_id();
    });
}

bool MovieRecommender::isInRecommendations(const std::vector<Movie> &recommendations, const Movie &movie) const {
    return std::any_of(recommendations.begin(), recommendations.end(), [&movie](const Movie& recommended) {
        return recommended.get_id() == movie.get_id();
    });
}

std::vector<Movie>
MovieRecommender::findClosestByCriteria(const std::vector<Movie> &candidates, int target, bool byAge) const {
    if (candidates.empty()) {
        throw std::runtime_error("No candidates available for selection.");
    }

    double mid_diff = 0;
    std::vector<std::pair<Movie, int>> diffs;
    for (const auto& movie : candidates) {
        int diff = byAge ? std::abs(movie.get_int_age_limit() - target) : std::abs(movie.get_runtime_minutes() - target);
        mid_diff += static_cast<double>(diff);
        diffs.push_back({movie, diff});
    }
    mid_diff /= diffs.size() * 10;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> noise(0, mid_diff);

    for (auto& pair : diffs) {
        pair.second += noise(gen);
    }

    std::sort(diffs.begin(), diffs.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    std::vector<Movie> sort_closest;
    for (auto& diff: diffs) {
        sort_closest.push_back(diff.first);
    }

    return sort_closest;
}

void MovieRecommender::shuffleScores(std::vector<std::pair<Movie, double>> &scoredMovies) const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::normal_distribution<> noise(0, 0.4);

    for (auto& pair : scoredMovies) {
        pair.second += noise(gen);
    }
}

MovieRecommender::MovieRecommender(const std::vector<Movie> &all_movies)  : movies(all_movies) {}

std::vector<Movie>
MovieRecommender::recommendMovies(const std::vector<Movie> &liked_movies, const std::string &genreFilter,
                                 const std::string &ageFilter, const std::string &ratingFilter,
                                 const std::string &runtimeFilter, const std::string &yearFilter)  {

    if (liked_movies.empty()) {
        if (movies.size() < 5) {
            throw std::runtime_error("Not enough movies available for random selection.");
        }
        std::vector<Movie> randomRecommendations;
        std::vector<int> indices(movies.size());
        std::iota(indices.begin(), indices.end(), 0);

        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::shuffle(indices.begin(), indices.end(), gen);

        for (int i = 0; i < 5; ++i) {
            randomRecommendations.push_back(movies[indices[i]]);
        }
        return randomRecommendations;
    }

    analyzePreferences(liked_movies);
    std::vector<Movie> recommendations;
    std::vector<std::pair<Movie, double>> scoredMovies;

    for (const auto& movie : movies) {
        if (isLiked(liked_movies, movie)) continue;

        if (genreFilter != "Любой жанр" && movie.get_genre().find(genreFilter) == std::string::npos) continue;
        if (ageFilter != "Любой возраст" && movie.get_age_limit() != ageFilter) continue;
        if (ratingFilter != "Любой рейтинг" && ((ratingFilter == "Выше" && movie.get_rating() <= 7) || (ratingFilter == "Ниже" && movie.get_rating() > 7))) continue;
        if (runtimeFilter != "Любая длительность" && ((runtimeFilter == "Длиннее" && movie.get_runtime_minutes() <= 120) || (runtimeFilter == "Короче" && movie.get_runtime_minutes() > 120))) continue;
        if (yearFilter != "Любой год" && ((yearFilter == "Новые" && movie.get_release_year() < 2000) || (yearFilter == "Старые" && movie.get_release_year() >= 2000))) continue;

        std::string temp;
        std::vector<std::string> movie_genres;
        std::stringstream ss(movie.get_genre());
        while (getline(ss, temp, ',')) {
            temp.erase(0, temp.find_first_not_of(" \n\r\t"));
            temp.erase(temp.find_last_not_of(" \n\r\t") + 1);
            movie_genres.push_back(temp);
        }
        double genreScore = genrePreferences[movie_genres[0]] + genrePreferences[movie_genres[1]] + genrePreferences[movie_genres[2]];
        double ageScore = calculateProbability(movie.get_int_age_limit(), preferredAgeRating, std::sqrt(5.0)) / 18;
        double durationScore = calculateProbability(movie.get_runtime_minutes(), preferredDuration, 20.0) / 180;
        double ratingScore = movie.get_rating() / 10.0;

        double totalScore = genreScore * 2 + ageScore * 0.5 + durationScore * 0.5 + ratingScore;
        scoredMovies.push_back({movie, totalScore});
    }

    if (scoredMovies.empty())
        throw std::runtime_error("Нет фильмов для автоподбора");

    shuffleScores(scoredMovies);

    std::sort(scoredMovies.begin(), scoredMovies.end(),
              [](const auto& a, const auto& b) { return a.second > b.second; });

    for (size_t i = 0; i < 3 && i < scoredMovies.size(); ++i) {
        recommendations.push_back(scoredMovies[i].first);
    }

    std::vector<Movie> byAge;
    std::vector<Movie> byDuration;

    for (const auto& movie : movies) {
        if (!isLiked(liked_movies, movie) && !isInRecommendations(recommendations, movie)) {
            byAge.push_back(movie);
            byDuration.push_back(movie);
        }
    }

    if (!byAge.empty()) {
        std::vector<Movie> ageMovies = findClosestByCriteria(byAge, preferredAgeRating, true);
        for (auto& ageMovie: ageMovies) {
            if (!isInRecommendations(recommendations, ageMovie)) {
                recommendations.push_back(ageMovie);
                break;
            }
        }
    }

    if (!byDuration.empty()) {
        std::vector<Movie> durationMovies = findClosestByCriteria(byDuration, preferredDuration, false);
        for (auto& durationMovie: durationMovies) {
            if (!isInRecommendations(recommendations, durationMovie)) {
                recommendations.push_back(durationMovie);
                break;
            }
        }
    }

    return recommendations;
}