//
// Created by rattus on 31.05.2021.
//

#include "spawner.h"

void Spawner::spawn() {
    for (size_t i = 0; i < pattern_x_size; i++)
        for (size_t j = 0; j < pattern_y_size; j++) {
            if (x + i >= board->get_x_size() || y + j >= board->get_y_size())
                return;
            board->set_status_at(i + x, j + y, pattern[i][j]);
        }
}

void Spawner::paint_preview(sf::RenderWindow &window) const {
    for (size_t i = 0; i < pattern_x_size; i++) {
        for (size_t j = 0; j < pattern_y_size; j++) {
            sf::Color color = (pattern[i][j] == Alive) ? GREEN : RED;
            painter::paint_cell(window, (i + x) * CELL_SIZE, (j + y) * CELL_SIZE + Y_OFFSET, color);

        }
    }
}

void Spawner::set_spawn_position(size_t new_x, size_t new_y) {
    this->x = new_x;
    this->y = new_y;
}

void Spawner::set_spawn_pattern(size_t new_pattern) {
    std::ifstream file(PATTERN_FILE);
    std::string tmp;
    if (!file) {
        throw std::invalid_argument("No file found!");
    }
    int skip;
    std::getline(file, tmp);
    for (int i = 0; i < new_pattern; i++) {
        file >> skip;
        file >> skip;
        for (int j = 0; j < skip + 2; j++) {
            std::getline(file, tmp);
        }
    }
    file >> pattern_x_size;
    file >> pattern_y_size;
    for (size_t i = 0; i < pattern_y_size; i++) {
        for (size_t j = 0; j < pattern_x_size; j++) {
            int cell_status;
            file >> cell_status;
            pattern[j][i] = static_cast<Status>(cell_status);
        }
    }
    file.close();
}

void Spawner::rotate_pattern(bool left) {
    Status tmp_pattern[MAX_PATTERN_SIZE][MAX_PATTERN_SIZE];
    for (size_t i = 0; i < pattern_x_size; i++)
        for (size_t j = 0; j < pattern_y_size; j++)
            tmp_pattern[i][j] = pattern[i][j];

    for (size_t i = 0; i < pattern_y_size; i++)
        for (size_t j = 0; j < pattern_x_size; j++){
            if(left)
                pattern[i][j] = tmp_pattern[j][pattern_y_size - 1 - i];
            else
                pattern[i][j] = tmp_pattern[pattern_x_size - 1 - j][i];
        }

    std::swap(pattern_x_size, pattern_y_size);
}
