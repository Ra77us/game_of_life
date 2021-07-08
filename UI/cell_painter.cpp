//
// Created by rattus on 04.06.2021.
//

#include "cell_painter.h"

void painter::paint_cell(sf::RenderWindow &window, int x, int y, sf::Color color) {
    sf::RectangleShape cell_representation;
    cell_representation.setPosition(x, y);
    cell_representation.setSize(CELL_SIZE_VEC);
    cell_representation.setOutlineThickness(1);
    cell_representation.setOutlineColor(GRAY);
    cell_representation.setFillColor(color);
    window.draw(cell_representation);
}
