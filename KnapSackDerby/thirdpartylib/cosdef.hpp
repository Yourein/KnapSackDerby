#pragma once

//INCLUDE DEPENDINGS
#include <iostream>
#include <string>
#include <Windows.h>

const unsigned int CON_BLACK = 0;
const unsigned int CON_BLUE = 1;
const unsigned int CON_GREEN = 2;
const unsigned int CON_AQUA = 3;
const unsigned int CON_RED = 4;
const unsigned int CON_PURPLE = 5;
const unsigned int CON_YELLOW = 6;
const unsigned int CON_WHITE = 7;
const unsigned int CON_GRAY = 8;
const unsigned int CON_LBLUE = 9;
const unsigned int CON_LGREEN = 10;
const unsigned int CON_LAQUA = 11;
const unsigned int CON_LRED = 12;
const unsigned int CON_LPURPLE = 13;
const unsigned int CON_LYELLOW = 14;
const unsigned int CON_LWHITE = 15;

const unsigned int CON_DEFAULT = 0x000F;

namespace Yconsole {
	void ConsoleWrite(HANDLE chandle, std::string message, unsigned int foreground = 0x000F, unsigned int background = 0x0000) {
		SetConsoleTextAttribute(chandle, (background | foreground));
		std::cout << message << std::endl;
		SetConsoleTextAttribute(chandle, CON_DEFAULT);
	}

	void CLEAR() {
		system("CLS");
	}
}