#include "CPlayer.h"
#include "CGame.h"



CPlayer::CPlayer()
{
    m_tPlayer = NULL;

    PosX = 100.0f;
    PosY = 150.0f;

    VELOCITY_X = 5.0f;
    VELOCITY_Y = 15.0f;

    CurrentFrame = 0;
    CurrentColumn = 0;

    m_bMovingLeft = false;
    m_bMovingRight = false;
    m_bisAlive = true;

    m_bisJumping = false;
    m_bLockJump = false;
    m_bisDead = false;


}


void CPlayer::Init(SDL_Renderer* pRenderer)
{
    m_tPlayer = SpritePlayer.Load(pRenderer,"data/imgs/player/Mario.png", 255, 0, 255);
}

void CPlayer::HandleInput(SDL_Event* Event)
{

    /*switch (Event->type)
    {
        case SDL_KEYDOWN:
            switch (Event->key.keysym.sym)
            {
                case SDLK_a:
                    m_bMovingLeft = true;
                    VelX = -VELOCITY_X;
                    CurrentFrame++;
                    std::cout << "MovingLeft: " << m_bMovingLeft << "\n";
                    break;

                case SDLK_d:
                    m_bMovingRight = true;
                    VelX = VELOCITY_X;
                    CurrentFrame++;
                    break;

                case SDLK_SPACE:
                    m_bisJumping = true;
                    m_bLockJump = true;
                    VelY = -VELOCITY_Y;
                    CurrentFrame = 1;
                    break;
            }

        case SDL_KEYUP:
            switch (Event->key.keysym.sym)
            {
                case SDLK_a:
                    m_bMovingLeft = false;
                    //VelX = 0;
                    //CurrentFrame = 0;
                    break;

                case SDLK_d:
                    m_bMovingRight = false;
                    //VelX = 0;
                    //CurrentFrame = 0;
                    break;

            }

    }
    //std::cout << m_bMovingRight;
    std::cout << "MovingLeft in HandleInput(): " << m_bMovingLeft << "\n";*/
}

bool CPlayer::Collision_Hor(int x, int y, int &TileCoordY, CMap* Map)
{
	int TileXInPixels = x - (x % Tile.GetSize());	//calculate the x position (pixels!) of the tiles we check against
	int CheckEnd = x + PLAYER_WIDTH;		//calculate the end of testing (just to save the x+w calculation each for loop)

	TileCoordY = y / Tile.GetSize();			//calculate the y position (map coordinates!) of the tiles we want to test

	int TileCoordX = TileXInPixels / Tile.GetSize();	//calculate map x coordinate for first tile

	while(TileXInPixels <= CheckEnd)
    {
		if(Map->GetTypeOfTile(TileCoordX, TileCoordY) == 1)
        {
			return true;
        }

		TileCoordX++;
		TileXInPixels += Tile.GetSize();
	}

	return false;
}

bool CPlayer::Collision_Ver(int x, int y, int &TileCoordX, CMap* Map)
{
	int TileYInPixels = y - (y % Tile.GetSize());
	int CheckEnd = y + PLAYER_HEIGHT;

	TileCoordX = x / Tile.GetSize();

	int TileCoordY = TileYInPixels / Tile.GetSize();

	while(TileYInPixels <= CheckEnd)
    {
		if(Map->GetTypeOfTile(TileCoordX, TileCoordY) == 1)
        {
            return true;
        }

		TileCoordY++;
		TileYInPixels += Tile.GetSize();
	}

	return false;
}

void CPlayer::Animate(int MaxFrames)
{
    if (CurrentFrame >= MaxFrames)
    {
        CurrentFrame = 0;
    }
    SpritePlayer.SetSourceRect(0/*PLAYER_WIDTH*/,PLAYER_HEIGHT*CurrentFrame,PLAYER_WIDTH,PLAYER_HEIGHT);

    //std::cout << m_bMovingRight;

}


