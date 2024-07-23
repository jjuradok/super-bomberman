//
// Created by Usuario on 7/8/2024.
//

#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include "../Scene/Scene.h"
using namespace sf;

class Game;

class Menu : public Scene{
    public:
        Menu();
        void update(Game &j) override;
        void draw(RenderWindow &w) override;
    private:
        Font m_font;
        Text m_t1,m_t2,m_t3, m_t4;
        std::vector<Text> m_options;
};



#endif //MENU_H
