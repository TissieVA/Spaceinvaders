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

    Window* win = AF->makeWindow(); //create a window
    GameController::getInstance().setWindow(win);
    GameController::getInstance().setFactory(AF);
    restart = false;

    if (win->create()) {
        auto* pla = new Player(lround((SCREEN_WIDTH/2)-((PLAYER_WIDTH*SCALE_X)/2)), lround(SCREEN_HEIGHT-20*SCALE_Y-SCALE_Y*PLAYER_HEIGHT), lround(SCALE_X*PLAYER_WIDTH), lround(SCALE_Y*PLAYER_HEIGHT)); //create player
        auto* buCo = new BulletController(pla); //create bullet controller
        auto* enCo = new EnemyController(ROWS,COLUMNS,buCo); //create enemycontroller + enemies are created here
        auto* miscCo = new MiscController(win); //create miscellaneous controller (health, bonusship)

        auto* scoreText = AF->makeText("SCORE:", lround(SCREEN_WIDTH/2), lround(10*SCALE_Y), lround(15*SCALE_Y), "Assets/PressStart2P.ttf");
        auto* levelText = AF->makeText("LEVEL:",lround(10*SCALE_X),lround(10*SCALE_Y),lround(15*SCALE_Y),"Assets/PressStart2P.ttf");

        GameController::getInstance().getEventmanager() ->addObserver(pla); //adding the player as an observer

        win->setBackground(GameController::getInstance().getFactory()->makeSprite("Assets/background.png"));
        win->setIcon(GameController::getInstance().getFactory()->makeIcon("Assets/spaceshipIcon.png"));

        while (!win->pollEvents()) //while escape hasn't been touched
        {
            timePast = win->getTimePast(); //get time it took to create a frame
            if(pla->isShoot()) //if player has hit spacebar
                buCo->addBullet(lround(pla->getXpos()+pla->getWidth()/2), pla->getYpos(),-1,false);
            pla->update(timePast); //move player in relation to the time
            scoreText->setText("SCORE:"+to_string(buCo->getScore()));
            levelText->setText("LEVEL:"+to_string(enCo->getLevel()));

            win->enqueueGO(pla);          //set player in a list to be shown on screen
            win->enqueueText(scoreText);  //set text to be shown on screen
            win->enqueueText(levelText);
            enCo->enqueueEnemies(win);   //set all the enemies to be shown on screen (in EnemyController)
            buCo->enqueueBullets(win);   //set bullets to be shown on screen

            enCo->moveEnemies(timePast);
            miscCo->bonus(timePast,win); //try to spawn bonusship

            buCo->moveBullets(timePast,enCo->getEnemyVector(),miscCo->getBonusVector()); //move bullets (if not hit) according to time
            miscCo->showHealth(pla->getHealth()); //set health to be shown on screen


            if(enCo->isGameOver()) //if enemies has hit the bottom
            {
                gameOver = true;
                enCo->setGameOver(false);//reset gameOver variable in enCo
            }

            if(pla->getHealth()<=0)
            {
                gameOver = true;
            }

            win->draw(); //draw everything that has been queued

            if(gameOver)
            {
                win->setBackground(GameController::getInstance().getFactory()->makeSprite("Assets/GameOver.png")); //set background to gameover background
                auto* gameOverText = AF->makeText(std::string("Score"), lround(SCREEN_WIDTH/2 -100*SCALE_X), lround(10*SCALE_Y), lround(25*SCALE_Y), "Assets/PressStart2P.ttf");
                pla->setRestart(false); //space hit during game won't count

                while(!win->pollEvents()) //while escape isn't hit
                {
                    restart = pla->isRestart();                                       //set restart to the restart in player, if player hits space restart will be true
                    gameOverText->setText("Score:"+to_string(buCo->getScore())); //set gameovertext as text to the score the player got
                    win->enqueueText(gameOverText);                                   //set text to be shown on screen
                    win->draw();                                                      //draw background and score
                    if(restart)                                                       //if space was hit we'll want to restart;
                        break;
                }

                gameOver = false;             //set gameover back to false
                pla->setHealth(START_HEALTH); //reset player health
                pla->setShoot(false);   //set shoot to false, otherwise the space of restart will be counted as a bullet shot
                pla->setXpos(lround(SCREEN_WIDTH/2));
                pla->setYpos(lround(SCREEN_HEIGHT-20*SCALE_Y-SCALE_Y*773/8));
                win->setBackground(GameController::getInstance().getFactory()->makeSprite("Assets/background.png")); //set background back to game background
                enCo->removeEnemies();
                buCo->removeBullets();
                miscCo->removeBonus();
                buCo->setScore(0); //reset score
                if(!restart)             // if we got out of gamover pollevents but not because of restart -> because of escape button-> stop game
                    break;               //go out of pollevent loop
            }
        }
        
        delete pla; //delete everything
        delete buCo;
        delete enCo;
        delete miscCo;
        delete scoreText;
        win->remove(); //remove window
    }
}

