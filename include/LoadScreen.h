//
// Created by Usuario on 7/22/2024.
//

#ifndef LOADSCREEN_H
#define LOADSCREEN_H
#include "Scene.h"


class LoadScreen :public Scene{
public:
    LoadScreen(const std::string &levelName);
    void draw(RenderWindow &) override;
    void update(Game &j) override;

private:
    sf::Font font;
    sf::Text text;
    sf::Clock clock;
    int countdown;
    std::string m_levelName;

};



#endif //LOADSCREEN_H
