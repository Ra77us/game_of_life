//
// Created by rattus on 26.05.2021.
//

#ifndef GAME_OF_LIFE_BOARD_H
#define GAME_OF_LIFE_BOARD_H

#include <cstdlib>
#include "cell.h"
#include "../statuses.h"

class Board {

public:
    Board(size_t x, size_t y);

    ~Board();

    void update_board() const;

    void calculate_next_cell_status(size_t x, size_t y) const;

    size_t get_x_size() const;

    size_t get_y_size() const;

    Status get_status_at(size_t x, size_t y) const;

    void set_status_at(size_t x, size_t y, Status status) const;

    void reverse_at(size_t x, size_t y) const;

    void change_running_state();

    bool get_running_state() const;

    void reset();

private:
    const size_t x_size;

    const size_t y_size;

    Cell **array;

    bool is_running;

};


#endif //GAME_OF_LIFE_BOARD_H
