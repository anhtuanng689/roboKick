#ifndef MAINCONTROL_H
#define MAINCONTROL_H

#include <iostream>
#include <SDL.h>

//#include "SDLDraw.h"
#include "ball.h"
#include "player1.h"
#include "player2.h"
#include "ball.h"
#include "classPainter.h"
#include "const.h"


class MainControl
{
    public:
        MainControl();
        virtual ~MainControl();
        void initializeSDL(std::string program_name,const int&x,const int& y,const int& width,const int& height,const int& screen_option);
        void update();
        void handleEvent();
        void close();
        SDL_Window* getWindow() const;
        SDL_Renderer* getRenderer() const;
        bool isEndLoop() const;
        void setEndLoop(const bool&);
        static int getWidth() ;
        static int getHeight() ;
        void render();
        void loadBackground();

    protected:
        static int WIDTH;
        static int HEIGHT;
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Event event;
        bool end_loop;
};

#endif // MAINCONTROL_H

