#ifndef _CMAP_H_
    #define _CMAP_H_


#include "SDL.h"
#include "SDL_image.h"

#include "CTile.h"
#include "CSprite.h"

#include <fstream>
#include <iostream>
#include <vector>



class CMap
{
    public:
        CMap();

    public:
        bool Load(SDL_Renderer* pRenderer, char* File, int MapWidth, int MapHeight);
        void Render(SDL_Renderer* pRenderer);

        int GetTypeOfTile(int X, int Y);
        bool IsCompleted() { return m_Completed; }

        std::vector<CTile> TileList;

        float GetWidth() { return MAP_WIDTH; }
        float GetHeight() { return MAP_HEIGHT; }

    private:
        int MAP_WIDTH;
        int MAP_HEIGHT;

        int MAP_WIDTH_IN_TILES;
        int MAP_HEIGHT_IN_TILES;

        bool m_Completed;

        CSprite TileSheet;
        CTile Tile;


};



#endif // _CMAP_H_
