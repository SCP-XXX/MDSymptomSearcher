#include <cwchar>
#include <windows.h>

#include "menu.h"

int main()
{
	Menu menu;

	std::string sInput;

	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 800, 600, TRUE);

	/*CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 20;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);*/

	while (true)
	{
		// Display a menu that takes an input from the user
		menu.displayTitle();
		menu.displayOptions();

		std::cin >> sInput;
		system("CLS");
		menu.processInput(sInput);
	}

	return 0;
}