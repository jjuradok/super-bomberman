#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>
#include "../Game.h"
#include "Details.h"
class Game;

Details::Details(Game &j) {

}

void Details::updateTextColor(sf::Text& text, Game& j) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(j.getWindow());
    if (text.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        text.setFillColor(sf::Color(75,75,75)); // Cambiar el color al pasar el mouse
    } else {
        text.setFillColor(sf::Color::White); // Restaurar el color original
    }
}