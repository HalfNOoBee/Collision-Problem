#include "CAttack.h"

std::vector<CAttack> CAttack::AttackList;

CAttack::CAttack()
{
    PosX = 0;
    PosY = 0;
    Width = 16;
    Height = 16;

    CurrentFrame = 0;
    MaxFrames = 4;
}

void CAttack::Load(SDL_Renderer* pRenderer)
{
    m_tFireball = AttackSprite.Load(pRenderer,"data/imgs/player/attacks/Fireball.png",255,0,255);
}

void CAttack::New()
{   CAttack newAttack;
    CAttack::AttackList.push_back(newAttack);
}


void CAttack::Update()
{

    if (CurrentFrame >= MaxFrames)
    {
        CurrentFrame = 0;
    }

    CurrentFrame++;

    AttackSprite.SetSourceRect(Width * CurrentFrame,0,Width,Height);
}


void CAttack::Render(SDL_Renderer* pRenderer)
{
    AttackSprite.SetDestinationRect(PosX,PosY,Width,Height);
    AttackSprite.Render(pRenderer);
}

/*int CAttack::ResetCooldown()
{
    Cooldown = 35; //FPS is 35 --> 1 sec per shot

    Cooldown--;
}

bool CAttack::CanAttack()
{
    if (Cooldown == 0)
    {
        m_bCanAttack = true;
    }
    else
    {
        m_bCanAttack = false;
    }

    return m_bCanAttack;
}*/


