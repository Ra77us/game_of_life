cmake_minimum_required(VERSION 3.17)
project(game_of_life)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "/home/rattus/Libraries/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/home/rattus/Libraries/SFML-2.5.1/lib")
set(SFML_DIR "/home/rattus/Libraries/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if (SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif ()

add_executable(game_of_life main.cpp Config/consts.h Logic/Simulation/cell.cpp Logic/Simulation/cell.h Logic/Simulation/board.cpp Logic/Simulation/board.h Logic/statuses.h UI/window_wrapper.cpp UI/window_wrapper.h Logic/Spawning/spawner.cpp Logic/Spawning/spawner.h UI/cell_painter.cpp UI/cell_painter.h)
target_link_libraries(game_of_life sfml-graphics sfml-window sfml-system)