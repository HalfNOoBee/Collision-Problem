#include "CGame.h"



CGame::CGame()
{
    bRunning = true;

    SCREEN_WIDTH = 640;
    SCREEN_HEIGHT = 480;

    MainWindow = NULL;
    MainRenderer = NULL;
    MainWindowSurface = NULL;
    MainIcon = NULL;

}


bool CGame::OnInit()
{

    if (SDL_Init (SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL could not be initialized! SDL_Error: " << SDL_GetError () << "\n";
    }
    else
    {
        MainWindow = SDL_CreateWindow ("The Running Man",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_RESIZABLE);
        if (MainWindow == NULL)
        {
            std::cout << "SDL could not create the window! SDL_Error: " << SDL_GetError () << "\n";
        }
        else
        {
            MainRenderer = SDL_CreateRenderer(MainWindow, -1, SDL_RENDERER_ACCELERATED);
            if (MainRenderer == NULL)
            {
                std::cout << "SDL could not create the renderer! SDL_Error: " << SDL_GetError() << "\n";
            }
            else
            {
                MainWindowSurface = SDL_GetWindowSurface(MainWindow);
                if (MainWindowSurface == NULL)
                {
                    std::cout << "SDL could not get the window surface! SDL_Error: " << SDL_GetError() << "\n";
                }
                else
                {
                    MainIcon = IMG_Load("data/icons/Mario Block.png");
                    if (MainIcon == NULL)
                    {
                        std::cout << "Failed to load the main icon! IMG_Error: " << IMG_GetError() << "\n";
                    }
                    else
                    {
                        SDL_SetWindowIcon(MainWindow,MainIcon);
                    }

                }

            }
        }
    }

    if (TTF_Init() < 0)
    {
        std::cout << "TTF could not be initialized! TTF_Error: " << TTF_GetError() << "\n";
    }

    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
    {
        std::cout << "Mixer could not be initialized! Mix_Error: " << Mix_GetError() << "\n";
    }

    Soundtrack = Mix_LoadMUS("data/sounds/Super Mario  - Official Soundtrack.mp3");
    if (Soundtrack == NULL)
    {
        std::cout << "Failed to open the Soundtrack! Mix_Error: " << Mix_GetError << "\n";
    }
    else
    {
        Mix_PlayMusic(Soundtrack,999);
    }

    Background.Init(MainRenderer);

    Map.Load(MainRenderer, "data/maps/01/1-1.txt", 1600, 480);

    Player.Init(MainRenderer);

    return true;
}


void CGame::OnEvent(SDL_Event* Event)
{
    Player.HandleInput(Event);

    switch (Event->type)
    {
        case SDL_QUIT:
            bRunning = false;
            break;

    }
}


void CGame::OnUpdate()
{
    Background.Update(MainRenderer);
    Player.Animate(5);
    Player.Update(&Map);
}

void CGame::OnRender()
{
    SDL_SetRenderDrawColor(MainRenderer,0,0,0,255);
    SDL_RenderClear(MainRenderer);

    Background.Render(MainRenderer);
    Map.Render(MainRenderer);
    Player.Render(MainRenderer);


    SDL_RenderPresent(MainRenderer);

}

void CGame::OnCleanup()
{
    Background.CleanUp();
    Mix_FreeMusic(Soundtrack);
    SDL_FreeSurface(MainIcon);
    SDL_FreeSurface(MainWindowSurface);
    SDL_DestroyWindow(MainWindow);
    SDL_DestroyRenderer(MainRenderer);

    TTF_Quit();
    SDL_Quit();
}

int CGame::GetScreenHeight()
{
    return SCREEN_HEIGHT;
}

int CGame::GetScreenWidth()
{
    return SCREEN_WIDTH;
}

SDL_Renderer* CGame::GetRenderer()
{
    return MainRenderer;
}

SDL_Event* CGame::GetEvent()
{
    return MainEvent;
}
