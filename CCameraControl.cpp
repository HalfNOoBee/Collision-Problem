#include "CCameraControl.h"

CCamera CCamera::CameraControl;

CCamera::CCamera()
{
    X = 0;
    Y = 0;

    TargetMode = TARGET_MODE_NORMAL;

    TargetX = NULL;
    TargetY = NULL;
}


void CCamera::OnMove(int MoveX, int MoveY)
{
    X += MoveX;
    Y += MoveY;
}


int CCamera::GetX()
{
    if(TargetX != NULL)
    {
        if(TargetMode == TARGET_MODE_CENTER)
        {
            return *TargetX - (Game->GetScreenWidth() / 2);
        }
        return *TargetX;
    }
    return X;
}


int CCamera::GetY()
{
    if(TargetY != NULL)
    {
        if(TargetMode == TARGET_MODE_CENTER)
        {
            return *TargetY - (Game->GetScreenHeight() / 2);
        }
        return *TargetY;
    }
    return Y;
}


void CCamera::SetPos(int X, int Y)
{
    this->X = X;
    this->Y = Y;
}


void CCamera::SetTarget(int* X, int* Y)
{
    TargetX = X;
    TargetY = Y;
}
