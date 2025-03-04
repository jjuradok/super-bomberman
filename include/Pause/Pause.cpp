#include <iostream>

#include "Pause.h"
#include "../LevelSelector/LevelSelector.h"
#include "Pause.h"
#include "../SettingsMenu/SettingsMenu.h"
#include "../config/ResourcesLocation/ResourcesLocation.h"
#include "../utils/Details.h"

Pause::Pause()
{
    font.loadFromFile(FONT_FILE);
    resumeText.setFont(font);
    resumeText.setString("Resume");
    resumeText.setCharacterSize(30);
    resumeText.setFillColor(Color::White);
    resumeText.setPosition(100, 100);

    levelSelectText.setFont(font);
    levelSelectText.setString("Select level");
    levelSelectText.setCharacterSize(30);
    levelSelectText.setFillColor(Color::White);
    levelSelectText.setPosition(100, 150);

    exitText.setFont(font);
    exitText.setString("Exit");
    exitText.setCharacterSize(30);
    exitText.setFillColor(Color::White);
    exitText.setPosition(100, 200);

    options.push_back(resumeText);
    options.push_back(levelSelectText);
    options.push_back(exitText);
    options.push_back(settingsText);
}

void Pause::update(Game &j)
{
    for (auto &text : options)
    {
        Details::updateTextColor(text, j);
    }
    if (Mouse::isButtonPressed(Mouse::Left))
    {
        Vector2i mousePos = Mouse::getPosition(j.getWindow());

        if (resumeText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && counter.getElapsedTime().asMilliseconds() >= 250)
        {
            j.changeScene(j.getPreviousScene());
        }
        else if (levelSelectText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && counter.getElapsedTime().asMilliseconds() >= 250)
        {
            j.changeScene(new LevelSelector());
        }
        else if (exitText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && counter.getElapsedTime().asMilliseconds() >= 250)
        {
            j.getWindow().close();
        }
        else if (settingsText.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && counter.getElapsedTime().asMilliseconds() >= 250)
        {
            j.changeScene(new SettingsMenu);
        }
    }
}

void Pause::draw(RenderWindow &w)
{
    w.clear();
    for (auto &text : options)
    {
        w.draw(text);
    }
}
