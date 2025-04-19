#pragma once

// Include necessary headers for managing players, deck, discard pile, and play area
#include <vector>
#include <memory>
#include "../Player/Player.h"
#include "../Deck/Deck.h"
#include "../DiscardPile/DiscardPile.h"
#include "../PlayArea/PlayArea.h"
#include "../Player/Player.h"

// The Game class manages the state, flow, and logic of the game.
class Game {
private:
    // A vector of shared pointers to Player objects representing all players in the game
    std::vector<std::shared_ptr<Player>> players;

    // The deck of cards used in the game, containing all the playing cards for this game session
    Deck deck;

    // The first player object representing player one in the game
    Player player1;
    // The second player object representing player two in the game
    Player player2;


    // The discard pile where discarded cards are stored
    DiscardPile discardPile;

    // The play area where the current cards being played are shown
    PlayArea playArea;

    // The index of the current player in the players vector
    int currentPlayerIndex;

    // Flag indicating whether the game has ended
    bool gameOver;

    // The current round number in the game
    int currentRound;

    // The current turn number within the current round
    int currentTurn;

    // Constant for the maximum number of turns in the game
    static const int MAX_TURNS = 20;  // Game ends after 20 total turns

    // Helper method to handle the situation where a player busts (i.e., exceeds the limit)
    void handleBust();

    // Helper method to bank the current play area (transfer the cards to the appropriate area)
    void bankCurrentPlayArea();

    // Helper method to determine if the game should end
    bool shouldGameEnd() const;

    // Helper method to switch the turn to the next player
    void switchToNextPlayer();

public:
    // Constant for the maximum number of rounds in the game
    static const int MAX_ROUNDS = 3;  // Maximum number of rounds in the game

    // Constructor that initializes the game with a specific number of players
    Game(int numPlayers);

    // Game setup method to initialize the game state
    void initialize();

    // Method to deal cards to players at the beginning of the game
    void dealCards();

    // Method to start the game
    void start();

    // Method to play a single turn for the current player
    void playTurn();

    // Method to move to the next turn
    void nextTurn();

    // Returns true if the game has reached its end condition (MAX_ROUNDS or MAX_TURNS)
    bool isGameOver() const;

    // Draws and returns the top card from the deck as a shared pointer
    std::shared_ptr<Card> drawCard();


    // Method to bank the current player's cards
    void bankCards();

    // Getter for the deck (const version)
    const Deck& getDeck() const { return deck; }

    // Getter for the deck (non-const version for drawing cards)
    Deck& getDeck() { return deck; }

    // Getter for the discard pile (const version)
    const DiscardPile& getDiscardPile() const { return discardPile; }

    // Getter for the discard pile (non-const version)
    DiscardPile& getDiscardPile() { return discardPile; }

    // Getter for the players vector (const version)
    const std::vector<std::shared_ptr<Player>>& getPlayers() const { return players; }

    // Getter for the play area (const version)
    const PlayArea& getPlayArea() const { return playArea; }

    // Getter for the play area (non-const version)
    PlayArea& getPlayArea() { return playArea; }

    // Getter for the current player
    Player& getCurrentPlayer() { return *players[currentPlayerIndex]; }

    // Getter for the current round number
    int getCurrentRound() const { return currentRound; }

    // Getter for the current turn number
    int getCurrentTurn() const { return currentTurn; }

    // Method to check if the game should be over
    void checkGameOver();

    // Method to calculate the final scores of the game
    void calculateFinalScores();

    // Method to display the current game state
    void displayGameState() const;

    // Method to display information about the current round
    void displayRoundInfo() const;

    // Method to display the winner of the game
    void displayWinner() const;

    // Method to add a card to the discard pile
    void addToDiscardPile(std::shared_ptr<Card> card);

    // getting the other player
    Player& getOtherPlayer();
};
