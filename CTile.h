#ifndef _CTILE_H_
    #define _CTILE_H_

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "CSprite.h"


enum {TILE_TYPE_NONE = 0,
      TILE_TYPE_SOLID = 1,
      TILE_TYPE_WALKABLE = 2,
      TILE_TYPE_DMG = 3,
      TILE_TYPE_CLIMBABLE = 4,
      TILE_TYPE_UNDERWATER = 5};


class CTile
{
    public:
        CTile();

        int TempTileID;
        int TempTypeID;

        int GetTileID();
        int GetTypeID();
        int GetSize();

        bool IsOnScreen(int X, int Y);

    private:
        int TileID;
        int TypeID;

        static const int TILE_SIZE = 32;
};


#endif // _CTILE_H_
