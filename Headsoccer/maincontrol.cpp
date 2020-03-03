#include "MainControl.h"
int MainControl::WIDTH;
int MainControl::HEIGHT;
Ball *ball = nullptr;
Player1 *player1 = nullptr;
Player2 *player2 = nullptr;

MainControl::MainControl()
{
    //ctor
    //init the data
    this->window   = nullptr;
    this->renderer = nullptr;
    this->end_loop = false;
}

MainControl::~MainControl()
{
    //dtor
}

void MainControl::initializeSDL(std::string program_name,const int&x,const int& y,const int& width,const int& height,const int& screen_option)
{
    WIDTH= width;
    HEIGHT=height;
    //initialize the SDL function
    if(SDL_Init(SDL_INIT_EVERYTHING)<0)
    {
        std::cout<<"Can't Initialize the SDL Libraries"<<SDL_GetError();
        end_loop=true;
        return;
    }
    //initialize the SDL window
    window = SDL_CreateWindow(program_name.c_str(),x,y,width,height,screen_option);
    if(window==nullptr)
    {
        std::cout<<"Can't create Window "<<SDL_GetError();
        end_loop =true;
        return;
    }
    //initialize the SDL Renderer
    renderer = SDL_CreateRenderer(this->window,-1,0);
    if(renderer==nullptr)
    {
        std::cout<<"Can't create Renderer"<<SDL_GetError();
        end_loop=true;
        return;
    }
    loadBackground();
    player1 = new Player1();
    player2 = new Player2();
    ball = new Ball();
    //Initialize the data

}

//function to update the class element
void MainControl::update()
{
    ball->update();
}



void MainControl::handleEvent()
{
    player1->handleEvent(event);
    player2->handleEvent(event);
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            end_loop = true;
            break;
        case SDL_KEYUP:
            if(event.key.keysym.sym==SDLK_ESCAPE)
                end_loop=true;
            break;
        default :
            break;
    }


}


void MainControl::close()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
}


SDL_Window* MainControl::getWindow() const
{
    return this->window;
}

SDL_Renderer* MainControl::getRenderer()const
{
    return this->renderer;
}

bool MainControl::isEndLoop() const
{
        return this->end_loop;
}

void MainControl::setEndLoop(const bool& end_loop)
{
    this->end_loop=end_loop;
}

int MainControl::getWidth()
{
    return WIDTH;
}

int MainControl::getHeight()
{
    return HEIGHT;
}
void MainControl::render()
{
        loadBackground();
        ball->render(renderer);
        player1->render(renderer);
        player2->render(renderer);
        SDL_RenderPresent(renderer);
}
void MainControl::loadBackground(){
    Painter painter(window,renderer);
    painter.clearWithBgColor(WHITE_COLOR);
//    SDL_Rect bg_rect;
//    bg_rect.x=0;
//    bg_rect.y=0;
//    bg_rect.w=WIDTH;
//    bg_rect.h=HEIGHT;
//    SDL_Texture*texture;
//    SDL_Surface* background = IMG_Load( "bg.png" );
//    texture = SDL_CreateTextureFromSurface(renderer,background);
//    SDL_RenderCopy(renderer,texture,NULL,&bg_rect);
}
