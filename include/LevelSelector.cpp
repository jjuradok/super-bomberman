//
// Created by Usuario on 7/10/2024.
//

#include "LevelSelector.h"

#include "Game.h"
#include "Match.h"
#include<fstream>

#include "LoadScreen.h"
#include "Menu.h"
#include "config/ResourcesLocation.h"

LevelSelector::LevelSelector() {
    m_font.loadFromFile(FONT_FILE);
        std::ifstream file(LEVEL_NAMES_SRC);
        std::string line;
        while (std::getline(file, line)) {
            if (!line.empty()) {
                levelNames.push_back(line);
            }
        }
        file.close();
    m_t1.setFont(m_font);  m_t1.setString("Select Level"); m_t1.setCharacterSize(100); m_t1.setPosition(180,80);
    m_t2.setFont(m_font);  m_t2.setString("Volver"); m_t2.setCharacterSize(80); m_t2.setPosition(1600,900);

    float xPosLeft = 180;
    float xPosRight = 600;
    float yPos = 320;

    for (size_t i = 0; i < levelNames.size(); i++) {
        sf::Text levelText;
        levelText.setFont(m_font);
        levelText.setString(levelNames[i]);
        levelText.setCharacterSize(50);
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
    updateTextColor(levelTexts,j);
    updateTextColor(m_t2,j);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(j.getWindow());
        if (m_t2.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(j.getWindow()).x), static_cast<float>(sf::Mouse::getPosition(j.getWindow()).y)) && c_cont.getElapsedTime().asMilliseconds() >= 250) {
            j.changeScene(new Menu);
        }
        for (auto &text : levelTexts) {
            if (text.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(j.getWindow()).x), static_cast<float>(sf::Mouse::getPosition(j.getWindow()).y)) && c_cont.getElapsedTime().asMilliseconds() >= 250) {
                j.changeScene(new LoadScreen(text.getString()));
            }
        }
    }
}

void LevelSelector::draw(sf::RenderWindow &w) {
    w.clear();
    w.draw(m_t1);
    w.draw(m_t2);
    for (auto& text : levelTexts) {
        w.draw(text);
    }
}

void LevelSelector::selectLevel(Game &j, const std::string &lvl_name) {
    j.changeScene(new Match(lvl_name));
}

