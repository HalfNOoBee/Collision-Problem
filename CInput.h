#ifndef _CINPUT_H_
    #define _CINPUT_H_


#include "SDL.h"
#include "SDL_image.h"
#include "CGame.h"

class CGame;

class CInput
{
    public:
        CInput();

    public:
        void HandleAllInput();
        void HandleWindow();

    private:
        CGame* Game;


};




#endif // _CINPUT_H_
