cmake_minimum_required(VERSION 3.29)
project(Labs-2-cours)

set(CMAKE_CXX_STANDARD 20)



set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/Qt/6.7.3/mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

qt6_wrap_ui(UI_HEADERS ${UI_FILES})

# Укажите путь к папке, куда вы распаковали SQLite
set(SQLITE3_DIR "${CMAKE_SOURCE_DIR}/SQLiteLibrary") # Замените <version> на актуальную папку#


add_executable(Labs-2-cours
        ${SQLITE3_DIR}/sqlite3.c
        ${SQLITE3_DIR}/sqlite3.h
        source/main.cpp
        headers/models/Movie.h
        source/models/Movie.cpp
        headers/database/DBManager.h
        headers/map_requests.h
        source/interface/MainWindow.cpp
        headers/interface/MainWindow.h
        source/interface/MainWindow.ui
        headers/database/MoviesDBManager.h
        source/database/MoviesDBManager.cpp
        headers/repositories/IMoviesRepository.h
        source/repositories/IMoviesRepository.cpp
        headers/filters/MovieFilters.h
        headers/filters/Filters.h
        headers/MovieErrorExceptions.h
        source/MovieErrorExceptions.cpp
)

target_link_libraries(Labs-2-cours
        Qt::Core
        Qt::Gui
        Qt::Widgets
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

