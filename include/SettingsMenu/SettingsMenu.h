//
// Created by Usuario on 7/22/2024.
//

#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H
#include <string>
#include <SFML/Graphics/Text.hpp>

#include "../Scene/Scene.h"


class SettingsMenu: public Scene {
public:
    SettingsMenu();
    void draw(RenderWindow &) override;
    void update(Game &j) override;
private:
    sf::Text m_titres;
    sf::Font font;
    std::vector<sf::Text> resolutionTexts;
    std::vector<std::pair<int, int>> resolutions;
    Clock c_cont;
    void initializeResolutions();
    void showResolutionOptions(Game &j);
    void initializeText(sf::Text &text, const std::string &str, unsigned int size, const sf::Vector2f &position);
};



#endif //SETTINGSMENU_H
