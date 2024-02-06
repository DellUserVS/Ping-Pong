#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <string>

class Console {
public:
	template <typename _consoleVarType> class Text {
	private:
		_consoleVarType text;
	public:
		Text(_consoleVarType userText) : text(userText) {};
		void printText() {
			std::cout << text;
		};
	};
};

#endif