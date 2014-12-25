#include "CInput.h"



CInput::CInput()
{

}

void CInput::HandleAllInput()
{
    while (SDL_PollEvent(Game->GetEvent()))
    {
        HandleWindow();
    }
}

void CInput::HandleWindow()
{
    switch (Game->GetEvent()->type)
    {
        case SDL_QUIT:
            Game->bRunning = false;
            break;
    }

}

