#ifndef LEVELSELECTOR_H
#define LEVELSELECTOR_H


#include "../Scene/Scene.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "../utils/LevelConfig.h"
#include "../config/ResourcesLocation.h"

using namespace std;
using namespace sf;
class LevelSelector : public Scene {
public:
    LevelSelector();
    void update(Game &j) override;
    void draw(RenderWindow &w) override;
    void selectLevel(Game &j,const string &lvl_id);
    void loadLevels();
    LevelConfig getLevelConfig(string id);
private:
    const string LEVEL_NAMES_SRC = LEVEL_IDS_FILE;
    Text m_t1,m_t2;
    vector<LevelConfig> levelsConfig;
    Font m_font;
    string selectedLevelId;
};
#endif 
