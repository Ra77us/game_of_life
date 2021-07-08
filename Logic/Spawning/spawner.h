//
// Created by rattus on 31.05.2021.
//

#ifndef GAME_OF_LIFE_SPAWNER_H
#define GAME_OF_LIFE_SPAWNER_H


#include <algorithm>
#include <fstream>
#include "../Simulation/board.h"
#include "../../Config/consts.h"
#include "../statuses.h"
#include "../../UI/cell_painter.h"

class Spawner {

public:

    explicit Spawner(Board *board) : board(board), x(0), y(0) {
        set_spawn_pattern(0);
    };

    void spawn();

    void paint_preview(sf::RenderWindow &window) const;

    void set_spawn_position(size_t new_x, size_t new_y);

    void set_spawn_pattern(size_t new_pattern);

    void rotate_pattern(bool left);


private:

    Board *board;

    Status pattern[MAX_PATTERN_SIZE][MAX_PATTERN_SIZE];

    size_t x;

    size_t y;

    size_t pattern_x_size;

    size_t pattern_y_size;

};


#endif //GAME_OF_LIFE_SPAWNER_H
