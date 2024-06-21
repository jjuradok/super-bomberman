#ifndef TANQUE_H
#define TANQUE_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Disparo.h"
using namespace sf;

class Tanque
{
	Texture m_tex;
	Sprite m_spr;
	Clock m_clock;
	Keyboard::Key m_acel, m_fren, m_izq, m_der, m_disp;

public:
	Tanque(bool player_one);
	void update();
	void draw(RenderWindow &w);
	bool debeDisparar();
	Disparo generarDisparo();
	Vector2f verPosicion();
};

#endif
