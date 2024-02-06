#include "Object.h"

void Object::Rectangle::_initFillColor(sf::Color fillColor) {
	// Asign color
	this->color = fillColor;
}

void Object::Rectangle::_initSpawnPosition(float spawnPositionX, float spawnPositionY) {
	// Assign spawnPositionX and spawnPositionY
	this->spawnPositionX = spawnPositionX;
	this->spawnPositionY = spawnPositionY;
}

void Object::Rectangle::_initSpeed(float speed)
{
	// Assign speed
	this->speed = speed;
}

int Object::Rectangle::getPerimeter()
{
	// Calculate perimeter
	float perimeter = 2*(width+height);

	// Return Perimeter
	return perimeter;
}

int Object::Rectangle::getArea()
{
	// Calculate Area
	float area = width * height;

	// Return Area
	return area;
}

void Object::Circle::_initFillColor(sf::Color fillColor) {
	// Assign color
	this->color = fillColor;
}
void Object::Circle::_initSpawnPosition(float spawnPositionX, float spawnPositionY) {
	// Assign spawnPositionX and spawnPositionY
	this->spawnPositionX = spawnPositionX;
	this->spawnPositionY = spawnPositionY;
}

void Object::Circle::_initSpeed(float speed) {
	// Assign speed
	this->speed = speed;
}

double pi = 3.141592653589793;

int Object::Circle::getPerimeter() {
	// Calculate perimeter
	double perimeter = 2 * pi * this->radius;

	return perimeter;
}

int Object::Circle::getArea()
{
	// Calculate area
	float radiusSqaured = std::pow(this->radius, 2);
	double area = pi * radiusSqaured;

	return 0;
}

