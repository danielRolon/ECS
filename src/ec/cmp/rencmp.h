#pragma once

struct Rgb
{
    float R, G, B;
};

struct RendererComponent
{
    Rgb rgb{255, 0, 0};
    float x, y, w, h;
    int idEntity = -1;
};