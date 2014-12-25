#ifndef _CBACKGROUND_H_
    #define _CBACKGROUND_H_


#include "CSprite.h"
#include "SDL.h"
#include "SDL_image.h"


class CBackground
{
    public:
        CBackground();

        bool Init(SDL_Renderer* pRenderer);
        void Update(SDL_Renderer* pRenderer);
        void Render(SDL_Renderer* pRenderer);
        void CleanUp();

    private:

        int PosX;
        int PosY;
        int Width;
        int Height;

        SDL_Texture* m_tBackground;
        SDL_Texture* m_tBackground2;

        CSprite BackgroundSprite;
        CSprite BackgroundSprite2;


};





#endif // _CBACKGROUND_H_
