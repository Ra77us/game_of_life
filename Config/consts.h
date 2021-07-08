//
// Created by rattus on 26.05.2021.
//

#ifndef GAME_OF_LIFE_CONSTS_H
#define GAME_OF_LIFE_CONSTS_H

#include <cstdlib>
#include <SFML/Graphics.hpp>

#define WHITE sf::Color::White
#define BLACK sf::Color::Black
#define GRAY sf::Color(153, 153, 153)
#define GREEN sf::Color::Green
#define RED sf::Color::Red

constexpr size_t X_RES = 1040;
constexpr size_t Y_RES = 900;
constexpr size_t Y_OFFSET = 120;

constexpr size_t CELL_SIZE = 13;
const sf::Vector2f CELL_SIZE_VEC(CELL_SIZE, CELL_SIZE);

constexpr size_t BOARD_SIZE_X = X_RES / CELL_SIZE;
constexpr size_t BOARD_SIZE_Y = (Y_RES - Y_OFFSET) / CELL_SIZE;

const sf::Time REFRESH_DELAY = sf::microseconds(20000);

constexpr size_t MAX_PATTERN_SIZE = 40;
const size_t PATTERNS_NUM = 5;

const std::string PATTERN_FILE = "./Config/patterns.txt";
const std::string FONT_FILE = "./Fonts/arial.ttf";

#endif //GAME_OF_LIFE_CONSTS_H
