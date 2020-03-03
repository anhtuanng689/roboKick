#include "Ball.h"



Ball::Ball()
{
    this->angle = 60;
    this->x= 400;
    this->y= 100;
    this->radius = 30;
    this->ddx = 0;
    this->ddy = 20;
    this->dx=100;
    this->dy=100;


}

Ball::~Ball()
{
    //dtor
}


void Ball::render(SDL_Renderer* renderer)
{
    SDL_Texture *ball= NULL;
    SDL_Surface *ballsurface= IMG_Load("ball.png") ;
    ball=SDL_CreateTextureFromSurface(renderer,ballsurface);
    SDL_Rect ball_rect;
    ball_rect.x=x-radius;
    ball_rect.y=y-radius;
    ball_rect.h=2*radius;
    ball_rect.w=2*radius;
    SDL_RenderCopy(renderer,ball,NULL,&ball_rect);
    SDL_FreeSurface(ballsurface);
    SDL_DestroyTexture(ball);
    }

void Ball::update()
{
    dx+=ddx;
    dy+=ddy;
    x+=dx/3;
    y+=dy/3;
    if(x>MainControl::getWidth()-radius){
        x=MainControl::getWidth()-radius;
        dx=-dx*9/10;
        dy=dy*9/10;
        ddx=-ddx;
        ;
    }
    if(x<radius){
        x=radius;
        dx=-dx*9/10;
        dy=dy*9/10;
        ddx=-ddx;
        ;
    }
    if(y>MainControl::getHeight()-100-radius){
        y=MainControl::getHeight()-100-radius;
        dy=-dy*9/10;

    }
    if(y<radius){
        y=radius;
        dy=-dy*9/10;
        dx=dx*9/10;
    }
    if(y==MainControl::getHeight()-100-radius){
        dx=dx*9/10;
    }
    if(y+radius>=Player1::getY()-75&&x<Player1::getX()+50&&x>Player1::getX()-25){
        y=Player1::getY()-75-radius;
        dy-=100;
    }
    else if(x+radius>=Player1::getX()-25&&x<=Player1::getX()&&y<Player1::getY()+50&&y>Player1::getY()-75){
        x=Player1::getX()-25-radius;
        dx-=100;
    }
    else if(x-radius<=Player1::getX()+50&&x>=Player1::getX()&&y<Player1::getY()+50&&y>Player1::getY()-75){
        x=Player1::getX()+50+radius;
        dx+=100;
    }
    else if(y+radius>=Player2::getY()-75&&x<Player2::getX()+25&&x>Player2::getX()-50){
        y=Player2::getY()-75-radius;
        dy-=100;
    }
    else if(x+radius>=Player2::getX()-50&&x<=Player2::getX()&&y<Player2::getY()+50&&y>Player2::getY()-75){
        x=Player2::getX()-50-radius;
        dx-=100;
    }
    else if(x-radius<=Player2::getX()+25&&x>=Player2::getX()&&y<Player2::getY()+50&&y>Player2::getY()-75){
        x=Player2::getX()+25+radius;
        dx+=100;
    }
}



