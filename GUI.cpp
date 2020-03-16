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
        : mainBoard(mainBoard){

    preloadIcons();

    bool Mouse_Pressed = false;
    //750 - 20
    //750/20 = 37
    sf::RenderWindow window(
            sf::VideoMode(mainBoard.getSize().at(0)*37, mainBoard.getSize().at(1)*37),
            "Minesweeper by Grzegorz Gajewski",
            sf::Style::Close);

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
                if(!mainBoard.isGameover())
                for (int i = 0; i < fields.size(); i++) {
                    GUIField s = fields.at(i);
                    if (s.isClicked(event.mouseButton.x, event.mouseButton.y)) {
                        if (!mainBoard.isFlagged(s.getBoardPosition().x, s.getBoardPosition().y)) {
                            mainBoard.reveal(s.getBoardPosition().x, s.getBoardPosition().y);
                            for (int j = 0; j < fields.size(); j++){
                                fields.at(j).Update(mainBoard);
                            }

                        }
                    }
                }
            }
        }
            if (event.type == sf::Event::MouseButtonReleased) {

                if (event.mouseButton.button == sf::Mouse::Right && Mouse_Pressed) {

                    Mouse_Pressed = false;
                    if(!mainBoard.isGameover())
                    for (int i = 0; i < fields.size(); i++) {

                        GUIField s = fields.at(i);
                        if (s.isClicked(event.mouseButton.x, event.mouseButton.y)) {
                            mainBoard.setFlag(s.getBoardPosition().x, s.getBoardPosition().y);
                            fields.at(i).Update(mainBoard);

                        }
                    }

                }
            }

            window.clear(sf::Color::Black);
            sf::Sprite s;
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
            window.draw(s);

            mainBoard.hasWon();



        if (mainBoard.isGameover()) {


            sf::Font font;
            font.loadFromFile("./data/arial.ttf");

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
            sf::RectangleShape rect1(sf::Vector2f(10,10));
            rect1.setFillColor(sf::Color::Black);
            text.setCharacterSize(80);
            float textX = window.getSize().x/2-str.size()*20;
            float textY = window.getSize().y/2;
            rect1.setPosition(0, textY);
            rect1.setSize(sf::Vector2f(window.getSize().x,80*1.5));
            text.setFillColor(textColor);

            text.setPosition(textX,textY);
            window.draw(rect1);
            window.draw(text);
        }

        window.display();
        usleep(10000);
    }


}


sf::Image GUI::loadTexture(char state) const{

    sf::Image icon;
    switch (state) {
        case ' ':
            icon.loadFromFile("./data/0.png");
            break;
        case 'x':
            icon.loadFromFile("./data/bomb.png");
            break;
        case '#':
            icon.loadFromFile("./data/undiscovered.png");
            break;
        case 'F':
            icon.loadFromFile("./data/flag.png");
            break;

        default:
            icon.loadFromFile(std::string("./data/")+state+std::string(".png"));//Todelete
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

sf::Image GUI::getImage(char state) const{
    for(Icon ico:textures){
            if(ico.type == state){
                return ico.image;

            }
    }
    return loadTexture('?');

}


