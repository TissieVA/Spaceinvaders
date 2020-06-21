//
// Created by Tijs Van Alphen on 24/02/2020.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H
#include "Factories/AFactory.h"
#include "GameObject/Enemy.h"

using namespace SpaceInvaders::Factories;

class Game {
public:
    Game(AFactory* afac );
    void run();


private:
    AFactory* AF;
    double timePast;
    bool gameOver = false;
    bool restart = true;
    double stopwatch;
    double startTime;
};


#endif //GAME_GAME_H
