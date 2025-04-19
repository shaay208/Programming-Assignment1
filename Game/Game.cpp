#include "Game.h"
#include <iostream>
#include <string>
#include <algorithm>

// Constructor that initializes the game with the given number of players
Game::Game(int numPlayers)
    : currentPlayerIndex(0), gameOver(false), currentRound(1), currentTurn(1) {
    // Create players with names "Player 1", "Player 2", etc.
    for (int i = 0; i < numPlayers; ++i) {
        players.push_back(std::make_shared<Player>("Player " + std::to_string(i + 1)));
    }
}

// Initializes the game by resetting the deck and dealing cards
void Game::initialize() {
    deck.reset();
    dealCards();
}

// Deals 5 cards to each player at the beginning of the game
void Game::dealCards() {
    for (int i = 0; i < 5; ++i) {
        for (auto& player : players) {
            if (auto card = deck.drawCard()) {
                player->addCardToHand(card);
            }
        }
    }
}

// Starts the main game loop until the game is over
void Game::start() {
    while (!isGameOver()) {
        playTurn();
    }
    calculateFinalScores();
    displayWinner();
}

// Handles a single player's turn
void Game::playTurn() {
    auto& currentPlayer = getCurrentPlayer();
    std::cout << currentPlayer.getName() << "'s turn.\n";

    // Display the current player's banked cards
    std::cout << currentPlayer.getName() << "'s Bank:\n";
    currentPlayer.displayBank();

    bool continueTurn = true;

    while (continueTurn && !isGameOver()) {
        // Player draws a card; if drawCard() returns false, player busts
        if (!drawCard()) {
            handleBust();
            break;
        }

        // Display the current play area after drawing a card
        std::cout << "\n" << currentPlayer.getName() << "'s Play Area:\n";
        playArea.display();

        // Ask if the player wants to draw again or bank their cards
        std::string input;
        std::cout << "\nDraw again? (y/n): ";
        std::getline(std::cin, input);

        // If the player chooses not to draw again, bank the cards
        if (input != "y" && input != "Y") {
            bankCards();
            continueTurn = false;
        }
    }

    // Move to the next turn after the current player finishes
    nextTurn();
}

// Player attempts to draw a card and play it
bool Game::drawCard() {
    auto& currentPlayer = getCurrentPlayer();
    if (auto card = deck.drawCard()) {
        // Returns false if the playCard() caused a bust
        return !currentPlayer.playCard(card);
    }
    return false;
}

// Moves all cards from the player's play area to their bank
void Game::bankCards() {
    auto& currentPlayer = getCurrentPlayer();
    currentPlayer.movePlayAreaToBank();
}

// Called when the player busts; clears the play area
void Game::handleBust() {
    auto& currentPlayer = getCurrentPlayer();
    currentPlayer.clearPlayArea();
    std::cout << currentPlayer.getName() << " busted and lost all cards in play area!\n";
}

// Advances the game to the next player's turn, and handles round progression
void Game::nextTurn() {
    currentTurn++;
    if (currentTurn > players.size()) {
        currentTurn = 1;
        currentRound++;
    }
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
}

// Checks if the game is over based on rounds, empty deck, or gameOver flag
bool Game::isGameOver() const {
    return gameOver || currentRound > MAX_ROUNDS || deck.isEmpty();
}

// Calculates the final score for each player
void Game::calculateFinalScores() {
    for (auto& player : players) {
        player->calculateScore();
    }
}

// Displays current round and turn number
void Game::displayRoundInfo() const {
    std::cout << "Round " << currentRound << ", Turn " << currentTurn << "\n";
}

// Finds and displays the winner and their score, followed by all players' scores
void Game::displayWinner() const {
    auto winner = std::max_element(players.begin(), players.end(),
        [](const auto& a, const auto& b) {
            return a->getScore() < b->getScore();
        });

    std::cout << "\nGame Over!\n";
    std::cout << "Winner: " << (*winner)->getName() << " with " << (*winner)->getScore() << " points\n";

    for (const auto& player : players) {
        std::cout << player->getName() << ": " << player->getScore() << " points\n";
    }
}

// Getter for the players vector
const std::vector<std::shared_ptr<Player>>& Game::getPlayers() const { return players; }

// Getter for the deck (const)
const Deck& Game::getDeck() const { return deck; }

// Getter for the discard pile (non-const)
DiscardPile& Game::getDiscardPile() { return discardPile; }

// Getter for the discard pile (const)
const DiscardPile& Game::getDiscardPile() const { return discardPile; }

// Getter for the play area (non-const)
PlayArea& Game::getPlayArea() { return playArea; }

// Getter for the play area (const)
const PlayArea& Game::getPlayArea() const { return playArea; }

// Getter for the current player
Player& Game::getCurrentPlayer() { return *players[currentPlayerIndex]; }

// Getter for the current round
int Game::getCurrentRound() const { return currentRound; }

// Getter for the current turn
int Game::getCurrentTurn() const { return currentTurn; }


// Adds the given card to the discard pile if the card pointer is valid
void Game::addToDiscardPile(std::shared_ptr<Card> card) {
    if (card) {  // Check if the card pointer is not null
        discardPile.addCard(card);  // Add the card to the discard pile
    }
}

// Returns a reference to the other player in a two-player game
// If current player is player1 (index 0), returns player2, and vice versa
Player& Game::getOtherPlayer() {
    return currentPlayerIndex == 0 ? player2 : player1;
}

