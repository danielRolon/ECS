#include <tools/keyboard/keyboard.h>

#include <windows.h>

bool Keyboard::KeyPress(int key)
{
    return bool(GetAsyncKeyState(key));
}

bool Keyboard::KeyClic(int key)
{
    bool& keyS  = KeysSolted[key];
    bool& keyC  = KeysClic[key];

    if ((bool)GetAsyncKeyState(key))
    {
        if (keyS)
        {
            if (!keyC)
            {
                keyC = true;
            }
            else
            {
                keyC = false;
            }
            keyS = false;
        }
    }
    else
    {
        keyS = true;
    }

    return keyC;
}