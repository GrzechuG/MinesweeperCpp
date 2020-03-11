#include <iostream>
#include "MinesweeperBoard.h"
#include "GUI.h"
int main() {
    MinesweeperBoard board(20, 20);
   // board.debug_display();
//    for(int i = 0; i<10; i++){
//        if(board.fieldType(i,5)==' '){
//            board.reveal(i,5);
//        }
//    }
   // std::cout<<board.fieldType(4,4)<<std::endl;
   // board.reveal(4,4);
   board.debug_display();

    //board.console_display();

    GUI gameWindow(board);



    return 0;
}
