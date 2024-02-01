#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

class Game
{
private:
	sf::RenderWindow game_window;
	unsigned long long game_time; //in frames
	sf::Event window_event;
	bool open;
	std::vector<sf::RectangleShape> tiles;
	//vector<Tiles> tiles


private:
	void _render();

public:
	void handleKeyPress(sf::Keyboard::Key keyPressed);
	Game();
	void generateWorld();
	void update();
	void closeGame();
	bool isOpen();
};

