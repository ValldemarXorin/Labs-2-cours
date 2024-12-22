cmake_minimum_required(VERSION 3.29)
project(Labs-2-cours)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

set(CMAKE_PREFIX_PATH "D:/Qt/6.7.3/mingw_64")
set(CMAKE_PREFIX_PATH "C:/Users/vova3/vcpkg/installed/x64-windows")
set(CMAKE_TOOLCHAIN_FILE "C:/Users/vova3/vcpkg/scripts/buildsystems/vcpkg.cmake")

#find_package(CURL REQUIRED)

set(CURL_INCLUDE_DIR "D:/cURL/include")  # Укажите путь к заголовочным файлам cURL
set(CURL_LIBRARY "D:/cURL/lib/libcurl.dll.a")  # Укажите путь к библиотеке cURL
include_directories("C:/Users/vova3/vcpkg/installed/x64-windows/include")

find_package(nlohmann_json REQUIRED)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Network
        REQUIRED)

qt6_wrap_ui(UI_HEADERS ${UI_FILES})

set(SQLITE3_DIR "${CMAKE_SOURCE_DIR}/SQLiteLibrary")

add_executable(Labs-2-cours
        ${SQLITE3_DIR}/sqlite3.c
        ${SQLITE3_DIR}/sqlite3.h
        source/main.cpp
        headers/models/Movie.h
        source/models/Movie.cpp
        headers/database/DBManager.h
        source/interface/MainWindow.cpp
        headers/interface/MainWindow.h
        source/interface/MainWindow.ui
        headers/database/MoviesDBManager.h
        source/database/MoviesDBManager.cpp
        headers/repositories/IMoviesRepository.h
        source/repositories/IMoviesRepository.cpp
        headers/MovieErrorExceptions.h
        source/MovieErrorExceptions.cpp
        source/interface/loginwindow.cpp
        headers/interface/loginwindow.h
        source/interface/loginwindow.ui
        headers/auth_models/User.h
        source/auth_models/User.cpp
        headers/UserErrorExceptions.h
        source/UserErrorExceptions.cpp
        headers/repositories/IUsersRepository.h
        headers/database/UsersDBManager.h
        source/database/UsersDBManager.cpp
        source/repositories/IUsersRepository.cpp
        headers/database/Database.h
        source/database/Database.cpp
        headers/search/search_engine.h
        source/search/search_engine.cpp
        source/interface/MovieCard.cpp
        headers/interface/MovieCard.h
        source/interface/MovieCard.ui
        headers/database/LikedDBManager.h
        source/interface/MovieCardInfo.cpp
        headers/interface/MovieCardInfo.h
        source/interface/MovieCardInfo.ui
        headers/search/IFilter.h
        headers/search/ICompositFilters.h
        headers/search/GenreFilter.h
        source/search/GenreFilter.cpp
        headers/search/YearFilter.h
        source/search/YearFilter.cpp
        headers/search/RuntimeFilter.h
        source/search/RuntimeFilter.cpp
        headers/search/RatingFilter.h
        source/search/RatingFilter.cpp
        headers/search/AgeLimitFilter.h
        source/search/AgeLimitFilter.cpp
        headers/search/CompositeFilters.h
        source/search/CompositeFilters.cpp
        source/interface/FiltersWindow.cpp
        headers/interface/FiltersWindow.h
        source/interface/FiltersWindow.ui
        headers/MyVector.h
        source/database/LikedDBManager.cpp
        headers/models/LikedMovie.h
        source/models/LikedMovie.cpp
        headers/repositories/LikedRepository.h
        source/repositories/LikedRepository.cpp
        headers/JSONMovieCollection.h
        source/JSONMovieCollection.cpp
        headers/TopParser.h
        source/TopParser.cpp
        headers/MovieRecommender.h
        source/MovieRecommender.cpp
        source/interface/AdminWindow.cpp
        headers/interface/AdminWindow.h
        source/interface/AdminWindow.ui
        source/interface/FiltersWindowSearch.cpp
        headers/interface/FiltersWindowSearch.h
        source/interface/FiltersWindowSearch.ui
)

include_directories(${CURL_INCLUDE_DIR})

target_link_libraries(Labs-2-cours
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network
        ${CURL_LIBRARY}
        nlohmann_json
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

