#include "Game.h"
#include "MapGenerator.h"

sf::Event event;

void Game::_render() {
	//game_window.draw(tiles)
	for (auto& tile : tiles)
		game_window.draw(tile);
	game_window.display();
	game_window.clear();
}

Game::Game() {
	//poi userà file
	game_window.create(sf::VideoMode::getFullscreenModes()[0], "Test", sf::Style::Fullscreen);
	

	game_time = 0;
	open = true;
}

void Game::update() {

	game_time++;

	if (game_window.pollEvent(window_event) || !game_window.isOpen()) {
		switch (window_event.type) {
			case sf::Event::Closed:

				closeGame();
				
				break;
			case sf::Event::KeyPressed:
				handleKeyPress(window_event.key.code);
				break;
			default:
				break;
		}
	}

	_render();
}


void Game::handleKeyPress(sf::Keyboard::Key keyPressed){
	switch (keyPressed){
		//TODO: scrivere per ogni tasto funzione movimento

		case sf::Keyboard::W:

			break;
		case sf::Keyboard::A:

			break;

		case sf::Keyboard::S:

			break;

		case sf::Keyboard::D:

			break;



	}
}

void Game::closeGame() {

	//dovrà salvare
	open = false;
	game_window.close();
}

bool Game::isOpen() {
	return open;
}

void Game::generateWorld() {

	std::vector<double> generated = MapGenerator::generate();
	tiles.resize(generated.size());

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {

			int k = i * 101 + j;
			tiles[k] = sf::RectangleShape(sf::Vector2f(10, 10));
			tiles[k].setPosition(i * 10, j * 10);
			tiles[k].setFillColor(

				generated[k] < 0.25 ? sf::Color(10, 10, 100) : //LAGO || PROFONDO
				generated[k] < 0.4 ? sf::Color(50, 50, 200) :  //LAGO 
				generated[k] < 0.6 ? sf::Color(10, 200, 10) :  //PIANURA
				generated[k] < 0.7 ? sf::Color(0, 150, 0) : sf::Color(40, 40, 40) //FORESTA - MONTAGNA
			);
		}
	}
}