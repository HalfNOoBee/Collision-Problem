#ifndef _CCAMERACONTROL_H_
    #define _CCAMERACONTROL_H_


#include "SDL.h"
#include "SDL_image.h"

#include "CGame.h"

enum {TARGET_MODE_NORMAL = 0,
      TARGET_MODE_CENTER = 1};

class CGame;

class CCamera
{
    public:
        static CCamera CameraControl;

        CCamera();

        void OnMove(int MoveX, int MoveY);

        int GetX();
        int GetY();

        void SetPos(int X, int Y);
        void SetTarget(int* X, int* Y);

        int TargetMode;


    private:
        int X;
        int Y;

        int* TargetX;
        int* TargetY;

        CGame* Game;

};



#endif // _CCAMERACONTROL_H_
