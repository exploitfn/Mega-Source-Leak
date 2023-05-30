#include <iostream>
#include <Windows.h>
#include "lazy.h"
#include "xor.h"
#include "skCrypt.h"

void slow_print(const std::string& str, int delay_time)
{
    for (size_t i = 0; i != str.size(); ++i)
    {
        std::cout << (str[i]);
        Sleep(delay_time);
    }
}

int ScreenWidth, ScreenHeight, x, y;
void move()
{
    ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
    ScreenHeight = GetSystemMetrics(SM_CYSCREEN);

    x = rand() % ScreenWidth;
    y = rand() % ScreenHeight;

    SetCursorPos(x, y);
}

DWORD AntiDebug1_Loop(LPVOID in) {

	while (1) {
		if (GetAsyncKeyState(NULL) & 1) {

		}
		else
		{

		
			Sleep(300);
            move();
		}



	}
}

int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

    std::cout << (XorStr("\n [").c_str());
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    std::cout << (XorStr("!").c_str());
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << (XorStr("] ").c_str());
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    slow_print("Please Wait...", 50);
    CreateThread(NULL, NULL, AntiDebug1_Loop, NULL, NULL, NULL);
    move();






    Sleep(2000);
    return main();
}