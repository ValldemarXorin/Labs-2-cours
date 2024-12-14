#include <iostream>
#include "../headers/models/Movie.h"
#include "../SQLiteLibrary/sqlite3.h"
#include "../headers/repositories/IMoviesRepository.h"
#include "../headers/repositories/LikedRepository.h"
#include "../headers/interface/MainWindow.h"
#include "../headers/interface/loginwindow.h"
#include <QApplication>
#include <memory>




#include "../headers/TopParser.h"
#include "nlohmann/json.hpp"


int main(int argc, char* argv[]) {
//    QApplication app(argc, argv);
//
//    IUserRepository users;
//    IMoviesRepository movies;
//    LikedRepository liked_movies;
//
//    LoginWindow loginWindow(&movies, &users, &liked_movies);
//    loginWindow.show();
//
//    return app.exec();

    TopParser parser; // Создание объекта парсера
    parser.fetch_movies(); // Запуск функции для получения фильмов

    return 0; // Запуск цикла событий
}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//#include <algorithm>
//#include <cmath>
//#include <random>
//#include <sstream>
//#include <numeric>
//
//struct Movi {
//    std::string title;
//    std::string genre;
//    std::string ageRating;
//    std::string duration;
//    double rating;
//    int year;
//
//    int getAgeRating() const {
//        return std::stoi(ageRating.substr(0, ageRating.size() - 1));
//    }
//
//    int getDurationMinutes() const {
//        std::istringstream iss(duration);
//        int hours, minutes, seconds;
//        char colon;
//        iss >> hours >> colon >> minutes >> colon >> seconds;
//        return hours * 60 + minutes;
//    }
//};
//
//class MoviRecommender {
//private:
//    std::vector<Movi> movies;
//    std::unordered_map<std::string, int> genrePreferences;
//    int preferredAgeRating = 0;
//    int preferredDuration = 0;
//
//    void analyzePreferences(const std::vector<Movi>& liked_movies) {
//        int totalAge = 0;
//        int totalDuration = 0;
//
//        for (const auto& movie : liked_movies) {
//            genrePreferences[movie.genre]++;
//            totalAge += movie.getAgeRating();
//            totalDuration += movie.getDurationMinutes();
//        }
//
//        if (!liked_movies.empty()) {
//            preferredAgeRating = totalAge / liked_movies.size();
//            preferredDuration = totalDuration / liked_movies.size();
//        }
//    }
//
//    double calculateProbability(double value, double mean, double stddev) const {
//        double exponent = std::exp(-0.5 * std::pow((value - mean) / stddev, 2));
//        return (1.0 / (stddev * std::sqrt(2 * M_PI))) * exponent;
//    }
//
//    bool isLiked(const std::vector<Movi>& liked_movies, const Movi& movie) const {
//        return std::any_of(liked_movies.begin(), liked_movies.end(), [&movie](const Movi& liked) {
//            return liked.title == movie.title;
//        });
//    }
//
//    bool isInRecommendations(const std::vector<Movi>& recommendations, const Movi& movie) const {
//        return std::any_of(recommendations.begin(), recommendations.end(), [&movie](const Movi& recommended) {
//            return recommended.title == movie.title;
//        });
//    }
//
//    std::vector<Movi> findClosestByCriteria(const std::vector<Movi>& candidates, int target, bool byAge) const {
//        if (candidates.empty()) {
//            throw std::runtime_error("No candidates available for selection.");
//        }
//
//        double mid_diff;
//        std::vector<std::pair<Movi, int>> diffs;
//        for (const auto& movie : candidates) {
//            int diff = byAge ? std::abs(movie.getAgeRating() - target) : std::abs(movie.getDurationMinutes() - target);
//            mid_diff += static_cast<double>(diff);
//            diffs.push_back({movie, diff});
//        }
//        mid_diff /= diffs.size() * 10;
//
//        std::random_device rd;
//        std::mt19937 gen(rd());
//        std::normal_distribution<> noise(0, mid_diff);
//
//        for (auto& pair : diffs) {
//            pair.second += noise(gen);
//        }
//
//        std::sort(diffs.begin(), diffs.end(), [](const auto& a, const auto& b) {
//            return a.second < b.second;
//        });
//
//        std::vector<Movi> sort_closest;
//        for (auto& diff: diffs) {
//            sort_closest.push_back(diff.first);
//        }
//
//        return sort_closest;
//    }
//
//
//    void shuffleScores(std::vector<std::pair<Movi, double>>& scoredMovies) const {
//        static std::random_device rd;
//        static std::mt19937 gen(rd());
//        std::normal_distribution<> noise(0, 0.4);
//
//        for (auto& pair : scoredMovies) {
//            pair.second += noise(gen);
//        }
//    }
//
//public:
//    MoviRecommender(const std::vector<Movi>& all_movies) : movies(all_movies) {}
//
//    std::vector<Movi> recommendMovies(
//            const std::vector<Movi>& liked_movies,
//            const std::string& genreFilter = "Genre",
//            const std::string& ageFilter = "Age limit",
//            const std::string& ratingFilter = "Rating",
//            const std::string& runtimeFilter = "Runtime",
//            const std::string& yearFilter = "Year") {
//
//        if (liked_movies.empty()) {
//            if (movies.size() < 5) {
//                throw std::runtime_error("Not enough movies available for random selection.");
//            }
//            std::vector<Movi> randomRecommendations;
//            std::vector<int> indices(movies.size());
//            std::iota(indices.begin(), indices.end(), 0);
//
//            static std::random_device rd;
//            static std::mt19937 gen(rd());
//            std::shuffle(indices.begin(), indices.end(), gen);
//
//            for (int i = 0; i < 5; ++i) {
//                randomRecommendations.push_back(movies[indices[i]]);
//            }
//            return randomRecommendations;
//        }
//
//        analyzePreferences(liked_movies);
//        std::vector<Movi> recommendations;
//        std::vector<std::pair<Movi, double>> scoredMovies;
//
//        for (const auto& movie : movies) {
//            if (isLiked(liked_movies, movie)) continue;
//
//            if (genreFilter != "Genre" && movie.genre != genreFilter) continue;
//            if (ageFilter != "Age limit" && movie.ageRating != ageFilter) continue;
//            if (ratingFilter != "Rating" && ((ratingFilter == "High" && movie.rating <= 7) || (ratingFilter == "Low" && movie.rating > 7))) continue;
//            if (runtimeFilter != "Runtime" && ((runtimeFilter == "Long" && movie.getDurationMinutes() <= 120) || (runtimeFilter == "Short" && movie.getDurationMinutes() > 120))) continue;
//            if (yearFilter != "Year" && ((yearFilter == "New" && movie.year < 2000) || (yearFilter == "Old" && movie.year >= 2000))) continue;
//
//            double genreScore = genrePreferences[movie.genre];
//            double ageScore = calculateProbability(movie.getAgeRating(), preferredAgeRating, std::sqrt(5.0)) / 18;
//            double durationScore = calculateProbability(movie.getDurationMinutes(), preferredDuration, 20.0) / 180;
//            double ratingScore = movie.rating / 10.0;
//
//            double totalScore = genreScore * 2 + ageScore * 0.5 + durationScore * 0.5 + ratingScore;
//            scoredMovies.push_back({movie, totalScore});
//        }
//
//        shuffleScores(scoredMovies);
//
//        std::sort(scoredMovies.begin(), scoredMovies.end(),
//                  [](const auto& a, const auto& b) { return a.second > b.second; });
//
//        for (size_t i = 0; i < 3 && i < scoredMovies.size(); ++i) {
//            recommendations.push_back(scoredMovies[i].first);
//        }
//
//        std::vector<Movi> byAge;
//        std::vector<Movi> byDuration;
//
//        for (const auto& movie : movies) {
//            if (!isLiked(liked_movies, movie) && !isInRecommendations(recommendations, movie)) {
//                byAge.push_back(movie);
//                byDuration.push_back(movie);
//            }
//        }
//
//        if (!byAge.empty()) {
//            std::vector<Movi> ageMovies = findClosestByCriteria(byAge, preferredAgeRating, true);
//            for (auto& ageMovie: ageMovies) {
//                if (!isInRecommendations(recommendations, ageMovie)) {
//                    recommendations.push_back(ageMovie);
//                    break;
//                }
//            }
//        }
//
//        if (!byDuration.empty()) {
//            std::vector<Movi> durationMovies = findClosestByCriteria(byDuration, preferredDuration, false);
//            for (auto& durationMovie: durationMovies) {
//                if (!isInRecommendations(recommendations, durationMovie)) {
//                    recommendations.push_back(durationMovie);
//                    break;
//                }
//            }
//        }
//
//        return recommendations;
//    }
//};
//
//
//int main() {
//    std::vector<Movi> movies = {
//            {"Inception", "Sci-Fi", "13+", "02:28:00", 8.8, 2010},
//            {"Titanic", "Romance", "12+", "03:15:00", 7.8, 1997},
//            {"The Dark Knight", "Action", "16+", "02:32:00", 9.0, 2008},
//            {"Shrek", "Animation", "0+", "01:30:00", 8.0, 2001},
//            {"Parasite", "Thriller", "16+", "02:12:00", 8.6, 2019},
//            {"Interstellar", "Sci-Fi", "13+", "02:49:00", 8.6, 2014},
//            {"Joker", "Drama", "18+", "02:02:00", 8.5, 2019},
//            {"Avengers", "Action", "13+", "02:23:00", 8.4, 2012},
//            {"Coco", "Animation", "0+", "01:45:00", 8.5, 2017},
//            {"The Lion King", "Animation", "0+", "01:28:00", 8.5, 1994},
//            {"The Matrix", "Sci-Fi", "16+", "02:16:00", 8.7, 1999},
//            {"Frozen", "Animation", "0+", "01:49:00", 7.5, 2013},
//            {"The Godfather", "Crime", "18+", "02:55:00", 9.2, 1972},
//            {"Pulp Fiction", "Crime", "18+", "02:34:00", 8.9, 1994},
//            {"Forrest Gump", "Drama", "13+", "02:22:00", 8.8, 1994},
//            {"The Shawshank Redemption", "Drama", "16+", "02:22:00", 9.3, 1994},
//            {"Toy Story", "Animation", "0+", "01:21:00", 8.3, 1995},
//            {"Finding Nemo", "Animation", "0+", "01:40:00", 8.1, 2003},
//            {"Gladiator", "Action", "16+", "02:35:00", 8.5, 2000},
//            {"Spirited Away", "Animation", "0+", "02:05:00", 8.6, 2001},
//            {"The Avengers: Endgame", "Action", "13+", "03:02:00", 8.4, 2019},
//            {"Black Panther", "Action", "13+", "02:14:00", 7.3, 2018},
//            {"The Incredibles", "Animation", "0+", "01:55:00", 8.0, 2004},
//            {"Spider-Man: Into the Spider-Verse", "Animation", "13+", "01:57:00", 8.4, 2018},
//            {"WALL-E", "Animation", "0+", "01:38:00", 8.4, 2008},
//            {"Up", "Animation", "0+", "01:36:00", 8.2, 2009},
//            {"Django Unchained", "Western", "18+", "02:45:00", 8.4, 2012},
//            {"The Wolf of Wall Street", "Biography", "18+", "02:59:00", 8.2, 2013},
//            {"Mad Max: Fury Road", "Action", "16+", "02:00:00", 8.1, 2015},
//            {"Guardians of the Galaxy", "Action", "13+", "02:01:00", 8.0, 2014},
//            {"The Lord of the Rings: The Fellowship of the Ring", "Fantasy", "12+", "02:58:00", 8.8, 2001},
//            {"The Lord of the Rings: The Two Towers", "Fantasy", "12+", "02:59:00", 8.8, 2002},
//            {"The Lord of the Rings: The Return of the King", "Fantasy", "12+", "03:21:00", 9.0, 2003},
//            {"The Hobbit: An Unexpected Journey", "Fantasy", "12+", "02:49:00", 7.8, 2012},
//            {"The Hunger Games", "Sci-Fi", "13+", "02:22:00", 7.2, 2012},
//            {"Avatar", "Sci-Fi", "13+", "02:42:00", 7.8, 2009},
//            {"Frozen II", "Animation", "0+", "01:43:00", 6.8, 2019},
//            {"Beauty and the Beast", "Fantasy", "0+", "01:30:00", 8.0, 1991},
//            {"Moana", "Animation", "0+", "01:47:00", 7.6, 2016},
//            {"Aladdin", "Animation", "0+", "01:30:00", 8.0, 1992},
//            {"Iron Man", "Action", "13+", "02:06:00", 7.9, 2008},
//            {"Captain America: The Winter Soldier", "Action", "13+", "02:16:00", 7.8, 2014},
//            {"Thor: Ragnarok", "Action", "13+", "02:10:00", 7.9, 2017},
//            {"Doctor Strange", "Action", "13+", "01:55:00", 7.5, 2016},
//            {"Ant-Man", "Action", "13+", "01:57:00", 7.3, 2015},
//            {"Wonder Woman", "Action", "13+", "02:21:00", 7.4, 2017},
//            {"Aquaman", "Action", "13+", "02:23:00", 6.8, 2018},
//            {"Man of Steel", "Action", "13+", "02:23:00", 7.1, 2013},
//            {"The Suicide Squad", "Action", "18+", "02:12:00", 7.2, 2021},
//            {"Zootopia", "Animation", "0+", "01:48:00", 8.0, 2016},
//            {"Big Hero 6", "Animation", "0+", "01:42:00", 7.8, 2014},
//            {"Ratatouille", "Animation", "0+", "01:51:00", 8.1, 2007},
//            {"Monsters, Inc.", "Animation", "0+", "01:32:00", 8.1, 2001},
//            {"Toy Story 3", "Animation", "0+", "01:43:00", 8.3, 2010},
//            {"Toy Story 4", "Animation", "0+", "01:40:00", 7.7, 2019},
//            {"Inside Out", "Animation", "0+", "01:35:00", 8.2, 2015},
//            {"Soul", "Animation", "0+", "01:40:00", 8.0, 2020},
//            {"The Good Dinosaur", "Animation", "0+", "01:33:00", 6.7, 2015},
//            {"Luca", "Animation", "0+", "01:35:00", 7.5, 2021},
//            {"Encanto", "Animation", "0+", "01:42:00", 7.2, 2021},
//            {"Brave", "Animation", "0+", "01:33:00", 7.1, 2012},
//            {"The Secret Life of Pets", "Animation", "0+", "01:27:00", 6.5, 2016},
//            {"Despicable Me", "Animation", "0+", "01:35:00", 7.6, 2010},
//            {"Minions", "Animation", "0+", "01:31:00", 6.4, 2015},
//            {"How to Train Your Dragon", "Animation", "0+", "01:38:00", 8.1, 2010},
//            {"Kung Fu Panda", "Animation", "0+", "01:32:00", 7.6, 2008},
//            {"Ice Age", "Animation", "0+", "01:21:00", 7.5, 2002},
//            {"The Croods", "Animation", "0+", "01:38:00", 7.2, 2013},
//            {"Hotel Transylvania", "Animation", "0+", "01:31:00", 7.1, 2012},
//            {"Megamind", "Animation", "0+", "01:36:00", 7.3, 2010},
//            {"The Lego Movie", "Animation", "0+", "01:40:00", 7.7, 2014},
//            {"Frozen Fever", "Animation", "0+", "00:08:00", 6.8, 2015},
//            {"Sing", "Animation", "0+", "01:48:00", 7.1, 2016},
//            {"The Boss Baby", "Animation", "0+", "01:37:00", 6.3, 2017},
//            {"Happy Feet", "Animation", "0+", "01:48:00", 6.4, 2006},
//            {"Bolt", "Animation", "0+", "01:36:00", 7.0, 2008},
//            {"The Peanuts Movie", "Animation", "0+", "01:28:00", 7.1, 2015},
//            {"Rio", "Animation", "0+", "01:36:00", 6.9, 2011},
//            {"The Lorax", "Animation", "0+", "01:26:00", 6.4, 2012},
//            {"Cloudy with a Chance of Meatballs", "Animation", "0+", "01:30:00", 6.9, 2009},
//            {"The Jungle Book", "Adventure", "0+", "01:46:00", 7.4, 2016},
//            {"Cinderella", "Fantasy", "0+", "01:52:00", 7.0, 2015},
//            {"Sleeping Beauty", "Animation", "0+", "01:15:00", 7.2, 1959},
//            {"The Little Mermaid", "Animation", "0+", "01:23:00", 7.6, 1989},
//            {"Mulan", "Animation", "0+", "01:28:00", 7.6, 1998},
//            {"Pocahontas", "Animation", "0+", "01:21:00", 6.7, 1995},
//            {"Tangled", "Animation", "0+", "01:40:00", 7.7, 2010},
//            {"Ralph Breaks the Internet", "Animation", "0+", "01:51:00", 7.0, 2018},
//            {"Hercules", "Animation", "0+", "01:33:00", 7.3, 1997},
//            {"Snow White and the Seven Dwarfs", "Animation", "0+", "01:23:00", 7.6, 1937},
//            {"Pinocchio", "Animation", "0+", "01:28:00", 7.4, 1940},
//            {"Dumbo", "Animation", "0+", "01:04:00", 7.2, 1941},
//            {"Bambi", "Animation", "0+", "01:10:00", 7.3, 1942},
//            {"The Aristocats", "Animation", "0+", "01:18:00", 7.1, 1970},
//            {"101 Dalmatians", "Animation", "0+", "01:19:00", 7.2, 1961},
//            {"Peter Pan", "Animation", "0+", "01:17:00", 7.3, 1953},
//            {"Lady and the Tramp", "Animation", "0+", "01:16:00", 7.4, 1955},
//            {"Beauty and the Beast (Live Action)", "Fantasy", "12+", "02:09:00", 7.1, 2017},
//            {"Alice in Wonderland", "Fantasy", "13+", "01:48:00", 6.4, 2010},
//            {"Maleficent", "Fantasy", "13+", "01:37:00", 7.0, 2014},
//            {"The Chronicles of Narnia: The Lion, the Witch and the Wardrobe", "Fantasy", "12+", "02:23:00", 6.9, 2005},
//            {"Fantastic Beasts and Where to Find Them", "Fantasy", "13+", "02:13:00", 7.2, 2016},
//            {"Harry Potter and the Sorcerer's Stone", "Fantasy", "12+", "02:32:00", 7.6, 2001},
//            {"Harry Potter and the Chamber of Secrets", "Fantasy", "12+", "02:41:00", 7.4, 2002},
//            {"Harry Potter and the Prisoner of Azkaban", "Fantasy", "12+", "02:22:00", 7.9, 2004},
//            {"Harry Potter and the Goblet of Fire", "Fantasy", "12+", "02:37:00", 7.7, 2005},
//            {"Harry Potter and the Order of the Phoenix", "Fantasy", "12+", "02:18:00", 7.5, 2007},
//            {"Harry Potter and the Half-Blood Prince", "Fantasy", "12+", "02:33:00", 7.6, 2009},
//            {"Harry Potter and the Deathly Hallows: Part 1", "Fantasy", "12+", "02:26:00", 7.7, 2010},
//            {"Harry Potter and the Deathly Hallows: Part 2", "Fantasy", "12+", "02:10:00", 8.1, 2011},
//            {"Percy Jackson & the Olympians: The Lightning Thief", "Fantasy", "12+", "01:58:00", 5.9, 2010},
//            {"The Twilight Saga: Breaking Dawn – Part 1", "Romance", "13+", "01:57:00", 4.9, 2011},
//            {"The Twilight Saga: Breaking Dawn – Part 2", "Romance", "13+", "02:02:00", 5.5, 2012},
//            {"The Fault in Our Stars", "Romance", "13+", "02:13:00", 7.7, 2014},
//            {"Me Before You", "Romance", "12+", "01:50:00", 7.4, 2016},
//            {"Pride and Prejudice", "Romance", "0+", "02:09:00", 7.8, 2005},
//            {"A Walk to Remember", "Romance", "12+", "01:41:00", 7.4, 2002},
//            {"The Notebook", "Romance", "12+", "02:04:00", 7.8, 2004},
//            {"La La Land", "Musical", "12+", "02:08:00", 8.0, 2016},
//            {"The Greatest Showman", "Musical", "12+", "01:45:00", 7.6, 2017},
//            {"Les Misérables", "Musical", "12+", "02:38:00", 7.5, 2012},
//            {"West Side Story", "Musical", "12+", "02:36:00", 7.6, 2021},
//            {"The Sound of Music", "Musical", "0+", "02:54:00", 8.0, 1965},
//            {"Grease", "Musical", "0+", "01:50:00", 7.2, 1978},
//            {"Pitch Perfect", "Comedy", "12+", "01:52:00", 7.1, 2012},
//            {"Mamma Mia!", "Musical", "12+", "01:48:00", 6.4, 2008},
//            {"Moulin Rouge!", "Musical", "12+", "02:07:00", 7.6, 2001}
//    };
//
//    std::vector<Movi> liked_movies = {
//            {"Ant-Man",           "Action", "13+", "01:57:00", 7.3, 2015},
//            {"Fantastic Beasts and Where to Find Them", "Fantasy", "13+", "02:13:00", 7.2, 2016},
//            {"Pitch Perfect", "Comedy", "12+", "01:52:00", 7.1, 2012},
//            {"The Twilight Saga: Breaking Dawn – Part 1", "Romance", "13+", "01:57:00", 4.9, 2011},
//            {"The Twilight Saga: Breaking Dawn – Part 2", "Romance", "13+", "02:02:00", 5.5, 2012},
//
//    };
//
//            MoviRecommender recommender(movies);
//
//    try {
//        for (int i = 0; i < 10; ++i) {
//            std::cout << "Run " << i + 1 << ":\n";
//            std::vector<Movi> recommendations = recommender.recommendMovies(liked_movies, "Genre", "Age limit", "Rating", "Runtime", "Year");
//
//            std::cout << "Recommended Movies:\n";
//            for (const auto& movie : recommendations) {
//                std::cout << "- " << movie.title << " (" << movie.genre << ")\n";
//            }
//            std::cout << "\n";
//        }
//    } catch (const std::exception& e) {
//        std::cerr << e.what() << '\n';
//    }
//
//    return 0;
//}

