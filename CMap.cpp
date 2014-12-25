#include "CMap.h"

CMap::CMap()
{
    StartX = 0;
    StartY = 0;

    MaxX = 800;
    MaxY = 480;

    MAP_WIDTH = 0;
    MAP_HEIGHT = 0;

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

            fscanf(FileHandle, "%d:%d ", &tempTile.TileID, &tempTile.TypeID);

            TileList.push_back(tempTile);
        }
        fscanf(FileHandle, "\n");
    }

    fclose(FileHandle);

    TileSheet.Load(pRenderer, "data/imgs/tiles/bigmap/Tileset-Blocks.png", 255, 0, 255);

    return true;
}

void CMap::Render(SDL_Renderer* pRenderer)
{

    int ID = 0;

    for(int Y = 0; Y < MAP_HEIGHT/Tile.GetSize(); Y++)
    {
        for(int X = 0; X < MAP_WIDTH/Tile.GetSize(); X++)
        {
            if(TileList[ID].TileID == 0) //No Tile
            {
                ID++;
                continue;
            }

            else if (TileList[ID].TileID == 1) //
            {
                TileSheet.SetSourceRect(0, 0, Tile.GetSize(), Tile.GetSize());
                TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize()  + StartY, Tile.GetSize(), Tile.GetSize());
                TileSheet.Render(pRenderer);
                ID++;
                continue;
            }

            else if (TileList[ID].TileID == 2) //
            {
                TileSheet.SetSourceRect(Tile.GetSize(), 0, Tile.GetSize(), Tile.GetSize());
                TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize()  + StartY, Tile.GetSize(), Tile.GetSize());
                TileSheet.Render(pRenderer);
                ID++;
                continue;
            }

            else if (TileList[ID].TileID == 3) //
            {

                TileSheet.SetSourceRect(Tile.GetSize()*2, 0, Tile.GetSize(), Tile.GetSize());
                TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize()  + StartY, Tile.GetSize(), Tile.GetSize());
                TileSheet.Render(pRenderer);
                ID++;
                continue;
            }
            else if (TileList[ID].TileID == 4) //
            {
                TileSheet.SetSourceRect(Tile.GetSize()*3, 0, Tile.GetSize(), Tile.GetSize());
                TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize()  + StartY, Tile.GetSize(), Tile.GetSize());
                TileSheet.Render(pRenderer);
                ID++;
                continue;
            }
            else if (TileList[ID].TileID == 5) //
            {
                TileSheet.SetSourceRect(Tile.GetSize()*4, 0, Tile.GetSize(), Tile.GetSize());
                TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize()  + StartY, Tile.GetSize(), Tile.GetSize());
                TileSheet.Render(pRenderer);
                ID++;
                continue;
            }
            else if (TileList[ID].TileID == 6) //
            {
                TileSheet.SetSourceRect(Tile.GetSize()*5, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                TileSheet.Render(pRenderer);
                ID++;
                continue;
            }
            else if (TileList[ID].TileID == 14) //
            {
                TileSheet.SetSourceRect(Tile.GetSize()*2, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                TileSheet.Render(pRenderer);
                ID++;
                continue;
            }
            else if (TileList[ID].TileID == 20) //
            {
                TileSheet.SetSourceRect(0, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                TileSheet.Render(pRenderer);
                ID++;
                continue;
            }
            else if (TileList[ID].TileID == 21) //
            {
                TileSheet.SetSourceRect(Tile.GetSize(), Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                TileSheet.Render(pRenderer);
                ID++;
                continue;
            }
            else if (TileList[ID].TileID == 22) //
            {
                TileSheet.SetSourceRect(Tile.GetSize()*2, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                TileSheet.Render(pRenderer);
                ID++;
                continue;
            }
            else if (TileList[ID].TileID == 23) //
            {
                TileSheet.SetSourceRect(Tile.GetSize()*3, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                TileSheet.Render(pRenderer);
                ID++;
                continue;
            }
            else if (TileList[ID].TileID == 24) //
            {
                TileSheet.SetSourceRect(Tile.GetSize()*4, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                TileSheet.Render(pRenderer);
                ID++;
                continue;
            }
            else if (TileList[ID].TileID == 25) //
            {
                TileSheet.SetSourceRect(Tile.GetSize()*5, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                TileSheet.Render(pRenderer);
                ID++;
                continue;
            }
            else if (TileList[ID].TileID == 26) //
            {
                TileSheet.SetSourceRect(Tile.GetSize()*6, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                TileSheet.Render(pRenderer);
                ID++;
                continue;
            }
            else if (TileList[ID].TileID == 27) //
            {
                TileSheet.SetSourceRect(Tile.GetSize()*7, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                TileSheet.Render(pRenderer);
                ID++;
                continue;
            }
            else if (TileList[ID].TileID == 28) //
            {
                TileSheet.SetSourceRect(Tile.GetSize()*8, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                TileSheet.Render(pRenderer);
                ID++;
                continue;
            }
            else if (TileList[ID].TileID == 29) //
            {
                TileSheet.SetSourceRect(Tile.GetSize()*9, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                TileSheet.Render(pRenderer);
                ID++;
                continue;
            }
            else if (TileList[ID].TileID == 30) //
            {
                TileSheet.SetSourceRect(Tile.GetSize()*10, Tile.GetSize(), Tile.GetSize(), Tile.GetSize());
                TileSheet.SetDestinationRect (X * Tile.GetSize() + StartX, Y * Tile.GetSize() + StartY, Tile.GetSize(), Tile.GetSize());
                TileSheet.Render(pRenderer);
                ID++;
                continue;
            }

        }
    }

    //std::cout << "Total Tiles detected: " << ID << "\n";
}

int CMap::GetTypeOfTile(int X, int Y)
{
    return TileList[Y * MAP_WIDTH_IN_TILES + X].TypeID;
}

void CMap::SetCameraPos (int PosX, int PosY)
{
    if (PosX > 0)
    {
        StartX += 5;
    }
    else if (PosX < 0)
    {
        StartX -= 5;
    }

}

