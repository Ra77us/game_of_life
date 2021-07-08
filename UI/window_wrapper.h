//
// Created by rattus on 26.05.2021.
//

#ifndef GAME_OF_LIFE_WINDOW_WRAPPER_H
#define GAME_OF_LIFE_WINDOW_WRAPPER_H

#include <SFML/Graphics.hpp>
#include "../Config/consts.h"
#include "../Logic/Simulation/board.h"
#include "../Logic/Spawning/spawner.h"
#include "cell_painter.h"

enum State {
    Running,
    Paused,
    Spawning,
};

class WindowWrapper {
public:
    explicit WindowWrapper(Board *board, Spawner *spawner) :
            board(board), spawner(spawner), clicked_x(0), clicked_y(0), state(State::Paused) {}

    void run();

private:

    void repaint(sf::RenderWindow &window, sf::Text &main_label) const;

    void handle_key(sf::Event *event);

    void handle_mouse(sf::Event *event);

    State state;

    Board *board;

    Spawner *spawner;

    size_t clicked_x;

    size_t clicked_y;
};


#endif //GAME_OF_LIFE_WINDOW_WRAPPER_H
