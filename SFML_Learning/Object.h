#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <cmath>

#include <SFML/Graphics.hpp>

class Object {
public:
	class Rectangle {
	public:
		// Public Functions
		Rectangle(float width, float height) : width(width), height(height) {};

		void _initFillColor(sf::Color fillColor);
		void _initSpawnPosition(float spawnPositionX, float spawnPositionY);
		void _initSpeed(float speed);

		int getPerimeter();
		int getArea();

		// Public Variables
		float width;
		float height;

		sf::Color color;

		float spawnPositionX;
		float spawnPositionY;

		float speed;
	};
	class Circle {
	public:
		// Public Functions
		Circle(float radius) : radius(radius) {};

		void _initFillColor(sf::Color fillColor);
		void _initSpawnPosition(float spawnPositionX, float spawnPositionY);
		void _initSpeed(float speed);

		int getPerimeter();
		int getArea();

		// Public Variables
		float radius;

		sf::Color color;

		float spawnPositionX;
		float spawnPositionY;

		float speed;
	};
};

#endif