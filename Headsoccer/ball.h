#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED
#include <iostream>
#include <cmath>
#include <SDL.h>
#include <string>
#include "maincontrol.h"
#include "player1.h"

class Ball{
    float x;
    float y;
    float dx;
    float dy;
    float ddx;
    float ddy;
    float angle;
    float radius;
public:
    Ball();
    virtual ~Ball();
    void render(SDL_Renderer *renderer);
    void update();
};


#endif // BALL_H_INCLUDED
