#ifndef _CPLAYER_H_
    #define _CPLAYER_H_


#include "CSprite.h"
#include "CTile.h"
#include "CMap.h"



class CPlayer
{
    public:
        CPlayer();

    public:
        void Init(SDL_Renderer* pRenderer);
        void HandleInput(SDL_Event* Event);
        void Animate(int MaxFrames);
        void Update(CMap* Map);
        void Render(SDL_Renderer* pRenderer);
        void KeepBounds();

        void SetPosX(float PosX);
        void SetPosY(float PosY);

        float GetPosX();
        float GetPosY();

        bool Collision_Hor(int x, int y, int &TileCoordY, CMap* Map);
        bool Collision_Ver(int x, int y, int &TileCoordX, CMap* Map);


    private:
        SDL_Texture* m_tPlayer;

        const int PLAYER_WIDTH = 28;
        const int PLAYER_HEIGHT = 32;

        float VelX;
        float VelY;

        float VELOCITY_X;
        float VELOCITY_Y;

        float PosX;
        float PosY;

        int CurrentFrame;
        int CurrentColumn;

        bool m_bMovingRight;
        bool m_bMovingLeft;

        bool m_bisAlive;
        bool m_bisDead;

        bool m_bisJumping;
        bool m_bLockJump;

        CSprite SpritePlayer;
        CTile Tile;

};


#endif // _CPLAYER_H_
