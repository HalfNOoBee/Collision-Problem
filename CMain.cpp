#include "CGame.h"
#include "CPlayer.h"


CPlayer Player;
CGame Game;

const int FPS = 30;
const int DELAY_TIME = 1000.0f / FPS;



int main (int argc, char* argv [])
{
    Uint32 frameStart;
    Uint32 frameTime;

    if(Game.OnInit() == false)
    {
        return -1;
    }

    SDL_Event Event;

    while(Game.bRunning)
    {
        frameStart = SDL_GetTicks();

        while(SDL_PollEvent(&Event))
        {
            Game.OnEvent(&Event);
        }

        Game.OnUpdate();
        Game.OnRender();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < DELAY_TIME)
        {
            SDL_Delay((int) (DELAY_TIME - frameTime));
        }
    }

    Game.OnCleanup();


    return 0;
}
