#ifndef _CTILE_H_
    #define _CTILE_H_

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "CSprite.h"

enum {TILE_TYPE_NORMAL = 0,
      TILE_TYPE_SOLID = 1};


class CTile
{
    public:
        CTile();

    public:
        int TileID;
        int TypeID;

        int GetSize();

    private:
        static const int TILE_SIZE = 16;
};


#endif // _CTILE_H_
