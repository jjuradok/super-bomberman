#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

class Settings
{
  std::string filename;
  unsigned int screen_width;
  unsigned int screen_height;
public:
  Settings(std::string &filename);
  unsigned int getScreenWidth() ;
  unsigned int getScreenHeight() ;
  void setScreenWidth(unsigned int width);
  void setScreenHeight(unsigned int height);
};

#endif