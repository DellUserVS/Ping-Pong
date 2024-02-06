#include "main.h"

int main(int argc, char** argv) {
	// Seed the random number
	std::random_device rd;
	std::mt19937 generator(rd());

	// Define distribution for random number between range [1, 2]
	std::uniform_int_distribution<int> distribution(1, 2);
	int randNum = distribution(generator);

	// Print window size
	Console::Text<std::string> windowSizeText("window-size: w{799}, h{707}");
	windowSizeText.printText();

	// Render Window
	Window d_window(
		799,			// d_window.width
		707,			// d_window.height
		"SFML Window"	// d_window.title
	);
	sf::RenderWindow window(
		sf::VideoMode(
			d_window.width,
			d_window.height
		),
		d_window.title,
		sf::Style::Default
	);

	// Initialize board 1
	Object::Rectangle d_board1(
		20,				// d_board.width
		100				// d_board.height
	);
	d_board1._initSpawnPosition(
		12,								// d_board.spawnPositionX
		707 / 2 - d_board1.height		// d_board.spawnPositionY
	);
	d_board1._initFillColor(sf::Color::White);		// d_board.color
	d_board1._initSpeed(300.0f);

	sf::RectangleShape board1(sf::Vector2f(d_board1.width, d_board1.height));
	board1.setFillColor(d_board1.color);
	board1.setPosition(d_board1.spawnPositionX, d_board1.spawnPositionY);

	// Initialize board 2
	Object::Rectangle d_board2(
		20,				// d_board.width
		100				// d_board.height
	);
	d_board2._initSpawnPosition(
		768,								// d_board.spawnPositionX
		270									// d_board.spawnPositionY
	);
	d_board2._initFillColor(sf::Color::White);		// d_board.color
	d_board2._initSpeed(300.0f);

	sf::RectangleShape board2(sf::Vector2f(d_board2.width, d_board2.height));
	board2.setFillColor(d_board2.color);
	board2.setPosition(d_board2.spawnPositionX, d_board2.spawnPositionY);

	// Render ball
	Object::Circle d_ball(25.0f);				// d_ball.radius
	d_ball._initFillColor(sf::Color::White);	// d_ball.color
	d_ball._initSpawnPosition(
		350,				// d_ball.spawnPositionX
		270					// d_ball.spawnPositionY
	);
	d_ball._initSpeed(240.0f);			// d_ball.speed

	sf::CircleShape ball(d_ball.radius);
	ball.setFillColor(d_ball.color);
	ball.setPosition(d_ball.spawnPositionX, d_ball.spawnPositionY);

	bool isSpacebarPressed = false;

	sf::Clock clock;

	while (window.isOpen()) {
		sf::Event sfEvent;

		while (window.pollEvent(sfEvent)) {
			if (sfEvent.type == sf::Event::Closed) {
				window.close();
				Console::Text<std::string> closeInfoText("Window closed!");
			}
			else if (sfEvent.type == sf::Event::KeyPressed) {
				if (sfEvent.key.code == sf::Keyboard::Space) {
					isSpacebarPressed = true;
				}
			}
			else if (sfEvent.type == sf::Event::KeyReleased) {
				if (sfEvent.key.code == sf::Keyboard::Space) {
					isSpacebarPressed = false;
				}
			}
		}

		float deltaTime = clock.restart().asSeconds();			// Get delta time for uniforming FPS

		// Keyboard Events
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && board1.getPosition().y >= 2) {board1.move(0, -d_board1.speed * deltaTime);}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && board1.getPosition().y + d_board1.height <= (window.getSize().y - 5)) {board1.move(0, d_board1.speed * deltaTime);}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && board2.getPosition().y >= 2) {board2.move(0, -d_board2.speed * deltaTime);}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && board2.getPosition().y + d_board2.height <= (window.getSize().y - 5)) {board2.move(0, d_board2.speed * deltaTime);}

		// Play with the ball
		
		if (isSpacebarPressed) {
			std::cout << std::endl << "Spacebar was clicked!" << std::endl;
		}

		window.clear();

		// Draw objects
		window.draw(board1);
		window.draw(board2);
		window.draw(ball);                 

		window.display();
	}

	return 0;
}