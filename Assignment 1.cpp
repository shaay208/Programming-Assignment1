#include "Assignment 1.h"
#include "Game/Game.h"
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
int main() {
	try {
		// Seed random number generator with current time
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		
		// Get singleton instance of the Game class
		// Game::getInstance() returns a reference to the single Game object
		Game& game = Game::getInstance();
		
		// Start the main game loop
		game.play();
		
		// Return success code if game ends normally
		return 0;
	}
	// Handle any standard exceptions
	catch (const std::exception& e) {
		// Print error message to standard error stream
		std::cerr << "Fatal error: " << e.what() << std::endl;
		return 1;  // Return error code 1 for standard exceptions
	}
	// Catch any other unexpected exceptions
	catch (...) {
		std::cerr << "Unknown error occurred" << std::endl;
		return 2;  // Return error code 2 for unknown exceptions
	}
}