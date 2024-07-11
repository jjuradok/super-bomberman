//
// Created by Usuario on 7/8/2024.
//

#include "Menu.h"

#include <iostream>

#include "Game.h"
#include "Match.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>

#include "LevelSelector.h"
using namespace sf;
Menu::Menu() {
    m_font.loadFromFile("assets/fonts/fuentegod.ttf");
    m_t1.setFont(m_font);  m_t1.setString("Bombita"); m_t1.setCharacterSize(150); m_t1.setPosition(180,80);
    m_t2.setFont(m_font);  m_t2.setString("Select level"); m_t2.setCharacterSize(70); m_t2.setPosition(180,350);
    m_t3.setFont(m_font);  m_t3.setString("Salir"); m_t3.setCharacterSize(70); m_t3.setPosition(1200,350);
    m_t4.setFont(m_font);  m_t4.setString("Jurado-Lui. 2024"); m_t4.setCharacterSize(70); m_t4.setPosition(180,900);
}

void Menu::draw(RenderWindow &w) {
    w.clear({2,4,74});
    w.draw(m_t1);
    w.draw(m_t2);
    w.draw(m_t3);
    w.draw(m_t4);
}

void Menu::update(Game &j) {

    updateTextColor(m_t2, j);
    updateTextColor(m_t3, j);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if (m_t2.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(j.getWindow()).x), static_cast<float>(sf::Mouse::getPosition(j.getWindow()).y))) {
            j.changeScene(new LevelSelector);
        }

        if (m_t3.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(j.getWindow()).x), static_cast<float>(sf::Mouse::getPosition(j.getWindow()).y))) {
            j.getWindow().close();
        }
    }Menu.h
}

void Menu::updateTextColor(sf::Text& text, Game& j) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(j.getWindow());
    if (text.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        text.setFillColor(sf::Color(75,75,75)); // Cambiar el color al pasar el mouse
    } else {
        text.setFillColor(sf::Color::White); // Restaurar el color original
    }
}

