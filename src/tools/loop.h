#pragma once

#include <inttypes.h>

class MainLoop
{
public:
    static void SetFPS(uint8_t FPS);
    static void Update();
    static bool PassedSecond();
    static void CallEveryFrame(void (*pFunc)(float DeltaTime));
    static void SetDebugFPS(bool value);
    static void SetDebugDelta(bool value);
private:
    inline       static float FPSObjetive    = 60;
    inline const static float SecondInMillis = 1000;
    inline       static float DeltaFrame     = (float)SecondInMillis / (float)FPSObjetive;

    inline static float       FPSCount       = 0;
    inline static float       Delta          = 0;

    inline static float       CurrentTime    = 0;
    inline static float       LastTime       = 0;
    inline static float       LastSecond     = 0;

    inline static bool        bPassedSecond   = false;
    inline static bool        bCallEveryFrame = false;
    inline static bool        DebugFPS        = false;
    inline static bool        DebugDelta      = false;
};