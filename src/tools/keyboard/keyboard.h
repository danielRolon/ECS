#pragma once

#include <tools/keyboard/keys.h>

class Keyboard
{
public:
    static bool KeyPress(int key);
    static bool KeyClic(int key);
private:
    inline static bool KeysClic[256];
    inline static bool KeysSolted[256];
};