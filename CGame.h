#ifndef _CGAME_H_
    #define _CGAME_H_


#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

#include "CSprite.h"
#include "CPlayer.h"
#include "CTile.h"
#include "CMap.h"
#include "CBackground.h"

#include <iostream>


class CGame
{
    public:
        CGame();

    public:
        bool OnInit();
        void OnEvent(SDL_Event* Event);
        void OnUpdate();
        void OnRender();
        void OnCleanup();

        int GetScreenWidth();
        int GetScreenHeight();

        SDL_Renderer* GetRenderer();
        SDL_Event* GetEvent();

        bool bRunning;

        const float GRAVITY = 9.81;

    private:
        int SCREEN_WIDTH;
        int SCREEN_HEIGHT;

        SDL_Window* MainWindow;
        SDL_Renderer* MainRenderer;
        SDL_Event* MainEvent;
        SDL_Surface* MainWindowSurface;
        SDL_Surface* MainIcon;

        SDL_Texture* tPlayer = NULL;
        SDL_Rect rcMiniMap;

        Mix_Music* Soundtrack = NULL;

        CPlayer Player;
        CMap Map;
        CTile Tile;
        CBackground Background;

};


#endif // _CGAME_H_
