#include "CBackground.h"


CBackground::CBackground()
{
    m_tBackground = NULL;
    m_tBackground2 = NULL;

    PosX = 0;
    PosY = 0;

    Width = 750;
    Height = 480;
}


bool CBackground::Init(SDL_Renderer* pRenderer)
{
    m_tBackground = BackgroundSprite.Load(pRenderer,"data/imgs/backgrounds/Background - BrightBlue.png",255,0,255);
    BackgroundSprite.SetSourceRect(0,0,Width,Height);

    m_tBackground2 = BackgroundSprite2.Load(pRenderer,"data/imgs/backgrounds/Background - BrightBlue.png",255,0,255);
    BackgroundSprite2.SetSourceRect(0,0,Width,Height);
}

void CBackground::Update(SDL_Renderer* pRenderer)
{
    if (PosX > -Width)
    {
        PosX -= 1;
    }
    else if (PosX <= -Width)
    {
        PosX = 0;
    }
    //std::cout << PosX << "\n";
}

void CBackground::Render(SDL_Renderer* pRenderer)
{
    BackgroundSprite.SetDestinationRect(PosX,PosY,Width,Height);
    BackgroundSprite.Render(pRenderer);
    BackgroundSprite2.SetDestinationRect(PosX + Width,PosY,Width,Height);
    BackgroundSprite2.Render(pRenderer);
}



void CBackground::CleanUp()
{
    SDL_DestroyTexture(m_tBackground);
    SDL_DestroyTexture(m_tBackground2);
    std::cout << "Destroyed texture of background...\n";
}



