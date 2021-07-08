#include "UI/window_wrapper.h"
#include "Config/consts.h"
#include "Logic/Spawning/spawner.h"

int main() {
    Board board(BOARD_SIZE_X, BOARD_SIZE_Y);
    Spawner spawner(&board);

    WindowWrapper window(&board, &spawner);
    window.run();
    return 0;
}