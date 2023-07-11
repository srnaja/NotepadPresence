#include <Windows.h>
#include <iostream>
#include "discord.h"
#include "notepad_discord.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    Discord d;
    d.Start();
    HWND window;

    STARTUPINFOA ii;
    PROCESS_INFORMATION i;

    ZeroMemory(&ii, sizeof(ii));
    ii.cb = sizeof(ii);

    if (CreateProcessA(0, (LPSTR)"notepad++.exe", 0,0, FALSE, 0,0,0, &ii, &i)) {
        WaitForSingleObject(&i, INFINITE);
        DWORD c;
        GetExitCodeProcess(i.hProcess, &c);
        while (c == STILL_ACTIVE) {
            GetExitCodeProcess(i.hProcess, &c);
            d.Update();
            Sleep(1000);
        }
    }

    CloseHandle(i.hProcess);
    CloseHandle(i.hThread);



    return 0;
}
