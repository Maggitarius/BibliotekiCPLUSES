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