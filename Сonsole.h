#pragma once
#include "CPs.h"
#ifndef CONSOLE_H
#define CONSOLE_H
#endif
//#include <windows.h>

using namespace std;

class Console {
protected:
    int consoleCP;

public:
    Console();

    int getCP();

    void setCP(CPs code);

private:
    void setUnsafeCP(int value);
};