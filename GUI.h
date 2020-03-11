//
// Created by samsepiol on 3/9/20.
//

#ifndef SAPER_GUI_H
#define SAPER_GUI_H


#include <SFML/Graphics/Texture.hpp>
#include "MinesweeperBoard.h"

struct Icon{
    char type;
    sf::Image image;
};
class GUI {

    MinesweeperBoard mainBoard;
    sf::Image loadTexture(char state);
    std::vector <Icon> textures;
    void preloadIcons();
    sf::Image getImage(char state);



public:
    GUI(MinesweeperBoard mainBoard);

};


#endif //SAPER_GUI_H
