#ifndef CLASSPAINTER_H_INCLUDED
#define CLASSPAINTER_H_INCLUDED
#include <iostream>
#include <cmath>
#include <string>
#include "player1.h"
#include <SDL.h>
#include <SDL_image.h>
#include "SDLfunctions.h"
#include "maincontrol.h"


class Painter{
    float x;
    float y;
    float angle;
    int width;
    int height;
    SDL_Color color;
    SDL_Renderer* renderer;
    SDL_Window* window;

public:
    Painter(SDL_Window* window, SDL_Renderer* renderer);
    void setPosition(float x, float y);
    float getX() const { return x; }
    float getY() const { return y; }
    void setAngle(float angle);
    float getAngle() const { return angle; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    void setColor(SDL_Color color);
    SDL_Color getColor() const { return color; }
    void clearWithBgColor(SDL_Color color);
    SDL_Renderer* getRenderer() const { return renderer; }
    void moveForward(float length);
    void jumpForward(float length);
    void moveBackward(float length);
    void jumpBackward(float length);
    void turnLeft(float angle);
    void turnRight(float angle);
    SDL_Texture* loadTexture( string path );
    bool createImage( SDL_Texture* texture );
};




#endif // CLASSPAINTER_H_INCLUDED
