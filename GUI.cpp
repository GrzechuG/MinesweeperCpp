//
// Created by samsepiol on 3/9/20.
//

#include "GUI.h"
#include "MinesweeperBoard.h"
#include "GUIField.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <zconf.h>
#include <iostream>

GUI::GUI(MinesweeperBoard mainBoard)
        : mainBoard(mainBoard) {

    preloadIcons();

    bool Mouse_Pressed = false;
    sf::RenderWindow window(sf::VideoMode(750, 750), "Minesweeper by Grzegorz Gajewski",sf::Style::Close);

    std::vector <GUIField> fields;
    int fieldWidth =  window.getSize().x/mainBoard.getSize().at(0);

    for(int y = 0; y<mainBoard.getSize().at(1); y++) {
        for (int x = 0; x < mainBoard.getSize().at(0); x++) {

            GUIField s(fieldWidth, x, y,'#');
            s.Update(mainBoard);

            fields.push_back(s);
        }
    }
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            Mouse_Pressed = true;
            if (event.mouseButton.button == sf::Mouse::Left) {
//
                for (int i = 0; i < fields.size(); i++) {
                    GUIField s = fields.at(i);
                    if (s.isClicked(event.mouseButton.x, event.mouseButton.y)) {
                        if (!mainBoard.isFlagged(s.getBoardPosition().x, s.getBoardPosition().y)) {
                            mainBoard.reveal(s.getBoardPosition().x, s.getBoardPosition().y);
                            for (int j = 0; j < fields.size(); j++){
                                fields.at(j).Update(mainBoard);
                            }
                            // mouseUpdate = false;
                        }
                    }
                }
            }
        }
            if (event.type == sf::Event::MouseButtonReleased) {

                if (event.mouseButton.button == sf::Mouse::Right && Mouse_Pressed) {
                    Mouse_Pressed = false;

                    for (int i = 0; i < fields.size(); i++) {

                        GUIField s = fields.at(i);
                        if (s.isClicked(event.mouseButton.x, event.mouseButton.y)) {
                            mainBoard.setFlag(s.getBoardPosition().x, s.getBoardPosition().y);
                            fields.at(i).Update(mainBoard);

                        }
                    }

                }
            }

        if(event.type == sf::Event::Resized){


        }


        if (!mainBoard.isGameover()) {
            window.clear(sf::Color::Black);
            for (int i = 0; i < fields.size(); i++) {
                GUIField s = fields.at(i);
                sf::Image image;
                image = getImage(s.getState());

                sf::Sprite sprite;
                sf::Texture texture;
                texture.loadFromImage(image);  //Load Texture from image
                sprite.setTexture(texture);

                // sprite.setTextureRect(sf::IntRect(s.getPosition().x*s.getWidth(), s.getPosition().y*s.getWidth(), s.getWidth(), s.getWidth()));
                sprite.setPosition(s.getPosition().x, s.getPosition().y);
                sprite.setScale(float(s.getWidth()) / texture.getSize().x, float(s.getWidth()) / texture.getSize().y);


                window.draw(sprite);
            }
            window.display();
            mainBoard.hasWon();
            usleep(10000);
        }else{


            sf::Font font;
            font.loadFromFile("/home/samsepiol/CLionProjects/Minesweeper_Project/arial.ttf");

            sf::Color textColor;
            std::string str;
            if(mainBoard.hasWon()){

                textColor = sf::Color::Green;
                str = "Victory!";
            }else {
                textColor = sf::Color::Red;
                str = "Game Over!";
            }
            sf::Text text(str, font);
            text.setFillColor(textColor);
            text.setCharacterSize(30);
            text.setPosition(window.getSize().x/2, window.getSize().y/2);

// Draw it
            window.draw(text);
            window.display();
            usleep(10000);
        }
    }


}


sf::Image GUI::loadTexture(char state) {

    sf::Image icon;
    switch (state) {
        case ' ':
            icon.loadFromFile("./icons/0.png");
            break;
        case 'x':
            icon.loadFromFile("./icons/bomb.png");
            break;
        case '#':
            icon.loadFromFile("./icons/undiscovered.png");
            break;
        case 'F':
            icon.loadFromFile("./icons/flag.png");
            break;

        default:
            icon.loadFromFile(std::string("./icons/")+state+std::string(".png"));//Todelete
    }
    return icon;

}

void GUI::preloadIcons() {

    std::vector <char> types = {' ', 'x', '#', 'F'};
    for(char c:types){

        textures.push_back((Icon){c,loadTexture(c)});
    }

    for(int i = 1; i<8; i++){
        textures.push_back((Icon){(char)('0'+i),loadTexture('0'+i)});
    }


}

sf::Image GUI::getImage(char state) {
    for(Icon ico:textures){
            if(ico.type == state){
                return ico.image;

            }
    }
    return loadTexture('?');

}
