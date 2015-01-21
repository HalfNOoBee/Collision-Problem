#include "CCamera.h"



CCamera CCamera::Camera;


CCamera::CCamera()
{
    m_PosX = 0;
    m_PosY = 0;
    m_Width = 640;
    m_Height = 480;

    Viewport.x = m_PosX;
    Viewport.y = m_PosY;
    Viewport.w = m_Width;
    Viewport.h = m_Height;
}

void CCamera::CenterOnPlayer(CPlayer Player, CMap Map)
{
    m_PosX = Player.GetPosX() + (Player.GetWidth()/2) - 320;

    if (m_PosX <= 0)
    {
        m_PosX = 0;
        std::cout << "Camera cant go any further to the left...\n";
    }
    else if (m_PosX + m_Width >= Map.GetWidth())
    {
        m_PosX = Map.GetWidth() - m_Width;
        std::cout << "Camera cant go any further to the right...\n";
    }

    Viewport.x = m_PosX;

    std::cout << "The camera is supposed to be at " << Player.GetPosX() + (Player.GetWidth()/2) - 320 << "\n";
    std::cout << "Because the player is at " << Player.GetPosX() << "\n";

}

float CCamera::GetPosX()
{
    return m_PosX;
}

float CCamera::GetPosY()
{
    return m_PosY;
}
