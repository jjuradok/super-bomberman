#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
using namespace sf;

class Game;

class Scene {
protected:
	Clock counter; // las clases que hereden de scene, tienen un reloj para evitar clicks seguidos
public:
	virtual void update(Game &j) = 0;
	virtual void draw(RenderWindow &) = 0;
	virtual ~Scene()=default; //destructor virtual por default
};

#endif
