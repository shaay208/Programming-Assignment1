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

    static Game* instance;

    // The deck of cards used in the game, containing all the playing cards for this game session
    Deck deck;

    // The first player object representing player one in the game
    Player player1;

    // The second player object representing player two in the game
    Player player2;

    // The discard pile where discarded cards are stored
    DiscardPile discardPile;

    // The index of the current player in the players vector
    int currentPlayerIndex;

    // Flag indicating whether the game has ended
    bool gameOver;

    // The current round number in the game
    int currentRound;

    // The current turn number within the current round
    int currentTurn;

    // Constant for the maximum number of turns in the game
    static const int MAX_ROUNDS = 10;  // Game ends after 10 total turns

    Game();

    // Advances the game to the next turn
    void nextTurn();

    // Handles the chest and key card combination for a player
    void handleChestKeyCombo(Player& player);
    
    // Displays the game title screen
    void displayTitle() const;

public:

    // Singleton access
    static Game& getInstance();

    // Delete copy constructor and assignment
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    // Game setup method to initialize the game state
    void initialize();

     void play();

    // Method to play a single turn for the current player
    void playTurn();

    // Returns true if the game has reached its end condition (MAX_ROUNDS or MAX_TURNS)
    bool isGameOver() const;

    // Draws and returns the top card from the deck as a shared pointer
    std::shared_ptr<Card> drawCard();


    // Method to display the current game state
    void displayGameState() const;


    // Method to display the winner of the game
    void displayWinner() const;

    // Method to add a card to the discard pile
    void addToDiscardPile(std::shared_ptr<Card> card);

    // getting the other player
    Player& getOtherPlayer();

    // Draws and returns the top card from the discard pile
    std::shared_ptr<Card> drawFromDiscardPile();

    // Method to look at the top card of the deck without removing it
    std::shared_ptr<Card> peekTopCard() const;

    Player& getCurrentPlayer();
};
