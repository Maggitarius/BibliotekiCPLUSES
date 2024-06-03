// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <iostream>
#include <string>
#include <windows.h>

__declspec(dllexport) bool FindCharacters(const char* str, const char* chars) {
    std::string inputStr(str);
    std::string characters(chars);

    for (char c : characters) {
        if (inputStr.find(c) == std::string::npos) {
            return false;
        }
    }

    return true;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

