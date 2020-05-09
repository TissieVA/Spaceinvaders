//
// Created by Tijs Van Alphen on 23/03/2020.
//

#include <cmath>
#include "GameController.h"

using namespace SpaceInvaders::Controllers;

GameController::GameController() {
    eventManager = new Events::EventManager();
}

GameController::~GameController() {

}

SpaceInvaders::Factories::AFactory *GameController::getFactory() const {
    return factory;
}

void GameController::setFactory(Factories::AFactory *factory) {
    GameController::factory = factory;
}

SpaceInvaders::Events::EventManager *GameController::getEventmanager() {
    return eventManager;
}



