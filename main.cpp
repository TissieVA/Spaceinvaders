#include <iostream>
#include "Factories/AFactory.h"

#include "Game.h"
#include "SDL/Factories/SDLFactory.h"

using namespace SpaceInvaders::Factories;

int main (int argc, char *argv[]) {
    AFactory* AF = new SDLFactory();
    Game* G = new Game(AF);
    G->run();
    return 0;
}
