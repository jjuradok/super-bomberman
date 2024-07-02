#include "../include/Game.h"
#include "../include/Match.h"
#include <iostream>

int main(int argc, char *argv[])
{
    Game j(new Match);
    j.start();
    return 0;
}
