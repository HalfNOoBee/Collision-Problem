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

void CCamera::SetPosX(float MovementSpeed)
{
    m_PosX += MovementSpeed;
    Viewport.x = m_PosX;

    if (m_PosX <= 0)
    {
        m_PosX = 0;
    }
}

float CCamera::GetPosX()
{
    return m_PosX;
}

float CCamera::GetPosY()
{
    return m_PosY;
}
