#include "player2.h"
float Player2::x;
float Player2::y;
Player2::Player2(){
    this->x= 600;
    this->y= 450;
    this->angle=90;
    this->y_jump= 100;
    this->jumping =1;
}

Player2::~Player2(){

};

void Player2::render(SDL_Renderer *renderer){

    SDL_Texture* texture_head = NULL;
    SDL_Texture* texture_leg = NULL;
    SDL_Rect head_rect;
    head_rect.x=x-50;
    head_rect.y=y-75;
    head_rect.w=75;
    head_rect.h=75;
    SDL_Surface* head = IMG_Load( "player2head.bmp" );
    SDL_Rect leg_rect;
    leg_rect.x=x-50;
    leg_rect.y=y;
    leg_rect.w=50;
    leg_rect.h=50;
    texture_head= SDL_CreateTextureFromSurface(renderer,head);
    SDL_RenderCopy(renderer,texture_head,NULL,&head_rect);
    SDL_Surface* leg = IMG_Load("player2leg.bmp");
    texture_leg= SDL_CreateTextureFromSurface(renderer,leg);
    SDL_RenderCopy(renderer,texture_leg,NULL, &leg_rect);
    SDL_DestroyTexture(texture_head);
    SDL_DestroyTexture(texture_leg);
    SDL_FreeSurface(head);
    SDL_FreeSurface(leg);
}
void Player2::startgame(){

};
void Player2::update(){

};
void Player2::handleEvent(SDL_Event& event2){
    SDL_PollEvent(&event2);
    switch(event2.type){
    case SDL_KEYDOWN:
            if(event2.key.keysym.sym ==SDLK_LEFT){
                if(x-50<=50) break;
                else x=x-30;
            }
            else if(event2.key.keysym.sym ==SDLK_RIGHT){
                if(x+25>=MainControl::getWidth()-50) break;
                else x=x+30;
            }
            else if(event2.key.keysym.sym ==SDLK_UP){
                if(y>450-y_jump&&jumping==1) y-=(y_jump/2);
                else if(y==450-y_jump) {
                    y+=(y_jump/2);
                    jumping=-1;
                }
                else if(y<450&&y>450-y_jump&&jumping==-1) {
                    y+=y_jump/2;
                }
                else if(y==450&&jumping==-1){
                    jumping=1;
                }

            }

            break;
        case SDL_MOUSEBUTTONDOWN:
//            if(event.button.button==SDL_BUTTON_LEFT){
//                x=2;
//                y=0;
//                x=event.motion.x;
//                y=event.motion.y;
//            }
            break;
        default:
            break;
    }
};
float Player2::getX(){

    return x;
}
float Player2::getY(){
    return y;
}