void CPlayer::Update(CMap* Map)
{

    VelX = 0;
    VelY = 0;
    PosY += 1.0f; //Gravity

    SDL_PumpEvents();

    const Uint8* Keystates = SDL_GetKeyboardState(NULL);

    if (Keystates[SDL_SCANCODE_A])
    {
        m_bMovingLeft = true;
        VelX = -4;
        CurrentFrame++;
    }
    else if (Keystates[SDL_SCANCODE_D])
    {
        m_bMovingRight = true;
        VelX = 4;
        CurrentFrame++;
    }
    else if (Keystates[SDL_SCANCODE_SPACE])
    {
        if (m_bLockJump == true)
        {
            m_bisJumping = true;
            VelY = -VELOCITY_Y;
            CurrentFrame = 1;
        }

    }


    int TilePos = 0;

    std::cout << "MovingLeft in Update(): " << m_bMovingLeft << "\n";
    std::cout << "MovingRight in Update(): " << m_bMovingRight << "\n";

	//x axis first (--)
	if(VelX > 0) //right
    {
		if(Collision_Ver(PosX + VelX + PLAYER_WIDTH, PosY, TilePos, Map) == 1)
        {
			PosX = (TilePos * Tile.GetSize()) - PLAYER_WIDTH;
			std::cout << "collision: Setting player to " << PosX << " ///// " << "TilePos: " << TilePos <<"\n";
        }
		else
        {
            PosX += VelX;
            std::cout << "no collision: moving right...\n";
        }

	}
	else if(VelX < 0) //left
	{
		if(Collision_Ver((PosX + VelX), PosY, TilePos, Map) == 1)
        {
            PosX = (TilePos + 1)* Tile.GetSize();
            std::cout << "collision: Setting player to " << PosX << " ///// " << "TilePos: " << TilePos <<"\n";
        }
		else
        {
            PosX += VelX;
        }

	}

	//then y axis (|)
	if(VelY < 0) //up
    {
		if(Collision_Hor(PosX, (PosY + VelY), TilePos, Map) == 1)
        {
			PosY = (TilePos + 1)* Tile.GetSize();
			VelY = 0;
			std::cout << "collision: Setting player to " << PosY << " ///// " << "TilePos: " << TilePos <<"\n";
		}
		else
        {
			PosY	+= VelY;
			PosY	+= 1;
		}
	}
	else
    {		//moving down / on ground
		//printf("test: down, vely:%d\n", vely);
		if(Collision_Hor(PosX, (PosY + VelY + PLAYER_HEIGHT), TilePos, Map))
		{
			PosY = (TilePos * Tile.GetSize()) - PLAYER_HEIGHT;
			VelY = 1;

			/*if(!keystates[SDLK_RSHIFT])	//player only may jump again if the jump key is released while on ground
				lockjump = false;*/
		}
		else
        {
			PosY += VelY;
			VelY += 1;

			if(VelY >= Tile.GetSize())
            {
				VelY = Tile.GetSize();
            }

			m_bLockJump = true;			//don't allow jumping after falling of an edge
		}
	}
}



void CPlayer::Render(SDL_Renderer* pRenderer)
{
    std::cout << VelX << "/" << VelY << "\n";
    std::cout << PosX << "/" << PosY << "\n";
    SpritePlayer.SetDestinationRect(PosX, PosY, PLAYER_WIDTH, PLAYER_HEIGHT);
    SpritePlayer.Render(pRenderer);
}

void CPlayer::KeepBounds()
{
    if (PosY + PLAYER_HEIGHT >= 480) //bottom
    {
        PosY = 480 - PLAYER_HEIGHT;
    }
    else if (PosX + PLAYER_WIDTH >= 640) //right
    {
        m_bisDead = true;
    }
    else if (PosX <= 0) //left
    {
        PosX = 0;
    }
}


void CPlayer::SetPosX(float XPos)
{
    PosX = XPos;
}


void CPlayer::SetPosY(float YPos)
{
    PosY = YPos;
}


float CPlayer::GetPosX()
{
    return PosX;
}


float CPlayer::GetPosY()
{
    return PosY;
}
