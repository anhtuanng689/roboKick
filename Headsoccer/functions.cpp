#include <iostream>
#include <SDL.h>
#include "const.h"
#include <string>
#include <math.h>
#include "classPainter.h"
#include "player1.h"
#include <Windows.h>
#include <conio.h>
#include <SDL_image.h>
#include "SDLfunctions.h"
using namespace std;

void logSDLError(std::ostream& os,const std::string &msg, bool fatal){
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);
        window = SDL_CreateWindow(WINDOW_TITLE.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        //SDL_Renderer *renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));if (renderer == nullptr)logSDLError(std::cout, "CreateRenderer", true);SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);}
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}
void quitSDL(SDL_Window* window, SDL_Renderer* renderer){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
Painter::Painter(SDL_Window* window, SDL_Renderer* renderer_):
    renderer(renderer_){
        SDL_RenderGetLogicalSize(renderer, &width, &height);
        if (width == 0 && height == 0)SDL_GetWindowSize(window, &width, &height);
        setPosition(width/2, height/2);
        setAngle(0);
        setColor(BLACK_COLOR);
        clearWithBgColor(WHITE_COLOR);
}
void waitUntilKeyPressed(){
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&(e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
        return;
        SDL_Delay(100);
    }
}
void Painter::setPosition(float x, float y){
    this->x = x;
    this->y = y;
}
void Painter::setAngle(float angle){
    this->angle = angle - floor(angle/360)*360;
}
SDL_Texture* Painter::loadTexture( string path ){
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if ( loadedSurface == NULL )
            cout << "Unable to load image " << path << " SDL_image Error: " << IMG_GetError() << endl;
        else {
            newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
            if( newTexture == NULL )
                cout << "Unable to create texture from " << path << " SDL Error: " << SDL_GetError() << endl;
            SDL_FreeSurface( loadedSurface );
        }
    return newTexture;
}
void Painter::setColor(SDL_Color color){
    this->color = color;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 0);
}
void Painter::clearWithBgColor(SDL_Color bgColor){
    SDL_Color curColor = color;
    setColor(bgColor);
    SDL_RenderClear(renderer);
    setColor(curColor);
}
void Painter::moveForward(float length){
    float prevX = x, prevY = y;
    jumpForward(length);
    SDL_RenderDrawLine(renderer, (int)prevX, (int)prevY, (int)x, (int)y);
}
void Painter::jumpForward(float length){
    float rad = (angle / 180) * M_PI;
    x += cos(rad) * length;
    y -= sin(rad) * length;
}
void Painter::moveBackward(float length){
    moveForward(-length);
}
void Painter::jumpBackward(float length){
    jumpForward(-length);
}
void Painter::turnLeft(float angle){
    setAngle(this->angle+angle);
}
void Painter::turnRight(float angle){
    setAngle(this->angle-angle);
}
float generateRandomNumber(){
    return (float) rand() / RAND_MAX;
}


bool Painter::createImage( SDL_Texture* texture ){
    if( texture == NULL ) return false;
    SDL_RenderCopy( renderer, texture, NULL, NULL );
    return true;
}

