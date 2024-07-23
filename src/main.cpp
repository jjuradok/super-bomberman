#include "../include/Game/Game.h"
#include "../include/Match/Match.h"
#include <iostream>
#include "../include/Menu/Menu.h"

int main(int argc, char *argv[])
{
    Game j(new Menu);
    j.start();
    return 0;
}
