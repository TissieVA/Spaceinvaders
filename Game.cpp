// Created by tijsv on 24/02/2020.
//

#include <cmath>
#include "Game.h"
#include "Factories/AFactory.h"
#include "Controllers/GameController.h"
#include "GameObject/Player.h"
#include "GameObject/Enemy.h"
#include "Controllers/EnemyController.h"
#include "Controllers/BulletController.h"
#include "Controllers/MiscController.h"
#include "Text/Text.h"

using namespace SpaceInvaders::Factories;
using namespace SpaceInvaders::Controllers;
using namespace SpaceInvaders::Text;

Game::Game(AFactory *afac) {
    AF = afac;
}

void Game::run() {

    Window* win = AF->makeWindow();
    GameController::getInstance().setWindow(win);
    GameController::getInstance().setFactory(AF);

    if (win->create()) {
        auto* pla = new Player(600, 700, lround(SCALE_X*1267/8), lround(SCALE_Y*773/8));
        auto* buCo = new BulletController(pla);
        auto* enCo = new EnemyController(ROWS,COLUMNS,buCo);
        auto* miscCo = new MiscController(win);

        GameController::getInstance().getEventmanager() ->addObserver(pla);
        win->setBackground(GameController::getInstance().getFactory()->makeSprite("Assets/background.png"));
        //win->setIcon(GameController::getInstance().getFactory()->makeSprite("Assets/spaceshipIcon.png"));
        //auto* points = new Text("TEST",100,100,100,100,lazy.ttf);
        while (!win->pollEvents())
        {
            timePast=win->getTimePast();
            if(pla->isShoot())
                buCo->addBullet(lround(pla->getXpos()+pla->getWidth()/2), pla->getYpos(),-1,false);
            pla->update(timePast);
            win->enqueueGO(pla);
            enCo->enqueueEnemies(win);
            enCo->moveEnemies(timePast);
            miscCo->bonus(timePast,win);
            buCo->enqueueBullets(win);
            buCo->moveBullets(timePast,enCo->getEnemyVector(),miscCo->getBonusVector());
            miscCo->showHealth(pla->getHealth());
            if(pla->getHealth()<=0)
                break;
            win->draw();
        }
        win->remove();
    }
}
