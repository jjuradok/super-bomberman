#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio.hpp>

#include "Scene.h"
using namespace std;
using namespace sf;

class Menu : public Scene
{
public:
    Menu();
    void update(Game &j) override;
    void draw(RenderWindow &w) override;
    void handleStartMusic();
private:
    Music backgroundMusic;
    Font menuFont;
    Text text1, text2, text3, text4;
    vector<Text> m_options;
};

#endif
