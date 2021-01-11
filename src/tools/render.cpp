#include <tools/render.h>

void Renderer2D::CreateWindow(const char* title, int width, int height)
{
    Width = width;
    Height = height;
    
    // Iniciamos la ventana
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(width, height, 0, &Window, &Renderer);
    SDL_SetWindowTitle(Window, title);
    
    // Limpiamos la pantalla
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
    SDL_RenderClear(Renderer);
    
    SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
    SDL_RenderPresent(Renderer);
}

void Renderer2D::DestroyWindow()
{
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}

void Renderer2D::Clear()
{
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
    SDL_RenderClear(Renderer);
}

void Renderer2D::Refresh()
{
    SDL_RenderPresent(Renderer);
}

int Renderer2D::PollEvents()
{
    return SDL_PollEvent(&Event);
}

const SDL_Event& Renderer2D::GetEvent()
{
    return Event;
}

void Renderer2D::SetColor(Uint8 r, Uint8 g, Uint8 b)
{
    R = r;
    G = g;
    B = b;
    SDL_SetRenderDrawColor(Renderer, R, G, B, A);
}

void Renderer2D::SetAlpha(Uint8 alpha)
{
    A = alpha;
    SDL_SetRenderDrawColor(Renderer, R, G, B, A);
}

void Renderer2D::DrawPixel(int x, int y)
{
    SDL_RenderDrawPoint(Renderer, x, y);
}


void Renderer2D::DrawLine(int x1, int y1, int x2, int y2)
{
    SDL_RenderDrawLine(Renderer, x1, y1, x2, y2);
}

void Renderer2D::DrawRect(int x, int y, int w, int h)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    SDL_RenderDrawRect(Renderer, &rect);
}

void Renderer2D::FillRect(int x, int y, int w, int h)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    SDL_RenderFillRect(Renderer, &rect);
}
