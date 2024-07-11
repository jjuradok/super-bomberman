//
// Created by Usuario on 7/10/2024.
//

#ifndef LEVELSELECTOR_H
#define LEVELSELECTOR_H


#include "Scene.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
class Game;
class LevelSelector : public Scene {
public:
    LevelSelector();
    void update(Game &j) override;
    void draw(sf::RenderWindow &w) override;
    void selectLevel(Game &j);

private:
    sf::Text m_t1;
    std::vector<std::string> levelNames= {"test.txt"};
    std::vector<sf::Text> levelTexts;
    sf::Font m_font;
    int selectedItemIndex;
};
#endif //LEVELSELECTOR_H
