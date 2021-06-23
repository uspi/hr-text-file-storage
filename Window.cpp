#include "CPs.h"
#include "Ñonsole.h"
#include "Window.h"

using namespace std;

void Window::print(
    string str,
    bool onNextLine,
    CPs consoleCodePage = CPs::ru)
{
    setCP(consoleCodePage);

    if (onNextLine)
    {
        cout << "\n" << str;
        return;
    }

    cout << str;

    // to default
    setCP(CPs::def);
}