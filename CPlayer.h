#ifndef _CPLAYER_H_
    #define _CPLAYER_H_


#include "CSprite.h"
#include "CTile.h"
#include "CMap.h"
#include "CTTF.h"

#include "SDL_mixer.h"

#include <iomanip>
#include <string>
#include <sstream>




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
        void CleanUp();

        void SetPosX(float PosX);
        void SetPosY(float PosY);

        float GetPosX();
        float GetPosY();

        bool Collision_Hor(int x, int y, int &TileCoordY, CMap* Map);
        bool Collision_Ver(int x, int y, int &TileCoordX, CMap* Map);


    private:
        SDL_Texture* m_tPlayer;
        SDL_Texture* m_tFireball;

        const int PLAYER_WIDTH = 26;
        const int PLAYER_HEIGHT = 32;

        float VelX;
        float VelY;

        float MOVING_SPEED;
        float JUMPING_HEIGHT;

        float PosX;
        float PosY;

        float MaxSpeedX;
        float MaxSpeedY;

        int CurrentFrame;
        int CurrentColumn;

        Uint32 OldTime;
        Uint32 CurrentTime;
        float dtTime;

        std::string sScore;
        int m_Score;
        CTTF* ScoreField;
        CTTF* CurrentScoreField;

        bool m_bMovingRight;
        bool m_bMovingLeft;

        bool m_bisAlive;
        bool m_bisDead;

        bool m_bisJumping;
        bool m_bLockJump;

        CSprite SpritePlayer;
        CTile Tile;

        Mix_Chunk* Jump;
        Mix_Chunk* Blockhit;
};


#endif // _CPLAYER_H_
