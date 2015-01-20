#ifndef _CATTACK_H_
    #define _CATTACK_H_


#include "CSprite.h"
#include <vector>


class CAttack
{
    public:
        CAttack();

    public:
        void Load(SDL_Renderer* pRenderer);
        void New();
        void Update();
        void Render(SDL_Renderer* pRenderer);
        void CleanUp();

        int GetWidth() { return Width; }
        int GetHeight() { return Height; }

        static std::vector <CAttack> AttackList;

    private:
        SDL_Texture* m_tFireball;

        int PosX;
        int PosY;
        int Width;
        int Height;

        int CurrentFrame;
        int MaxFrames;

        CSprite AttackSprite;
};


#endif // _CATTACK_H_
