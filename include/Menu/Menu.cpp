#include "Menu.h"
#include <iostream>
#include "../Game/Game.h"
#include "../Match/Match.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include "../config/ResourcesLocation/ResourcesLocation.h"
#include "../LevelSelector/LevelSelector.h"
#include "../utils/Details.h"

using namespace sf;


Menu::Menu() {
    handleStartMusic();
    menuFont.loadFromFile(FONT_FILE);
    text1.setFont(menuFont);  text1.setString("Bombita"); text1.setCharacterSize(150); text1.setPosition(180,80);
    text2.setFont(menuFont);  text2.setString("Select level"); text2.setCharacterSize(70); text2.setPosition(180,350);
    text3.setFont(menuFont);  text3.setString("Exit"); text3.setCharacterSize(70); text3.setPosition(1200,350);
    text4.setFont(menuFont);  text4.setString("Jurado-Lui. 2024"); text4.setCharacterSize(70); text4.setPosition(180,900);
    m_options.push_back(text2); m_options.push_back(text3);
}

void Menu::handleStartMusic() {
    backgroundMusic.openFromFile(MENU_BACKGROUND_MUSIC_SRC);
    backgroundMusic.setLoop(true);
    backgroundMusic.play();
}

void Menu::draw(RenderWindow &w) {
    w.clear({2,4,74});
    w.draw(text1);
    for (auto &text:m_options) {
        w.draw(text);
    }
    w.draw(text4);
}

void Menu::update(Game &j) {
    Details::updateTextColor(m_options,j);
    if (Mouse::isButtonPressed(Mouse::Left)){
        if (text2.getGlobalBounds().contains(static_cast<float>(Mouse::getPosition(j.getWindow()).x), static_cast<float>(Mouse::getPosition(j.getWindow()).y))) {
            backgroundMusic.stop();
            j.changeScene(new LevelSelector);
        }

        if (text3.getGlobalBounds().contains(static_cast<float>(Mouse::getPosition(j.getWindow()).x), static_cast<float>(Mouse::getPosition(j.getWindow()).y))) {
            j.getWindow().close();
        }
    }
}