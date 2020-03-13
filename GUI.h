//
// Created by samsepiol on 3/9/20.
//

#ifndef SAPER_GUI_H
#define SAPER_GUI_H


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "MinesweeperBoard.h"
#include "GUIField.h"

struct Icon{
    char type;
    sf::Image image;
};
class GUI {

    MinesweeperBoard mainBoard;
    sf::RenderWindow window;
    sf::Image loadTexture(char state) const;
    std::vector <Icon> textures;
    void preloadIcons();
    sf::Image getImage(char state) const;




public:
    GUI(MinesweeperBoard mainBoard);

};


#endif //SAPER_GUI_H
