//
// Created by rattus on 26.05.2021.
//

#ifndef GAME_OF_LIFE_CELL_H
#define GAME_OF_LIFE_CELL_H

#include "../../Config/consts.h"
#include <cstdlib>
#include "../statuses.h"

class Cell {
public:

    Cell() : status(Dead), next_status(Dead) {};

    Status get_status();

    void reverse();

    void set_next_status(Status next);

    void update();

    void set_status(Status status);

private:
    Status status;

    Status next_status;
};


#endif //GAME_OF_LIFE_CELL_H
