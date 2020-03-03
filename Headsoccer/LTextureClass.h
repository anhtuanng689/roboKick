#ifndef LTEXTURECLASS_H_INCLUDED
#define LTEXTURECLASS_H_INCLUDED
#ifndef PLAYER1_H_INCLUDED
#define PLAYER1_H_INCLUDED
#include <iostream>
#include <cmath>
#include <SDL.h>
#include <string>
#include "maincontrol.h"
#include "classPainter.h"
class LTexture
{
    public:
        //Initializes variables
        LTexture();

        //Deallocates memory
        ~LTexture();

        //Loads image at specified path
        bool loadFromFile( std::string path );

        //Deallocates texture
        void free();

        //Renders texture at given point
        void render( int x, int y );

        //Gets image dimensions
        int getWidth();
        int getHeight();

    private:
        //The actual hardware texture
        SDL_Texture* mTexture;

        //Image dimensions
        int mWidth;
        int mHeight;
};

#endif // LTEXTURECLASS_H_INCLUDED
