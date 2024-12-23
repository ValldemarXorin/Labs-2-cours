//
// Created by vova3 on 17.11.2024.
//
#include "../../headers/search/search_engine.h"

SearchEngine::SearchEngine(IMoviesRepository movies_repository) : movies_repository(movies_repository) {}

std::vector<Movie>& SearchEngine::search_by_fragment(std::string title_fragment, IMoviesRepository& movies_repository,
                                                     std::vector<Movie>& movies,
                                                    bool get_back, bool change_filters) {

    std::string title_movie;

    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::wstring wide_title_fragment = converter.from_bytes(title_fragment);
    wide_title_fragment = to_lower_case(wide_title_fragment);

    if (get_back || change_filters) {
        movies = movies_repository.get_movies();
    }
    std::vector<Movie> result_movies;
    for(auto& movie: movies) {
        title_movie = movie.get_title();


        std::wstring wide_title_movie = converter.from_bytes(title_movie);


        wide_title_movie = to_lower_case(wide_title_movie);

        if (wide_title_movie.find(wide_title_fragment) == 0)
            result_movies.push_back(movie);
    }
    movies = result_movies;
    return movies;
}

std::wstring SearchEngine::to_lower_case(const std::wstring &input) {
    std::wstring result = input;
    std::transform(result.begin(), result.end(), result.begin(), [](wchar_t c) -> wchar_t {  // Указываем явно тип возвращаемого значения
        if (c >= L'A' && c <= L'Z') {
            return c + (L'a' - L'A');
        } else if (c >= L'А' && c <= L'Я') {
            return c + (L'а' - L'А');
        }
        return c;
    });
    return result;
}