#include "CPlayer.h"
#include "CGame.h"
#include "CCamera.h"



CPlayer::CPlayer()
{
    m_tPlayer = NULL;
    m_tFireball = NULL;

    PosX = 100.0f;
    PosY = 150.0f;

    MOVING_SPEED = 5.0f;
    JUMPING_HEIGHT = 50.0f;

    MaxSpeedX = 5.0f;
    MaxSpeedY = 5.0f;

    CurrentFrame = 0;
    CurrentColumn = 0;

    m_bMovingLeft = false;
    m_bMovingRight = false;
    m_bisAlive = true;

    m_bisJumping = false;
    m_bLockJump = false;
    m_bisDead = false;


    Jump = NULL;
    Blockhit = NULL;

    m_Score = 1;

}


void CPlayer::Init(SDL_Renderer* pRenderer)
{
    m_tPlayer = SpritePlayer.Load(pRenderer,"data/imgs/player/Mario.png", 255, 0, 255);

    Jump = Mix_LoadWAV("data/sounds/jump.wav");
    if (Jump == NULL)
    {
        std::cout << "Failed to load the jump.wav for the Player! Mix_Error: " << Mix_GetError() << "\n";
    }

    Blockhit = Mix_LoadWAV ("data/sounds/blockhit.wav");
    if (Blockhit == NULL)
    {
        std::cout << "Failed to load the blockhit.wav for the Player! Mix_Error: " << Mix_GetError() << "\n";
    }

    ScoreField = new CTTF(20,20);
    ScoreField->Load(pRenderer,"data/fonts/SuperMario256.ttf",16);

    CurrentScoreField = new CTTF(20,40);
    CurrentScoreField->Load(pRenderer,"data/fonts/Super Mario Bros.ttf",16);
}

void CPlayer::HandleInput(SDL_Event Event)
{
    switch (Event.type)
    {
        case SDL_KEYDOWN:
            switch (Event.key.keysym.sym)
            {
                case SDLK_a:
                    m_bMovingLeft = true;
                    VelX = -4;
                    break;

                case SDLK_d:
                    m_bMovingRight = true;
                    VelX = 4;
                    break;

                case SDLK_SPACE:
                    m_bisJumping = true;
                    m_bLockJump = true;
                    VelY = - 40;
            }

        case SDL_KEYUP:
            switch (Event.key.keysym.sym)
            {
                case SDLK_a:
                    m_bMovingLeft = false;
                    break;

                case SDLK_w:
                    m_bMovingRight = false;
                    break;
            }
    }
}


bool CPlayer::Collision_Hor(int x, int y, int &TileCoordY, CMap* Map)
{
	int TileXInPixels = x - (x % Tile.GetSize()) ; //calculate the x position (pixels!) of the tiles we check against
	std::cout << "From " << TileXInPixels << " to ";
	int CheckEnd = x + PLAYER_WIDTH;		//calculate the end of testing (just to save the x+w calculation each for loop)
    std::cout << CheckEnd << "\n";

	TileCoordY = y / Tile.GetSize();			//calculate the y position (map coordinates!) of the tiles we want to test

	int TileCoordX = TileXInPixels / Tile.GetSize(); //calculate map x coordinate for first tile
	std::cout << "TileCoordX: " << TileCoordX << "\n";

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
	int TileYInPixels = y - (y % Tile.GetSize()) - 1;
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
    SpritePlayer.SetSourceRect(PLAYER_WIDTH*CurrentColumn,PLAYER_HEIGHT*CurrentFrame,PLAYER_WIDTH,PLAYER_HEIGHT);

}


void CPlayer::Update(CMap* Map)
{
    OldTime = CurrentTime;
    CurrentTime = SDL_GetTicks();
    dtTime = (CurrentTime - OldTime)/ 1000.0f;
    //std::cout << dtTime;

    VelY = 1;

    SDL_PumpEvents();

    const Uint8* Keystates = SDL_GetKeyboardState(NULL);

    if (Keystates[SDL_SCANCODE_A])
    {
        m_bMovingLeft = true;
        CurrentColumn = 1;
        CurrentFrame++;
        std::cout << VelX << "\n";
    }

    else if (Keystates[SDL_SCANCODE_D])
    {
        m_bMovingRight = true;
        CurrentColumn = 0;
        CurrentFrame++;
        std::cout << VelX << "\n";

        if (VelX == 0)
        {
            CurrentFrame = 0;
        }
    }
    else if (Keystates[SDL_SCANCODE_SPACE])
    {
        if (m_bLockJump == false)
        {
            m_bisJumping = true;
            VelY = -30;
            CurrentFrame = 1;
            m_bLockJump = true;
            Mix_PlayChannel(-1,Jump,0);

        }
        else
        {
            m_bLockJump = false;
        }

    }
    else if (!Keystates[SDL_SCANCODE_D] || (!Keystates[SDL_SCANCODE_A] && m_bisJumping == false))
    {
        VelX = 0;
        CurrentFrame = 4;
    }

    int TilePos = 0;

	//x axis first (--)
	if(VelX > 0) //right
    {
		if(Collision_Ver(PosX + VelX + PLAYER_WIDTH /*+ CCamera::Camera.GetPosX()*/, PosY, TilePos, Map) == true)
        {
			PosX = (TilePos * Tile.GetSize()) - PLAYER_WIDTH - 1;
			Mix_PlayChannel(-1,Blockhit,0);

        }
		else
        {
            PosX += VelX;
            //CCamera::Camera.SetPosX(4);
        }

	}
	else if(VelX < 0) //left
	{
		if(Collision_Ver((PosX + VelX/* + CCamera::Camera.GetPosX()*/), PosY, TilePos, Map) == true)
        {
            PosX = (TilePos + 1)* Tile.GetSize();
            Mix_PlayChannel(-1,Blockhit,0);

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
			Mix_PlayChannel(-1,Blockhit,0);
		}
		else
        {
			PosY	+= VelY;
			PosY	+= 1;
		}
	}
	else
    {
		if(Collision_Hor(PosX, (PosY + VelY + PLAYER_HEIGHT), TilePos, Map))
		{
		    VelY = 0;
			PosY = (TilePos * Tile.GetSize()) - PLAYER_HEIGHT;

		}
		else
        {
			PosY += VelY;
			VelY += 1;

			if(VelY >= Tile.GetSize())
            {
				VelY = Tile.GetSize();
            }

			m_bLockJump = true;
		}

        PosY += VelY;
	}

    m_Score++;
	std::stringstream ss;
	ss << std::setw(6) << std::setfill('0') << m_Score;
	sScore = ss.str().c_str();
}




void CPlayer::Render(SDL_Renderer* pRenderer)
{
    SpritePlayer.SetDestinationRect(PosX - CCamera::Camera.GetPosX(), PosY, PLAYER_WIDTH, PLAYER_HEIGHT);
    SpritePlayer.Render(pRenderer);
    ScoreField->Render(pRenderer,"SCORE",255,255,255);
    CurrentScoreField->Render(pRenderer,sScore,255,255,255);
}

void CPlayer::CleanUp()
{
    Mix_FreeChunk(Blockhit);
    Mix_FreeChunk(Jump);
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

float CPlayer::GetWidth()
{
    return (int)PLAYER_WIDTH;
}

float CPlayer::GetHeight()
{
    return (int)PLAYER_HEIGHT;
}
