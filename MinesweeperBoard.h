//
// Created by samsepiol on 3/9/20.
//

#ifndef SAPER_MINESWEEPERBOARD_H
#define SAPER_MINESWEEPERBOARD_H

#include <vector>
struct Field{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;

};
class MinesweeperBoard {
    Field board[100][100];
    int width;
    int height;

    bool gameOver;
    bool firstClick = true;
    int minesCounter = 0;
    int unrevealedFields = 0;

    int isMine(int x, int y) const;
    bool isCorrectField(int x, int y) const;
    void addNewMine();
    void removeMine(int x, int y);
    int countMines(int x, int y) const;
    void revealAllMines();



    //char fieldType(int x, int y) const;

public:
    char fieldType(int x, int y) const; //fordebug
    MinesweeperBoard(int width, int height);
    void NewGame();
    void reveal(int x, int y );

    void debug_display() const;
    void console_display() const;
    bool isGameover() const;
    bool hasWon();
    bool isFlagged(int x, int y);
    void setFlag(int x, int y);
    std::vector <int> getSize() const;




};


#endif //SAPER_MINESWEEPERBOARD_H
