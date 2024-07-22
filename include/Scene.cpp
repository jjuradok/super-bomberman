//
// Created by Usuario on 7/22/2024.
//
#include "Scene.h"
#include "Game.h"
#include <SFML/Window/Mouse.hpp>
#
class Game;
void Scene::updateTextColor(std::vector<sf::Text> &v_text, Game &j) {
    for(auto &text:v_text) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(j.getWindow());
        if (text.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            text.setFillColor(sf::Color(75,75,75)); // Cambiar el color al pasar el mouse
        } else {
            text.setFillColor(sf::Color::White); // Restaurar el color original
        }
    }
}
void Scene::updateTextColor(Text &text, Game &j) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(j.getWindow());
    if (text.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        text.setFillColor(sf::Color(75,75,75)); // Cambiar el color al pasar el mouse
    } else {
        text.setFillColor(sf::Color::White); // Restaurar el color original
    }
}
