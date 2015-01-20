#include "CTTF.h"


CTTF::CTTF(int x, int y)
{
    m_PosX = x;
    m_PosY = y;

    Font = NULL;
    Texture = NULL;

}

void CTTF::Load(SDL_Renderer* pRenderer, const char* FontPath, int FontSize)
{
    Font = TTF_OpenFont(FontPath,FontSize);
    if (Font == NULL)
    {
        std::cout << TTF_GetError() << std::endl;
    }
}

void CTTF::Render(SDL_Renderer* pRenderer, std::string Text, int R, int G, int B)
{

    textColor.r = R;
    textColor.g = G;
    textColor.b = B;

    SDL_Surface* tempSurface;
    tempSurface = TTF_RenderText_Blended(Font,Text.c_str(),textColor);
    if (tempSurface == NULL)
    {
        std::cout << TTF_GetError() << std::endl;
    }
    else
    {
        Texture = SDL_CreateTextureFromSurface(pRenderer,tempSurface);
        if (Texture == NULL)
        {
            std::cout << TTF_GetError() << std::endl;
        }
        else
        {
            SDL_QueryTexture(Texture,NULL,NULL,&m_Width,&m_Height);
            textRect.x = m_PosX;
            textRect.y = m_PosY;
            textRect.w = m_Width;
            textRect.h = m_Height;
        }
    }

    SDL_RenderCopy(pRenderer,Texture,NULL,&textRect);
}


