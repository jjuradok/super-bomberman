#include "../include/Game.h"
#include "../include/Partida.h"
#include <iostream>

int main(int argc, char *argv[])
{
    Game j(new Partida);
    j.start();
    return 0;
}
