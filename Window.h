#pragma once
#ifndef WINDOW_H
#define WINDOW_H
#endif
#include "CPs.h"
#include "Ñonsole.h"
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

class Window : Console {
public:
    void print(
        string str,
        bool onNextLine,
        CPs consoleCodePage);
};