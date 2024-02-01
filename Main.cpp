#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

#include "Game.h"

int main() {

	Game game;
	
	game.generateWorld();

	while (game.isOpen()) {

		game.update();
	}
		
	return 0;

}