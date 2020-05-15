// Created by tijsv on 24/02/2020.
//

#include <cmath>
#include <cstring>
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
        auto* pla = new Player(lround(SCREEN_WIDTH/2), lround(SCREEN_HEIGHT-20*SCALE_Y-SCALE_Y*773/8), lround(SCALE_X*1267/8), lround(SCALE_Y*773/8));
        auto* buCo = new BulletController(pla);
        auto* enCo = new EnemyController(ROWS,COLUMNS,buCo);
        auto* miscCo = new MiscController(win);

        auto* scoreText = AF->makeText(std::string("Score"), lround(SCREEN_WIDTH/2), lround(10*SCALE_Y), lround(15*SCALE_Y), "Assets/PressStart2P.ttf");

        GameController::getInstance().getEventmanager() ->addObserver(pla);
        win->setBackground(GameController::getInstance().getFactory()->makeSprite("Assets/background.png"));
        //win->setIcon(GameController::getInstance().getFactory()->makeSprite("Assets/spaceshipIcon.png"));

        while (!win->pollEvents())
        {
            timePast=win->getTimePast();
            if(pla->isShoot())
                buCo->addBullet(lround(pla->getXpos()+pla->getWidth()/2), pla->getYpos(),-1,false);
            pla->update(timePast);
            scoreText->setText("Score:"+to_string(buCo->getScore()));
            win->enqueueGO(pla);
            win->enqueueText(scoreText);
            enCo->enqueueEnemies(win);
            enCo->moveEnemies(timePast);
            miscCo->bonus(timePast,win);
            buCo->enqueueBullets(win);
            buCo->moveBullets(timePast,enCo->getEnemyVector(),miscCo->getBonusVector());
            miscCo->showHealth(pla->getHealth());

            if(pla->getHealth()<=0)
            {
                gameOver = true;
                break;
            }
            win->draw();
        }

        if(gameOver)
        {
            win->setBackground(GameController::getInstance().getFactory()->makeSprite("Assets/GameOver.png"));
            auto* gameOverText = AF->makeText(std::string("Score"), lround(SCREEN_WIDTH/2), lround(10*SCALE_Y), lround(25*SCALE_Y), "Assets/PressStart2P.ttf");
            pla->setRestart(false); //if space was hit during game, make it undone

            while(!win->pollEvents())
            {
                restart = pla->isRestart();  //set restart tothe restart in player, if player his space restart will be true
                gameOverText->setText("Score:"+to_string(buCo->getScore()));
                win->enqueueText(gameOverText);
                win->draw();
                if(restart) //if space was hit we'll want to restart;
                    break;
            }
        }


        delete pla;
        delete buCo;
        delete enCo;
        delete miscCo;
        delete scoreText;
        win->remove();
    }
}


