#include "Console.h"


// Getting the console handle
HANDLE Console::handle = GetStdHandle(STD_OUTPUT_HANDLE);

// Hides the console cursor
void Console::hideC() {
	CONSOLE_CURSOR_INFO info = {};
	GetConsoleCursorInfo(Console::handle, &info);
	info.bVisible = FALSE;
	SetConsoleCursorInfo(Console::handle, &info);
}

// Moves the console cursor
void Console::moveC(int x, int y) {
	COORD pos = { short(x), short(y) };
	SetConsoleCursorPosition(Console::handle, pos);
}

// Clears the console
void Console::clear() {
	system("cls");
}

// Returns the console size
Size Console::size() {
	CONSOLE_SCREEN_BUFFER_INFO csbi = {};
	GetConsoleScreenBufferInfo(Console::handle, &csbi);
	return Size(csbi.srWindow.Right - csbi.srWindow.Left + 1, csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
}

// Returns the last pressed key
char Console::input() {
	char key = 0;
	while (_kbhit()) {
		key = _getch();
	}
	return key;
}

// Updates the console title
void Console::title(const std::string& data) {
	SetConsoleTitleA(data.c_str());
}
