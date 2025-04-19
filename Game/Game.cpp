#include "Game.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <random>

// Static instance pointer for the singleton pattern
Game* Game::instance = nullptr;

// Singleton pattern to ensure only one instance of Game exists
Game& Game::getInstance() {
    if (!instance) {
        instance = new Game();
    }
    return *instance;
}

// Constructor that initializes the game with the given number of players
Game::Game() :
    currentRound(1),
    currentTurn(1),
    currentPlayerIndex(0),
    gameOver(false) {
}

// Initializes the game by resetting the deck and dealing cards
void Game::initialize() {
    displayTitle();
    std::cout << "\nStarting Dead Man's Draw++!\n";

    // Initialize game components
    deck.initialize();
    deck.shuffle();
    discardPile.clear();

    // Reset game state
    currentRound = 1;
    currentTurn = 1;
    currentPlayerIndex = 0;
    gameOver = false;
}

// Starts the main game loop until the game is over
void Game::play() {
    initialize();
    while (!isGameOver()) {
        playTurn();
    }
    displayWinner();
}

// Handles a single player's turn
void Game::playTurn() {
    std::cout << "\n--- Round " << currentRound << ", Turn " << currentTurn << " ---\n";
    Player& currentPlayer = getCurrentPlayer();
    std::cout << currentPlayer.getName() << "'s turn.\n";

    std::cout << currentPlayer.getName() << "'s Bank:\n";
    currentPlayer.displayBank();

    bool continueTurn = true;
    while (continueTurn && !isGameOver()) {
        auto drawnCard = drawCard();
        if (!drawnCard) {
            std::cout << "\nDeck is empty! Game will end after this turn.\n";
            gameOver = true;
            break;
        }

        std::cout << currentPlayer.getName() << " draws a " << drawnCard->str() << "\n";
        drawnCard->displayAbilityDescription();

        if (currentPlayer.playCard(drawnCard, *this)) {
            // Player busted
            break;
        }

        if (drawnCard->getType() != CardType::KRAKEN) {
            std::string input;
            do {
                std::cout << "\nDraw again? (y/n): ";
                std::getline(std::cin, input);
            } while (input != "y" && input != "n");

            if (input == "n") {
                handleChestKeyCombo(currentPlayer);
                currentPlayer.movePlayAreaToBank();
                break;
            }
        }
    }

    nextTurn();
}

// Advances the game to the next player's turn, and handles round progression
void Game::nextTurn() {
    currentPlayerIndex = (currentPlayerIndex + 1) % 2;
    if (currentPlayerIndex == 0) {
        currentTurn++;
        if (currentTurn > 2) {
            currentRound++;
            currentTurn = 1;
        }
    }
}

Player& Game::getCurrentPlayer() {
    return currentPlayerIndex == 0 ? player1 : player2;
}

// Returns a reference to the other player in a two-player game
// If current player is player1 (index 0), returns player2, and vice versa
Player& Game::getOtherPlayer() {
    return currentPlayerIndex == 0 ? player2 : player1;
}

// Player attempts to draw a card and play it
std::shared_ptr<Card> Game::drawCard() {
    return deck.drawCard();
}

// Adds the given card to the discard pile if it's not null
void Game::addToDiscardPile(std::shared_ptr<Card> card) {
    if (card) {
        discardPile.addCard(card);
    }
}

// Returns the top card from the deck without removing it
std::shared_ptr<Card> Game::peekTopCard() const {
    return deck.peekTop();
}

// Draws a card from the discard pile and returns it
std::shared_ptr<Card> Game::drawFromDiscardPile() {
    return discardPile.drawCard();
}

// Handles the special combination of Chest and Key cards
// If both are present in the player's play area, draws cards from the discard pile
void Game::handleChestKeyCombo(Player& player) {
    bool hasChest = false;
    bool hasKey = false;

    for (const auto& card : player.getPlayArea().getCards()) {
        if (card->getType() == CardType::CHEST) hasChest = true;
        if (card->getType() == CardType::KEY) hasKey = true;
    }

    if (hasChest && hasKey) {
        int cardsToBank = player.getPlayArea().size();
        std::cout << "\nChest and Key combination! Drawing " << cardsToBank
            << " cards from discard pile.\n";
        for (int i = 0; i < cardsToBank; i++) {
            if (auto card = discardPile.drawCard()) {
                player.getBank().addCard(card);
            }
            else {
                std::cout << "No more cards in discard pile.\n";
                break;
            }
        }
    }
}

// Displays the title screen of the game
void Game::displayTitle() const {
    std::cout << R"(
______                  _   ___  ___              _
|  _  \                | |  |  \/  |             ( )
| | | | ___   __ _   __| |  | .  . |  __ _  _ __ |/ ___
| | | |/ _ \ / _` | / _` |  | |\/| | / _` || '_ \  / __|
| |/ /|  __/| (_| || (_| |  | |  | || (_| || | | | \__ \
______ \___| \__,_| \__,_|  \_|  |_/ \__,_||_| |_| |___/
|  _  \                         _      _
| | | | _ __  __ _ __      __ _| |_  _| |_
| | | || '__|/ _` |\ \ /\ / /|_   _||_   _|
| |/ / | |  | (_| | \ V  V /   |_|    |_|
|___/  |_|   \__,_|  \_/\_/
)" << '\n';
}

// Displays the winner of the game based on scores
void Game::displayWinner() const {
    std::cout << "\n=== Game Over ===\n";
    std::cout << "Final Scores:\n";
    std::cout << player1.getName() << ": " << player1.getScore() << "\n";
    std::cout << player2.getName() << ": " << player2.getScore() << "\n\n";

    if (player1.getScore() > player2.getScore()) {
        std::cout << player1.getName() << " wins!\n";
    }
    else if (player2.getScore() > player1.getScore()) {
        std::cout << player2.getName() << " wins!\n";
    }
    else {
        std::cout << "It's a tie!\n";
    }
}

// Checks if the game is over based on rounds, empty deck, or gameOver flag
bool Game::isGameOver() const {
    return gameOver || deck.isEmpty() || currentRound > MAX_ROUNDS;
}

// Displays the current game state, including player information and deck status
void Game::displayGameState() const {
    std::cout << "\nCurrent Game State:\n";
    std::cout << "==================\n";
    std::cout << "Round: " << currentRound << "/" << MAX_ROUNDS << "\n";
    std::cout << "Turn: " << currentTurn << "\n\n";

    // Display player 1's state
    std::cout << "Player 1 (" << player1.getName() << "):\n";
    player1.displayPlayArea();
    player1.displayBank();
    std::cout << "\n";

    // Display player 2's state
    std::cout << "Player 2 (" << player2.getName() << "):\n";
    player2.displayPlayArea();
    player2.displayBank();
    std::cout << "\n";

    // Display deck status
    std::cout << "Cards remaining in deck: " << deck.size() << "\n";

    // Display discard pile status if not empty
    if (!discardPile.isEmpty()) {
        std::cout << "Top card in discard pile: ";
        if (auto topCard = discardPile.getCards().getCard(discardPile.getCards().size() - 1)) {
            std::cout << topCard->str() << "\n";
        }
    }
}