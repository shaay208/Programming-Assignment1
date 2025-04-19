#pragma once
#include "../Card/Card.h"
#include "../Bank/Bank.h"
#include <string>
#include <vector>
#include <memory>
#include "../CardCollection/CardCollection.h"
#include "../PlayArea/PlayArea.h"
#include "../DiscardPile/DiscardPile.h"

class Game;

class Player {
private:
    // The name of the player, used to identify the player throughout the game
    std::string name;

    // The play area where cards are placed during gameplay
    PlayArea playArea;

    // The player's bank where cards are stored for scoring
    Bank bank;

    // Flag indicating if the player has busted (exceeded a score limit)
    bool busted;  

    // Array of preset player names
    static const std::string names[10];

    // Update the bust status based on the current play area (whether the player has busted)
    void checkBust();

public:
    // Constructor: Initializes the player with a name
    explicit Player(const std::string& playerName = "");

    // Play area management
    // Plays a card from the player's hand to the play area
    bool playCard(std::shared_ptr<Card> card, Game& game);

    // Checks if the player has busted
    bool hasBusted() const;

    // Gets the play area (cards played by the player)
    const PlayArea& getPlayArea() const;

    // Bank operations
    // Moves all cards from the play area to the player's bank
    void movePlayAreaToBank();

    // Gets a const reference to the player's bank, allowing read-only access to bank contents
    const Bank& getBank() const;

    // Gets a non-const reference to the player's bank, allowing modification of bank contents
    Bank& getBank();

    // Gets the name of the player
    const std::string& getName() const;

    // Display functions
    void displayBank() const;  // Shows bank

    // Game logic functions
    // Checks if card would cause bust
    bool wouldBust(const std::shared_ptr<Card>& card) const; 
    
    PlayArea& getPlayArea();  // Gets modifiable play area

    // Handles busting by moving cards to discard pile
    void bustPlayArea(DiscardPile& discardPile);

    // Gets the player's score based on cards in the bank
    int getScore() const;

    // Displays the cards in the play area  
    void displayPlayArea() const;
};