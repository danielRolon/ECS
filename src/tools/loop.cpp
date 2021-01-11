#include <tools/loop.h>

#include <ctime>
#include <iostream>

void MainLoop::SetFPS(uint8_t FPS)
{
    FPSObjetive = FPS;
    DeltaFrame  = (float)SecondInMillis / (float)FPSObjetive;
}


void MainLoop::Update()
{
    bPassedSecond = false;
    bCallEveryFrame = false;

    CurrentTime = clock();
    Delta = CurrentTime - LastTime;
    float delta2 = CurrentTime - LastSecond;

    // Passed Frame
    if (Delta > DeltaFrame)
    {
        bCallEveryFrame = true;
        LastTime = CurrentTime;
        FPSCount++;
    }

    // Passed Second
    if (delta2 > (float)SecondInMillis)
    {
        bPassedSecond = true;
        LastSecond = CurrentTime;

        if (DebugFPS)   std::cout << "FPS: " << FPSCount << "\n\n";
        if (DebugDelta) std::cout << "Delta: " << Delta / DeltaFrame << "\n\n\n";
        
        FPSCount = 0;
    }
}

bool MainLoop::PassedSecond()
{
    return bPassedSecond;
}

void MainLoop::CallEveryFrame(void (*pFunc)(float DeltaTime))
{
    if (bCallEveryFrame)
    {
        pFunc(Delta / DeltaFrame);
    }
}

void MainLoop::SetDebugFPS(bool value)
{
    DebugFPS = value;
}

void MainLoop::SetDebugDelta(bool value)
{
    DebugDelta = value;
}
