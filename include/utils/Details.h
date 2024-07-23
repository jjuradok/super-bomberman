//
// Created by Usuario on 7/16/2024.
//

#ifndef DETAILS_H
#define DETAILS_H
#include <vector>
#include <SFML/Graphics/Text.hpp>

#include "LevelConfig.h"
class Game;
using namespace std;
class Details {
public:
    Details(Game &j);
    static void updateTextColor(vector<LevelConfig> &levelsConfig, Game &j);
    static void updateTextColor(vector<Text> &v_text, Game &j);
    static void updateTextColor(Text &text, Game &j);
private:

};
#endif //DETAILS_H
