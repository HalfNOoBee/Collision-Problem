#ifndef _CTEXT_H_
    #define _CTEXT_H_


#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>


class CText
{
    public:
        CText();

        SDL_Texture* PrintText (const char* Message, const char* FontPath, int FontSize, SDL_Color Color);

        void SetMessage(std::string Message);
        void SetFont (std::string Font);
        void SetFontSize (int FontSize);

        std::string GetMessage();
        TTF_Font* GetFont();
        int GetFontSize();

    private:
        std::string s_mMessage;
        TTF_Font* p_mFont;
        int mFontSize;
        SDL_Color mColor;

};





#endif // _CTEXT_H_
