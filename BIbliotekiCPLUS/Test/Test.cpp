#include <iostream>
#include <windows.h>
#include <string>
#include "Windows.h"

typedef bool (*FindCharacters)(const char*, const char*);

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    FindCharacters shuhunchik;

    HINSTANCE Bibki = LoadLibrary(L"DynamicLib.dll");

    if (!Bibki) {
        cerr << "Не удалось загрузить динамическую библиотеку." << endl;
        return 1;
    }

    if (Bibki != NULL) {
        shuhunchik = (FindCharacters)GetProcAddress(Bibki, "FindCharacters");

        string inputString, charactersToFind;
        cout << "Введите строку: ";
        getline(cin, inputString);
        cout << "Введите символы для поиска: ";
        getline(cin, charactersToFind);

        if (shuhunchik != NULL) {
            bool result = shuhunchik(inputString.c_str(), charactersToFind.c_str());

            if (result) {
                std::cout << "Все символы найдены в строке!" << std::endl;
            }
            else {
                std::cout << "Не все символы найдены в строке." << std::endl;
            }

            FreeLibrary(Bibki);
        }
        else {
            cout << "О-па-па";
        }
    }
    return 0;
}