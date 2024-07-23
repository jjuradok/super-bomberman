//
// Created by Usuario on 7/22/2024.
//

#include "SettingsMenu.h"
#include "Game.h"
#include <SFML/Window/Mouse.hpp>

#include "Menu.h"
#include "Pause.h"
#include "config/ResourcesLocation.h"
class Pause;
SettingsMenu::SettingsMenu(){
    font.loadFromFile(FONT_FILE);
    resolutions = {
        {1920, 1080},
        {1600, 900},
        {1366, 768},
        {1280, 720}
    };

    for (size_t i = 0; i < resolutions.size(); ++i) {
        sf::Text resolutionText;
        std::string resolutionStr = std::to_string(resolutions[i].first) + "x" + std::to_string(resolutions[i].second);
        resolutionText.setString(resolutionStr); resolutionText.setFont(font); resolutionText.setFillColor(sf::Color::White); resolutionText.setPosition(100, 150 + i * 50);
        resolutionTexts.push_back(resolutionText);
    }

    m_titres.setFont(font);
    m_titres.setString("Resolution");
    m_titres.setCharacterSize(75);
    m_titres.setFillColor(sf::Color::White);
    m_titres.setPosition(100,50);
}




void SettingsMenu::update(Game &game) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(game.getWindow());

    for (size_t i = 0; i < resolutionTexts.size(); ++i) {
        if (resolutionTexts[i].getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            resolutionTexts[i].setFillColor(sf::Color(75, 75, 75));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                selectedOption = i;
                m_settings.setScreenWidth(resolutions[i].first);
                m_settings.setScreenHeight(resolutions[i].second);
                game.getWindow().setSize(sf::Vector2u(resolutions[i].first, resolutions[i].second));
                game.getWindow().setView(sf::View(sf::FloatRect(0, 0, resolutions[i].first, resolutions[i].second)));
                m_settings.save(); // Guardar configuración
            }
        } else {
            resolutionTexts[i].setFillColor(sf::Color::White);
        }
    }
}


void SettingsMenu::draw(sf::RenderWindow &w) {
    w.clear();
    w.draw(m_titres);
    for (const sf::Text &resolutionText : resolutionTexts) {
        w.draw(resolutionText);
    }
}
