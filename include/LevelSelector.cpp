//
// Created by Usuario on 7/10/2024.
//

#include "LevelSelector.h"

#include "Game.h"
#include "Match.h"

LevelSelector::LevelSelector() {
    m_font.loadFromFile("assets/fonts/fuentegod.ttf");
    m_t1.setFont(m_font);  m_t1.setString("Select Level"); m_t1.setCharacterSize(100); m_t1.setPosition(180,80);

    float xPosLeft = 180;
    float xPosRight = 1000;
    float yPos = 320;

    for (size_t i = 0; i < levelNames.size(); ++i) {
        sf::Text levelText;
        levelText.setFont(m_font);
        levelText.setString(levelNames[i]);
        levelText.setCharacterSize(30);
        levelText.setFillColor(sf::Color::White);

        if (i % 2 == 0) {
            levelText.setPosition(sf::Vector2f(xPosLeft, yPos));
        } else {
            levelText.setPosition(sf::Vector2f(xPosRight, yPos));
            yPos += 40; // Incrementar Y sólo después de colocar en la columna derecha
        }

        levelTexts.push_back(levelText);
    }
}

void LevelSelector::update(Game &j) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(j.getWindow());

        for (auto &text : levelTexts) {
            if (text.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(j.getWindow()).x), static_cast<float>(sf::Mouse::getPosition(j.getWindow()).y))) {
                selectLevel(j);
            }
        }
    }
}

void LevelSelector::draw(sf::RenderWindow &w) {
    w.clear();
    w.draw(m_t1);
    for (auto& text : levelTexts) {
        w.draw(text);
    }
}

void LevelSelector::selectLevel(Game &j) {
    j.changeScene(new Match);
}