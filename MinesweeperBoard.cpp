//
// Created by samsepiol on 3/9/20.
//
#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include "MinesweeperBoard.h"
using std::cout;
using std::endl;

void MinesweeperBoard::console_display() const {
    for(int y = 0; y<height; y++) {
        for (int x = 0; x < width; x++) {

            cout<<"["<<fieldType(x,y)<<"]";
        }
        cout<<endl;
    }

}

void MinesweeperBoard::debug_display() const {


    for(int y = 0; y<height; y++){
        for(int x = 0; x<width; x++){
            Field s = board[x][y];
            cout<<"["<<(s.hasMine ? "M":".")<<"";
            cout<<""<<(s.isRevealed ? "o":".")<<"";
            cout<<""<<(s.hasFlag ? "f":".")<<"]";


        }
        cout<<endl;

    }
}


bool MinesweeperBoard::isCorrectField(int x, int y) const{
    return (x>=0 && y>=0 && x<width && y<height);
}

int MinesweeperBoard::isMine(int x, int y) const {
    if (isCorrectField(x, y)) {
        if (board[x][y].hasMine){
            return 1;
        }
    }
    return 0;

};

int MinesweeperBoard::countMines(int x, int y) const {
    int mines = 0;
    for(int i = -1; i<=1; i+=1){
        for(int j = -1; j<=1; j+=1){
            if(i!=0 || j!=0)
            if(isMine(x+i, y+j) == 1){
                mines++;
            }

        }
    }
    return mines;

};

void MinesweeperBoard::reveal(int x, int y){

    if(!board[x][y].isRevealed)
    if(isCorrectField(x, y)){

        board[x][y].isRevealed = true;
        unrevealedFields--;
        if(isMine(x, y)==1){
            if(firstClick){

                addNewMine();
                removeMine(x, y);

            }else {
                gameOver = true;
                revealAllMines();
            }
        }
        firstClick=false;

        if(fieldType(x,y)==' '){
            for(int i = -1; i<=1; i+=1){
                for(int j = -1; j<=1; j+=1){
                    if(i!=0 || j!=0)
                        if(!isMine(x+i, y+j) && !board[x+i][y+j].isRevealed)
                             reveal(x+i, y+j);

                }
            }
        }
    }

}

bool MinesweeperBoard::isGameover() const {
    return gameOver;

}

 MinesweeperBoard::MinesweeperBoard(int width, int height, float bomb_percent):width(width), height(height), bomb_percent(bomb_percent)
{
    NewGame();
}

char MinesweeperBoard::fieldType(int x, int y) const {
    if(isCorrectField(x,y)){
        if(board[x][y].isRevealed){
            if(isMine(x,y) == 1){
                return 'x';
            }else{
                int mines_around = countMines(x,y);

                if(mines_around == 0){
                    return ' ';
                }else{
                    return '0'+mines_around;
                }
            }

        }else{
            if(board[x][y].hasFlag){
                return 'F';
            }
            return '#';
        }
    }
    return '?';
};

void MinesweeperBoard::setFlag(int x, int y) {
    if(isCorrectField(x,y)){
        board[x][y].hasFlag=!board[x][y].hasFlag;
    }
}

void MinesweeperBoard::NewGame() {

    unrevealedFields = height*width;

    for(int y = 0; y<height; y++){
        for(int x = 0; x<width; x++){

            board[x][y] = (Field){false, false, false};

        }

    }

    srand (time(NULL));
    int minesToGenerate = (int)(bomb_percent*width*height);
    for(int i = 0; i < minesToGenerate; i++){

        addNewMine();
        /*
         * Calosc jest zrobiona w taki 'dziwny' sposob,
         * aby na pewno dwa razy nie wygenerowal w tym samym miejscu dwa razy miny.
         */
    }

}

std::vector<int> MinesweeperBoard::getSize() const{
    std::vector <int> size = {width,height};
    return size;
}

bool MinesweeperBoard::isFlagged(int x, int y) {
    if(isCorrectField(x,y))
        return (board[x][y].hasFlag);

    return false;


}

void MinesweeperBoard::addNewMine() {
    minesCounter++;
    int x, y;
    bool finish = false;
    do {
        x = rand() % (width);
        y = rand() % (height);

        if (!isMine(x, y)) {
            finish = true;
        }

        board[x][y].hasMine = true;

    }while(!finish);
}

void MinesweeperBoard::removeMine(int x, int y) {
    board[x][y].hasMine=false;
}

bool MinesweeperBoard::hasWon() {

    if(unrevealedFields == minesCounter){
        gameOver = true;

        return true;
    }
    return false;
}

void MinesweeperBoard::revealAllMines() {
    for(int y = 0; y<height; y++) {
        for (int x = 0; x < width; x++) {
            if(isMine(x,y)){
                reveal(x,y);
            }

        }
    }
}
