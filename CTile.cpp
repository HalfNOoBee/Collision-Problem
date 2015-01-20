#include "CTile.h"
#include "CCamera.h"

CTile::CTile()
{
    TileID = 0;
    TypeID = TILE_TYPE_NONE;
}

int CTile::GetSize()
{
    return TILE_SIZE;
}

int CTile::GetTileID()
{
    return TileID;
}

int CTile::GetTypeID()
{
    return TypeID;
}

bool CTile::IsOnScreen(int X, int Y)
{
    TileID = TempTileID;
    TypeID = TempTypeID;


    if (X + TILE_SIZE >= CCamera::Camera.Viewport.x &&
        X <= CCamera::Camera.Viewport.x + CCamera::Camera.Viewport.w &&
        Y + TILE_SIZE >= CCamera::Camera.Viewport.y &&
        Y <= CCamera::Camera.Viewport.y + CCamera::Camera.Viewport.h)
    {
         return true;
    }
    else
    {
        return false;
    }
}


