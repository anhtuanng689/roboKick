#include <iostream>
#include <SDL.h>
#include "const.h"
#include <string>
#include <math.h>
#include "player1.h"
#include "player2.h"
#include "ball.h"
#include "maincontrol.h"
#include <Windows.h>
#include <conio.h>
#include <SDL_image.h>
#include "classPainter.h"
#include "SDLfunctions.h"
using namespace std;



int main(int argc, char *argv[])
{
    MainControl main_control=MainControl();
    main_control.initializeSDL("Head soccer",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_SHOWN);
    //start time when the loop start aka start time of frame
    Uint32 start_time;
    //main program loop
    while(!main_control.isEndLoop())                // while the loop isn't end
    {
        start_time= SDL_GetTicks();                 //get the current time as millisecond
        main_control.handleEvent();
        main_control.update();                //get the user event
        main_control.render();
        if(SDL_GetTicks()-start_time<DELAY_TIME)   //the time the frame took to execute
            SDL_Delay(SDL_GetTicks()-start_time);   //if the time of frame lower than time per frame  delay it a period of time
    }

    main_control.close();
	return 0;
}
