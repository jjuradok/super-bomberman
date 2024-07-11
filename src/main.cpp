#include "../include/Game.h"
#include "../include/Match.h"
#include <iostream>
#include "../include/Menu.h"

int main(int argc, char *argv[])
{
    Game j(new Menu);
    j.start();
    return 0;
}
