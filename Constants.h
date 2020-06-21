//
// Created by Tijs Van Alphen on 29/03/2020.
//

#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

const int SCREEN_WIDTH_DEFAULT = 1280;
const int SCREEN_HEIGHT_DEFAULT = 720;
const int SCREEN_WIDTH = 2560/2;
const int SCREEN_HEIGHT = 1440/2;
const int ENEMY_BULLET_WIDTH = 15;
const int ENEMY_BULLET_HEIGHT = 30;
const int PLAYER_BULLET_WIDTH = 10;
const int PLAYER_BULLET_HEIGHT = 28;

const int ENEMY_HEIGHT=185/2.7;
const int ENEMY_WIDTH=200/2.7;
const int BONUSSHIP_WIDTH =100;
const int BONUSSHIP_HEIGHT = 50;


const int PLAYER_SPEED = 500;
const int ENEMY_SPEED = 150;
const int ENEMY_BULLET_SPEED = 160;
const int PLAYER_BULLET_SPEED =500;
const int BONUSSHIP_SPEED=100;
const int SPEED_MULTIPLIER = 10;//(SPEED_MULTIPLIER+level-1)/SPEED_MULTIPLIER -> SPEED_MULTIPLIER = how many levels before speed doubles

const int CHANCE =700; //chance of the enemy shooting a bullet (lower is more chance)
const int BONUSCHANCE =2000;

const int DROPDOWNAMOUNT =30; //how much the enemies go down if they hit the border
const int ROWS =4; //amount of rows of enemies
const int COLUMNS =6; //amount of columns of enemies
const int MAX_HEALTH =5;
const int START_HEALTH =3;

const double SCALE_X = SCREEN_WIDTH/ static_cast<double>(SCREEN_WIDTH_DEFAULT);
const double SCALE_Y = SCREEN_HEIGHT/ static_cast<double>(SCREEN_HEIGHT_DEFAULT);

const uint32_t Time_120fps = 1000/120;

#endif //GAME_CONSTANTS_H
