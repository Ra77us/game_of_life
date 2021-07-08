
#include "window_wrapper.h"

void WindowWrapper::run() {
    sf::RenderWindow window(sf::VideoMode(X_RES, Y_RES), "Game of life",
                            sf::Style::Titlebar | sf::Style::Close);
    sf::Text main_label;
    sf::Font font;
    font.loadFromFile(FONT_FILE);
    main_label.setFont(font);
    main_label.setCharacterSize(15);
    std::string label = "Welcome to game of life\n"
                        "Hotkeys: \n"
                        "Start/stop simulation - SPACE\n"
                        "Restart Simulation - R\n"
                        "Use right button to switch to spawning mode, select object number "
                        "from keyboard, use arrows to rotate and press S to spawn objects:\n";

    std::ifstream file(PATTERN_FILE);
    std::string name;
    int skip;
    if (!file)
        throw std::invalid_argument("No file found!");

    for (int i = 0; i < PATTERNS_NUM; i++) {
        std::getline(file, name);
        label += std::to_string(i) + " - " + name + "   ";
        file >> skip;
        file >> skip;
        for (int j = 0; j <= skip; j++) {
            std::getline(file, name);
        }
    }
    file.close();
    main_label.setString(label);

    sf::Clock clock;
    clock.restart();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    handle_key(&event);
                    break;
                case sf::Event::MouseButtonPressed:
                    handle_mouse(&event);
                    break;
                default:
                    break;
            }
        }
        repaint(window, main_label);
        if (clock.getElapsedTime() > REFRESH_DELAY) {
            board->update_board();
            clock.restart();
        }
    }
}

void WindowWrapper::repaint(sf::RenderWindow &window, sf::Text &main_label) const {
    window.clear();
    for (size_t i = 0; i < board->get_x_size(); i++) {
        for (size_t j = 0; j < board->get_y_size(); j++) {
            sf::Color color = (board->get_status_at(i, j) == Alive) ? WHITE : BLACK;
            painter::paint_cell(window, i * CELL_SIZE, j * CELL_SIZE + Y_OFFSET, color);
        }
    }
    if (state == State::Spawning)
        spawner->paint_preview(window);
    window.draw(main_label);
    window.display();
}

void WindowWrapper::handle_key(sf::Event *event) {
    switch (event->key.code) {
        case sf::Keyboard::Space:
            if (state == Running)
                state = State::Paused;
            else
                state = State::Running;
            board->change_running_state();
            break;
        case sf::Keyboard::R:
            state = State::Paused;
            board->reset();
            break;
        case sf::Keyboard::S:
            if (state == State::Spawning) {
                state = State::Paused;
                if (!board->get_running_state()) {
                    spawner->spawn();
                }
            }
            break;
        case sf::Keyboard::Right:
            if (state == State::Spawning)
                spawner->rotate_pattern(false);
            break;
        case sf::Keyboard::Left:
            if (state == State::Spawning)
                spawner->rotate_pattern(true);
            break;
        case sf::Keyboard::Num0:
            if (state == State::Spawning)
                spawner->set_spawn_pattern(0);
            break;
        case sf::Keyboard::Num1:
            if (state == State::Spawning)
                spawner->set_spawn_pattern(1);
            break;
        case sf::Keyboard::Num2:
            if (state == State::Spawning)
                spawner->set_spawn_pattern(2);
            break;
        case sf::Keyboard::Num3:
            if (state == State::Spawning)
                spawner->set_spawn_pattern(3);
            break;
        case sf::Keyboard::Num4:
            if (state == State::Spawning)
                spawner->set_spawn_pattern(4);
            break;
        default:
            break;
    }
}

void WindowWrapper::handle_mouse(sf::Event *event) {
    if (state == State::Running)
        return;
    clicked_x = event->mouseButton.x / CELL_SIZE;
    clicked_y = (event->mouseButton.y - Y_OFFSET) / CELL_SIZE;
    if (!(clicked_x >= 0 && clicked_x < BOARD_SIZE_X && clicked_y >= 0 && clicked_y < BOARD_SIZE_Y))
        return;
    if (event->mouseButton.button == sf::Mouse::Left) {
        if (state == State::Paused)
            board->reverse_at(clicked_x, clicked_y);
    } else {
        if (state == State::Spawning) {
            state = State::Paused;
        } else {
            spawner->set_spawn_position(clicked_x, clicked_y);
            state = State::Spawning;
        }
    }
}
