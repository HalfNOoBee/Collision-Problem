#ifndef _CTTF_H_
    #define _CTTF_H_

#include "SDL.h"
#include "SDL_ttf.h"
#include <iostream>
#include <string>


class CTTF
{
    public:
        CTTF(int x, int y);

        void Load(SDL_Renderer* pRenderer, const char* cPath, int FontSize);
        void Update(); //Probably update the std::string with stream
        void Render(SDL_Renderer* pRenderer, std::string Text, int R, int G, int B);


    private:
        int m_PosX;
        int m_PosY;
        int m_Width;
        int m_Height;

        TTF_Font* Font;
        SDL_Texture* Texture;
        SDL_Rect textRect;
        SDL_Color textColor;
        std::string Text;
};



#endif // _CTTF_H_

