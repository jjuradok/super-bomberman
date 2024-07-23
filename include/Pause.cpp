#include "Pause.h"

#include "LevelSelector.h"

#include "Pause.h"
#include <iostream>

#include "SettingsMenu.h"
#include "config/ResourcesLocation.h"


Pause::Pause() {
    if (!m_font.loadFromFile(FONT_FILE)) {
        std::cerr << "Error loading font\n";
        // Manejar error si es necesario
    }

    m_resume.setFont(m_font);
    m_resume.setString("Resume");
    m_resume.setCharacterSize(30);
    m_resume.setFillColor(sf::Color::White);
    m_resume.setPosition(100, 100);

    m_levelSelect.setFont(m_font);
    m_levelSelect.setString("Select level");
    m_levelSelect.setCharacterSize(30);
    m_levelSelect.setFillColor(sf::Color::White);
    m_levelSelect.setPosition(100, 150);

    m_exit.setFont(m_font);
    m_exit.setString("Exit");
    m_exit.setCharacterSize(30);
    m_exit.setFillColor(sf::Color::White);
    m_exit.setPosition(100, 200);

    m_settings.setFont(m_font);
    m_settings.setString("Settings");
    m_settings.setCharacterSize(30);
    m_settings.setFillColor(sf::Color::White);
    m_settings.setPosition(100, 250);


    m_options.push_back(m_resume);
    m_options.push_back(m_levelSelect);
    m_options.push_back(m_exit);
    m_options.push_back(m_settings);
}
void Pause::updateTextColor(sf::Text& text, Game& j) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(j.getWindow());
    if (text.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        text.setFillColor(sf::Color(75,75,75)); // Cambiar el color al pasar el mouse
    } else {
        text.setFillColor(sf::Color::White); // Restaurar el color original
    }
}
void Pause::update(Game& j) {

    for(auto & text: m_options) {
        updateTextColor(text,j);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(j.getWindow());

        if (m_resume.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && c_cont.getElapsedTime().asMilliseconds() >= 250) {
            std::cout << "Resuming game" << std::endl;
            // Reanudar el juego
            j.changeScene(j.getPreviousScene());
        } else if (m_levelSelect.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && c_cont.getElapsedTime().asMilliseconds() >= 250) {
            std::cout << "Selecting level" << std::endl;
            j.changeScene(new LevelSelector());
        } else if (m_exit.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && c_cont.getElapsedTime().asMilliseconds() >= 250) {
            std::cout << "Exiting game" << std::endl;
            // Salir del juego
            j.getWindow().close();
        } else if (m_settings.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && c_cont.getElapsedTime().asMilliseconds() >= 250) {
            std::cout << "Exiting game" << std::endl;
        // Salir del juego
            j.changeScene(new SettingsMenu);
    }
    }
}

void Pause::draw(sf::RenderWindow& w) {
    w.clear();
    for (auto& text : m_options) {
        w.draw(text);
    }
}


