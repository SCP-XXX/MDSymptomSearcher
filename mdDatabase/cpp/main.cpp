#include "menu.h"

int main()
{
	Menu menu;

	std::string sInput;

	while (true)
	{
		// Display a menu that takes an input from the user
		menu.displayTitle();
		menu.displayOptions();

		std::cin >> sInput;
		system("CLS");
		//menu.processInput(sInput);
	}

	return 0;
}