//
// Created by Usuario on 7/8/2024.
//

#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Scene.h"LevelSelector.cpp
using namespace sf;

class Game;

class Menu : public Scene{
    public:
        Menu();
        void update(Game &j) override;
        void draw(RenderWindow &w) override;
        void handleEvent(sf::Event &event, Game &j);
        void updateTextColor(sf::Text& text, Game& j);
    private:
        Font m_font;
        Text m_t1, m_t2, m_t3, m_t4;

};



#endif //MENU_H
