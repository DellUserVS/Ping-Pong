#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>

class Window {
public:
	// Public Functions
	Window(int width, int height, std::string title);

	// Public Variables
	int width;
	int height;
	std::string title;
};

#endif

