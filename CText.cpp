#include "CText.h"


CText::CText()
{
    p_mFont = NULL;

}


SDL_Texture* CText::PrintText(const char* Message, const char* FontPath, int FontSize, SDL_Color Color)
{
    p_mFont = TTF_OpenFont(FontPath, FontSize);
    if (p_mFont == NULL)
    {
        std::cout << "Failed to open up the font saved at " << FontPath << "! TTF_Error: " << TTF_GetError() << "\n";
    }
    else
    {
        SDL_Surface* p_Surface = NULL;
        p_Surface = TTF_RenderText_Solid(p_mFont, Message, Color);
        if (p_Surface == NULL)
        {
            TTF_CloseFont(p_mFont);
            std::cout << "Failed to render" << Message << " text in solid! TTF_Error: " << TTF_GetError() << "\n";
        }
    }


}
