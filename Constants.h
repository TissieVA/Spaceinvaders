//
// Created by Tijs Van Alphen on 29/03/2020.
//

#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

const int SCREEN_WIDTH_DEFAULT = 1280;
const int SCREEN_HEIGHT_DEFAULT = 720;
const int SCREEN_WIDTH = 1280;
const  int SCREEN_HEIGHT = 720;
const int BULLET_WIDTH = 10;
const int BULLET_HEIGHT = 10;

const int PLAYER_SPEED = 500;
const int ENEMY_SPEED = 100;
const int BULLET_SPEED = 150;

const int CHANCE =1000;


const double SCALE_X = SCREEN_WIDTH/ static_cast<double>(SCREEN_WIDTH_DEFAULT);
const double SCALE_Y = SCREEN_HEIGHT/ static_cast<double>(SCREEN_HEIGHT_DEFAULT);

const uint32_t Time_120fps = 1000/120;

#endif //GAME_CONSTANTS_H