#pragma once

struct PhysicsComponent
{
    float x, y, w, h, vx = 0, vy = 0;
    int idEntity = -1;
};