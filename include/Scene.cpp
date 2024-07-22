#include "Scene.h"
#include "Game.h"
#include <SFML/Window/Mouse.hpp>
#include "utils/LevelConfig.h"

using namespace sf;
using namespace std;

class Game;
void Scene::updateTextColor(vector<LevelConfig> &levelsConfig, Game &j)
{
    for (auto &config : levelsConfig)
    {
        Vector2i mousePos = Mouse::getPosition(j.getWindow());
        if (config.levelText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
        {
            config.levelText.setFillColor(Color(75, 75, 75));
        }
        else
        {
            config.levelText.setFillColor(Color::White);
        }
    }
}
void Scene::updateTextColor(vector<Text> &v_text, Game &j) {
    for(auto &text:v_text) {
        Vector2i mousePos = Mouse::getPosition(j.getWindow());
        if (text.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            text.setFillColor(Color(75,75,75)); 
        } else {
            text.setFillColor(Color::White); 
        }
    }
}
void Scene::updateTextColor(Text &text, Game &j) {
    Vector2i mousePos = Mouse::getPosition(j.getWindow());
    if (text.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        text.setFillColor(Color(75,75,75)); 
    } else {
        text.setFillColor(Color::White); 
    }
}
