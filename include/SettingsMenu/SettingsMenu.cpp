//
// Created by Usuario on 7/22/2024.
//

#include "SettingsMenu.h"
#include "../Game/Game.h"
#include <SFML/Window/Mouse.hpp>
#include "../config/ResourcesLocation.h"

#include "../Pause/Pause.h"
#include "../utils/Details.h"
class Pause;
SettingsMenu::SettingsMenu() {
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


void SettingsMenu::initializeText(sf::Text &m_titres, const std::string &str, unsigned int size, const sf::Vector2f &position) {
    m_titres.setFont(font);
    m_titres.setString(str);
    m_titres.setCharacterSize(size);
    m_titres.setFillColor(sf::Color::White);
    m_titres.setPosition(position);
}

void SettingsMenu::update(Game &j) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(j.getWindow());
    Details::updateTextColor(resolutionTexts,j);
    for (sf::Text &resolutionText : resolutionTexts) {
        if (resolutionText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        } else {
            resolutionText.setFillColor(sf::Color::White); // Restaurar el color original
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && resolutionText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && c_cont.getElapsedTime().asMilliseconds() >= 250) {
            j.changeScene(new Pause);
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
