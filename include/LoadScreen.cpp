//
// Created by Usuario on 7/22/2024.
//

#include "LoadScreen.h"

#include "LoadScreen.h"
#include "Game.h"
#include "Match.h"
#include "config/ResourcesLocation.h"

LoadScreen::LoadScreen(const std::string &levelName) : countdown(3), m_levelName(levelName) {
    font.loadFromFile(FONT_FILE);
    text.setFont(font);
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::White);
    text.setString(std::to_string(countdown));
    text.setPosition(900, 375);  // Adjust the position as needed
}

void LoadScreen::update(Game& game) {
    if (clock.getElapsedTime().asSeconds() >= 0.7) {
        countdown--;
        if (countdown > 0) {
            text.setString(std::to_string(countdown));
            clock.restart();
        } else {
            game.changeScene(new Match(m_levelName));
        }
    }
}

void LoadScreen::draw(sf::RenderWindow& window) {
    window.clear();
    window.draw(text);
}
