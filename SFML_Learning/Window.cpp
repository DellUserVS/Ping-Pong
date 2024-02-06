#include "Window.h"

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

Window::Window(int width, int height, std::string title) {
	this->width = width;
	this->height = height;
	this->title = title;
}
