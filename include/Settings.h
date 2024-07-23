#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

using namespace std;

class Settings
{
  string filename;
  unsigned int screen_width;
  unsigned int screen_height;
public:
  Settings(string &filename);
  Settings();
  unsigned int getScreenWidth() ;
  unsigned int getScreenHeight() ;
  void setScreenWidth(unsigned int width);
  void setScreenHeight(unsigned int height);
  void save();
};

#endif