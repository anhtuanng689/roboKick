#ifndef SDLFUNCTIONS_H_INCLUDED
#define SDLFUNCTIONS_H_INCLUDED
#include <iostream>
#include <SDL.h>
#include "const.h"
#include <string>
#include <math.h>
#include "classPainter.h"
#include <Windows.h>
#include <conio.h>
#include <SDL_image.h>
#include "player1.h"
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void logSDLError(std::ostream& os, const std::string &msg, bool fatal = false);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
SDL_Surface *LoadImage(std::string file_path);
#endif // SDLFUNCTIONS_H_INCLUDED
