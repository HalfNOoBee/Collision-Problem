#ifndef _CCAMERA_H_
    #define _CCAMERA_H_

#include "SDL.h"
#include <iostream>


class CGame;


class CCamera
{
    public:
        static CCamera Camera;
        CCamera();

        void SetPosX(float MovementSpeed);
        float GetPosX();
        float GetPosY();

        SDL_Rect Viewport;

    private:
        float m_PosX;
        float m_PosY;
        float m_Width;
        float m_Height;

};





#endif // _CCAMERA_H_
