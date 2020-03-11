//
// Created by samsepiol on 3/9/20.
//

#include "GUIField.h"

GUIField::GUIField(int width, int boardX, int boardY, char state)
: width(width), boardX(boardX), boardY(boardY), state(state)
{

}

void GUIField::Update(MinesweeperBoard board) {
    state = board.fieldType(boardX, boardY);
}

sf::Vector2f GUIField::getPosition() const{
    return {(float)(boardX*width),(float)(boardY*width)};
}

int GUIField::getWidth() const{
    return width;
}

char GUIField::getState() const{
    return state;
}

bool GUIField::isClicked(float mouseX, float mouseY) const {
    return getPosition().x < mouseX &&
           getPosition().y < mouseY &&
           getPosition().x + float(width) > mouseX &&
           getPosition().y + float(width) > mouseY;
}

sf::Vector2f GUIField::getBoardPosition() const {
    return sf::Vector2f(boardX,boardY);
}

//void GUIField::updateSize(int width) {
//    this -> width = width;
//}

