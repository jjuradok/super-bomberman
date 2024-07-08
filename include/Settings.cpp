#include "Settings.h"
#include "config/ResourcesLocation.h"
#include <fstream>
#include <iostream>

Settings::Settings(std::string &filename) : filename(filename), screen_width(800), screen_height(600)
{
  std::ifstream file(filename);
  if (!file.is_open())
  {
    std::cerr << "Failed to open configuration file: " << filename << std::endl;
    return;
  }
  file >> screen_width >> screen_height;
  file.close();

  if (screen_width == 0 || screen_height == 0)
  {
    std::cerr << "Invalid width or height values in configuration file." << std::endl;
    screen_width = 800; 
    screen_height = 600;
  }
}

Settings::Settings() : filename(SETTINGS_FILE), screen_width(800), screen_height(600)
{
  std::ifstream file(filename);
  if (!file.is_open())
  {
    std::cerr << "Failed to open configuration file: " << filename << std::endl;
    return;
  }
  file >> screen_width >> screen_height;
  file.close();

  if (screen_width == 0 || screen_height == 0)
  {
    std::cerr << "Invalid width or height values in configuration file." << std::endl;
    screen_width = 800;
    screen_height = 600;
  }
}

unsigned int Settings::getScreenWidth() 
{
  return screen_width;
}

unsigned int Settings::getScreenHeight() 
{
  return screen_height;
}

void Settings::setScreenWidth(unsigned int width)
{
  screen_width = width;
}

void Settings::setScreenHeight(unsigned int height)
{
  screen_height = height;
}