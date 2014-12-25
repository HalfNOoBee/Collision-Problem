#include "CTile.h"

CTile::CTile()
{
    TileID = 0;
    TypeID = TILE_TYPE_NORMAL;

}

int CTile::GetSize()
{
    return TILE_SIZE;
}


