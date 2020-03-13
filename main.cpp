#include <iostream>
#include "MinesweeperBoard.h"
#include "GUI.h"
int main() {
    MinesweeperBoard board(20, 20);
    board.debug_display();
    //board.console_display();
    GUI gameWindow(board);



    return 0;
}
