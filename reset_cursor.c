#include <windows.h>
#include <winuser.h>
#include <stdio.h>
#include <stdlib.h>
#include <shellapi.h>

int APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        int nCmdShow
        )
{

    LPWSTR *szArgList;
    int argCount;
    int x = 400;
    int y = 400;

    LPWSTR pt = GetCommandLineW();

    szArgList = CommandLineToArgvW(GetCommandLineW(), &argCount);

    if (argCount == 3) {
        x = _wtoi(szArgList[argCount - 2]);
        y = _wtoi(szArgList[argCount - 1]);
    }

    SetCursorPos(x, y);
    return 0;

}
