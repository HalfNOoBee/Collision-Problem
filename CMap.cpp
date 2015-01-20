#include "CMap.h"
#include "CCamera.h"

CMap::CMap()
{
    StartX = 0;
    StartY = 0;

    MaxX = 1600;
    MaxY = 480;

    MAP_WIDTH = 0;
    MAP_HEIGHT = 0;

    m_Completed = false; //Player has reached end of Level

}

bool CMap::Load(SDL_Renderer* pRenderer, char* File, int MapWidth, int MapHeight)
{
    MAP_WIDTH = MapWidth;
    MAP_HEIGHT = MapHeight;
    MAP_WIDTH_IN_TILES = MapWidth / Tile.GetSize();
    MAP_HEIGHT_IN_TILES = MapHeight / Tile.GetSize();

    TileList.clear();

    FILE* FileHandle = fopen(File, "r");

    if(FileHandle == NULL)
    {
        return false;
    }

    for(int Y = 0; Y < MAP_HEIGHT; Y++)
    {
        for(int X = 0; X < MAP_WIDTH; X++)
        {
            CTile tempTile;

            fscanf(FileHandle, "%d:%d ", &tempTile.TempTileID, &tempTile.TempTypeID);

            TileList.push_back(tempTile);
        }
        fscanf(FileHandle, "\n");
    }

    fclose(FileHandle);

    TileSheet.Load(pRenderer, "data/imgs/tiles/Tileset-Blocks2.png", 255, 0, 255);

    return true;
}

void CMap::Render(SDL_Renderer* pRenderer)
{

    int ID = 0;
    CCamera Camera;

    for(int Y = 0; Y < MAP_HEIGHT_IN_TILES; Y++)
    {
        for(int X = 0; X < MAP_WIDTH_IN_TILES; X++)
        {
            if (TileList[ID].IsOnScreen(X * Tile.GetSize(),Y * Tile.GetSize()) == false)
            {
                ID++;
                continue;
            }
            else
            {
                if(TileList[ID].GetTileID() == 0) //No Tile
                {
                    ID++;
                    continue;
                }

                else if (TileList[ID].GetTileID() == 1) //
                {
                    TileSheet.SetSourceRect(0, 0, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }

                else if (TileList[ID].GetTileID() == 2) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize(), 0, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }

                else if (TileList[ID].GetTileID() == 3) //
                {

                    TileSheet.SetSourceRect(Tile.GetSize()*2, 0, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize()  + StartY, Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 4) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()*3, 0, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize()  + StartY, Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 5) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()*4, 0, Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize()  + StartY, Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 6) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()*5, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 14) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()*2, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 20) //
                {
                    TileSheet.SetSourceRect(0, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 21) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize(), Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() - CCamera::Camera.GetPosX(), Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 22) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()*2, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 23) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()*3, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 24) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()*4, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 25) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()*5, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 26) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()*6, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 27) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()*7, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 28) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()*8, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 29) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()*9, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
                else if (TileList[ID].GetTileID() == 30) //
                {
                    TileSheet.SetSourceRect(Tile.GetSize()*10, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                    TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                    TileSheet.Render(pRenderer);
                    ID++;
                    continue;
                }
            }
        }
    }
}

int CMap::GetTypeOfTile(int X, int Y)
{
    return TileList[Y*MAP_WIDTH_IN_TILES + X].GetTypeID();
}

void CMap::SetCameraPos (int PosX, int PosY)
{
    if (PosX > 0)
    {
        StartX += PosX;
    }
    else if (PosX < 0)
    {
        StartX += PosX;
    }

}

