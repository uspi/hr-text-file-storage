#pragma once
#ifndef INPUT_H
#define INPUT_H
#endif
#include <string>
#include <iostream>
#include <windows.h>

#include "CPs.h"
#include "Ñonsole.h"

using namespace std;

class Input : Console {
public:
	string getInputText(int bufferSize, CPs consoleCodePage);
};
