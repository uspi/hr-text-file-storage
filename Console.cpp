#include <windows.h>
#include <Ñonsole.h>
#include "CPs.h"

using namespace std;

Console::Console() {
    consoleCP = getCP();
}

int Console::getCP() {
    return GetConsoleCP();
}

void Console::setCP(CPs code) {
    SetConsoleCP((int)code);
}

void Console::setUnsafeCP(int value) {
    SetConsoleCP(value);
}