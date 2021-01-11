#pragma once

struct AreaComponent
{
    float x, y, w, h;
    int idEntity = -1;
    bool collide = false;
    bool lastCollide = false;
};