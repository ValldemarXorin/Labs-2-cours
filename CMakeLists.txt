cmake_minimum_required(VERSION 3.29)
project(Clion_project)

set(CMAKE_CXX_STANDARD 20)


# Укажите путь к папке, куда вы распаковали SQLite
set(SQLITE3_DIR "${CMAKE_SOURCE_DIR}/SQLiteLibrary") # Замените <version> на актуальную папку

# Добавьте исходные файлы SQLite
set(SQLITE3_SOURCES
        ${SQLITE3_DIR}/sqlite3.c
        sours/main.cpp
        sours/Movie.cpp
        sours/MovieDatabase.cpp
)

# Укажите заголовочные файлы
include_directories(${SQLITE3_DIR})


add_executable(Clion_project sours/main.cpp ${SQLITE3_SOURCES}
        headers/Movie.h
        headers/MovieDatabase.h
)
