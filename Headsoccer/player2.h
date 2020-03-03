#ifndef PLAYER2_H_INCLUDED
#define PLAYER2_H_INCLUDED
#include <iostream>
#include <cmath>
#include <SDL.h>
#include <string>
#include "maincontrol.h"
#include "classPainter.h"

using namespace std;


class Player2{
    static float x;
    static float y;
    float y_jump;
    float angle;
    int jumping;
public:
    Player2();
    virtual ~ Player2();
    void startgame();
    void render(SDL_Renderer *renderer);
    void update();
    void handleEvent(SDL_Event&);
    static float getX();
    static float getY();
};




#endif // PLAYER1_H_INCLUDED

