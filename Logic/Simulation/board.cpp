//
// Created by rattus on 26.05.2021.
//

#include "board.h"
#include <iostream>

Board::Board(size_t x, size_t y) : x_size(x), y_size(y), is_running(false) {
    array = new Cell *[x_size];
    for (size_t i = 0; i < x_size; i++) {
        array[i] = new Cell[y_size];
    }
}

Board::~Board() {
    for (size_t i = 0; i < x_size; i++) {
        delete[] array[i];
    }
    delete[] array;
}

void Board::update_board() const {
    if (!is_running)
        return;

    for (size_t i = 0; i < x_size; i++)
        for (size_t j = 0; j < y_size; j++)
            calculate_next_cell_status(i, j);

    for (size_t i = 0; i < x_size; i++)
        for (size_t j = 0; j < y_size; j++)
            array[i][j].update();
}

void Board::calculate_next_cell_status(size_t x, size_t y) const {
    int neighbours = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i + x < 0 || j + y < 0 || i + x > x_size - 1 || j + y > y_size - 1 || (i == 0 && j == 0))
                continue;
            if (array[i + x][j + y].get_status() == Alive) {
                neighbours++;
            }
        }
    }

    if (array[x][y].get_status() == Alive && (neighbours == 3 || neighbours == 2)) {
        array[x][y].set_next_status(Alive);
        return;
    }

    if (array[x][y].get_status() == Dead && neighbours == 3) {
        array[x][y].set_next_status(Alive);
        return;
    }
    array[x][y].set_next_status(Dead);
}


Status Board::get_status_at(size_t x, size_t y) const {
    return array[x][y].get_status();
}

size_t Board::get_x_size() const {
    return x_size;
}

size_t Board::get_y_size() const {
    return y_size;
}

void Board::reverse_at(size_t x, size_t y) const {
    array[x][y].reverse();
}

void Board::change_running_state() {
    is_running = !is_running;
}

bool Board::get_running_state() const {
    return is_running;
}

void Board::reset() {
    for (size_t i = 0; i < x_size; i++)
        for (size_t j = 0; j < y_size; j++)
            array[i][j].set_status(Dead);
    is_running = false;
}

void Board::set_status_at(size_t x, size_t y, Status status) const {
    array[x][y].set_status(status);
}

