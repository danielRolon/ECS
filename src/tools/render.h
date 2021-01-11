#pragma once

#include <SDL2/SDL.h>

class Renderer2D
{
public:
    // Window
    static void CreateWindow(const char* title, int width, int height);
    static void DestroyWindow();

    // Events
    static int PollEvents();
    static const SDL_Event& GetEvent();
    
    // Primitives
    static void Clear();
    static void Refresh();
    static void SetColor(Uint8 r, Uint8 g, Uint8 b);
    static void SetAlpha(Uint8 alpha);
    static void DrawPixel(int x, int y);
    static void DrawLine(int x1, int y1, int x2, int y2);
    static void DrawRect(int x, int y, int w, int h);
    static void FillRect(int x, int y, int w, int h);

    // Getters
    inline static int GetWidth()  { return Width; }
    inline static int GetHeight() { return Height; }
private:
    inline static SDL_Event Event;
    inline static SDL_Renderer *Renderer = nullptr;
    inline static SDL_Window   *Window   = nullptr;

    inline static int Width = 0;
    inline static int Height = 0;

    inline static Uint8 R {255}, G {0}, B {0}, A {255};
};