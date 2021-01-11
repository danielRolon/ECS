#include <tools/maths.h>

float degToRad(float deg)
{
    return deg * 180 / PI;
}

float radToDeg(float rad)
{
    return rad / PI * 180;
}

float normalizeAngle(float angle)
{
    if (angle < 0)
        angle += PI*2;
    if (angle > PI*2)
        angle -= PI*2;

    return angle;
}

float distancePoint(float x1, float y1, float x2, float y2)
{
    float ca = x2-x1;
    float co = y2-y1;

    return abs(sqrt(ca*ca + co*co));
}