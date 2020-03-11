//
// Created by samsepiol on 3/9/20.
//

#ifndef SAPER_GUIFIELD_H
#define SAPER_GUIFIELD_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "MinesweeperBoard.h"

class GUIField{

    int width;
    int boardX;
    int boardY;
    sf::Texture icon;
    char state;

public:
    GUIField(int width, int boardX, int boardY, char state);
    void Update(MinesweeperBoard board);
    sf::Vector2f getPosition() const;
    sf::Vector2f getBoardPosition() const;
    int getWidth() const;
    char getState() const;
    bool isClicked(float mouseX, float mouseY)const;
    //void updateSize(int width);



};


#endif //SAPER_GUIFIELD_H
