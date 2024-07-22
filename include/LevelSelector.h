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
    void selectLevel(Game &j,const std::string &lvl_name);
    void loadLevels();
private:
    const std::string LEVEL_NAMES_SRC = "resources/level_names.txt";
    sf::Text m_t1,m_t2;
    std::vector<std::string> levelNames;
    std::vector<sf::Text> levelTexts;
    sf::Font m_font;
    int selectedItemIndex;
    Clock c_cont;
};
#endif //LEVELSELECTOR_H
