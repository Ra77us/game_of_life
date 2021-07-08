//
// Created by rattus on 04.06.2021.
//

#ifndef GAME_OF_LIFE_CELL_PAINTER_H
#define GAME_OF_LIFE_CELL_PAINTER_H

#include <SFML/Graphics.hpp>
#include "../Config/consts.h"

namespace painter {
    void paint_cell(sf::RenderWindow &window, int x, int y, sf::Color color);
}


#endif //GAME_OF_LIFE_CELL_PAINTER_H
