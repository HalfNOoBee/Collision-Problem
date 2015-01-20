#ifndef _CENEMY_H_
    #define _CENEMY_H_


#include "CSprite.h"
#include <vector>



class CEnemy
{
    public:
        Init(SDL_Renderer* pRenderer, const char* cPath, int X, int Y, int Width, int Height);
        Update();
        Render();
        CleanUp();


    private:
        int PosX;
        int PosY;
        int Width;
        int Height;

        int Health;
        int VelX;
        int VelY;
        int CurrentFrame;
};



#endif // _CENEMY_H_
