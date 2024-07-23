//
// Created by Usuario on 7/20/2024.
//

#ifndef PAUSE_H
#define PAUSE_H



#include <SFML/Graphics.hpp>
#include "../Scene/Scene.h"
#include "../Game/Game.h"

class Pause : public Scene {
public:
    Pause();
    void update(Game& j) override;
    void draw(sf::RenderWindow& w) override;
private:
    sf::Font m_font;
    sf::Text m_resume;
    sf::Text m_levelSelect;
    sf::Text m_settings;
    sf::Text m_exit;
    std::vector<sf::Text> m_options;
};



#endif //PAUSE_H
