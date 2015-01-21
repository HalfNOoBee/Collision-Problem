#ifndef _CENEMY_H_
    #define _CENEMY_H_


#include "CSprite.h"


class CEnemy
{
    public:
        virtual void Load() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;

        virtual float GetPosX() { return m_PosX; }
        virtual float GetPosY() { return m_PosY; }

        virtual float GetWidth() { return m_Width; }
        virtual float GetHeight() { return m_Height; }

        virtual bool CheckToMap();

    private:
        float m_PosX;
        float m_PosY;
        float m_Width;
        float m_Height;

        CSprite Sprite;
};






#endif // _CENEMY_H_
