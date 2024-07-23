#ifndef PAUSE_H
#define PAUSE_H



#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Game.h"

using namespace sf;
using namespace std;
class Pause : public Scene {
public:
    Pause();
    void update(Game& j) override;
    void draw(RenderWindow& w) override;
    void updateTextColor(Text& text, Game& j);
private:
    Font font;
    Text resumeText;
    Text levelSelectText;
    Text settingsText;
    Text exitText;
    vector<Text> options;
    Clock counter;
};



#endif //PAUSE_H
