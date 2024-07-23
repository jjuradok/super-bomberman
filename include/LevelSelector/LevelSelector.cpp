#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "../config/ResourcesLocation/ResourcesLocation.h"
#include "LevelSelector.h"
#include "../Game/Game.h"
#include "../Match/Match.h"
#include "../Menu/Menu.h"
#include "../utils/Details.h"

using namespace std;
using namespace sf;

LevelSelector::LevelSelector() {
    m_font.loadFromFile(FONT_FILE);
    ifstream file(LEVEL_NAMES_SRC);
    string line;
    while (getline(file, line))
    {
        if (!line.empty())
        {
            vector<string> parts;
            istringstream words(line);
            string word;
            while (getline(words, word, ';'))
            {
                parts.push_back(word);
            }
            if (parts.size() == 2)
            {
                LevelConfig levelConfig;
                levelConfig.id = parts[0];
                levelConfig.name = parts[1];

                levelsConfig.push_back(levelConfig);
            }
        }
        }
        file.close();
    m_t1.setFont(m_font);  m_t1.setString("Select Level"); m_t1.setCharacterSize(100); m_t1.setPosition(180,80);
    m_t2.setFont(m_font);  m_t2.setString("Back"); m_t2.setCharacterSize(80); m_t2.setPosition(1600,900);

    int xPosLeft = 180;
    int yPos = 320;

    for (size_t i = 0; i < levelsConfig.size(); i++) {
        LevelConfig config = levelsConfig[i];
        Text levelText;
        levelText.setFont(m_font);
        levelText.setString(config.name);
        levelText.setCharacterSize(50);
        levelText.setFillColor(Color::White);
        levelText.setPosition(Vector2f(xPosLeft, yPos + i * 70));

        config.levelText = levelText;
        levelsConfig[i] = config;
    }
}

void LevelSelector::update(Game &j) {
    vector<Text> levelTexts;
    for (auto &config : levelsConfig) {
        levelTexts.push_back(config.levelText);
    }
    Details::updateTextColor(levelsConfig, j);
    Details::updateTextColor(m_t2,j);
    if (Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousePos = Mouse::getPosition(j.getWindow());
        if (m_t2.getGlobalBounds().contains(static_cast<float>(Mouse::getPosition(j.getWindow()).x), static_cast<float>(Mouse::getPosition(j.getWindow()).y)) && c_cont.getElapsedTime().asMilliseconds() >= 250) {
            j.changeScene(new Menu);
        }
        for (auto &config : levelsConfig) {
            if (config.levelText.getGlobalBounds().contains(static_cast<float>(Mouse::getPosition(j.getWindow()).x), static_cast<float>(Mouse::getPosition(j.getWindow()).y)) && c_cont.getElapsedTime().asMilliseconds() >= 250) {
                selectLevel(j, config.id);
            }
        }
    }
}

void LevelSelector::draw(RenderWindow &w) {
    w.clear();
    w.draw(m_t1);
    w.draw(m_t2);
    for (auto &config : levelsConfig) {
        w.draw(config.levelText);
    }
}

void LevelSelector::selectLevel(Game &j, const string &lvl_id) {
    j.changeScene(new Match(lvl_id));
}

LevelConfig LevelSelector::getLevelConfig(string id) {
    for (auto &config : levelsConfig) {
        if (config.id == id) {
            return config;
        }
    }
    return LevelConfig();
}

