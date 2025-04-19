#pragma once
#include "../Card/Card.h"
#include "../Bank/Bank.h"
#include <string>
#include <vector>
#include <memory>
#include "../CardCollection/CardCollection.h"

class Game;

class Player {
private:
    // The name of the player
    std::string name;

    // The collection of cards currently played by the player
    CardCollection playArea;

    // The player's bank where cards are stored for scoring
    Bank bank;

    // The collection of cards currently in the player's hand
    CardCollection hand;

    // Flag indicating if the player has busted (exceeded a score limit)
    bool busted;

public:
    // Constructor: Initializes the player with a name
    explicit Player(const std::string& name);

    // Play area management
    // Plays a card from the player's hand to the play area
    bool playCard(std::shared_ptr<Card> card, Game& game);

    // Clears all cards from the play area
    void clearPlayArea();

    // Checks if the player has busted
    bool hasBusted() const { return busted; }

    // Gets the play area (cards played by the player)
    const CardCollection& getPlayArea() const { return playArea; }

    // Bank operations
    // Moves all cards from the play area to the player's bank
    void movePlayAreaToBank();

    // Removes a specific card from the player's bank
    void removeFromBank(const CardPtr& card);

    // Gets the total score from the bank's cards
    int getScore() const { return bank.getScore(); }

    // Gets a constant reference to the player's bank
    const Bank& getBankConst() const { return bank; }

    // Gets a reference to the player's bank (modifiable)
    Bank& getBank() { return bank; }

    // Hand management
    // Adds a card to the player's hand
    void addCardToHand(const CardPtr& card);

    // Removes a specific card from the player's hand
    void removeFromHand(const CardPtr& card);

    // Gets the current hand of the player
    const CardCollection& getHand() const { return hand; }

    // Getters
    // Gets the name of the player
    const std::string& getName() const { return name; }

    // Utility
    // Prints a summary of the player's status
    void print() const;

    // Card management
    // Adds a card to the player's hand (shared_ptr version)
    void addToHand(std::shared_ptr<Card> card);

    // Adds a card to the player's bank (shared_ptr version)
    void addToBank(std::shared_ptr<Card> card);

    // Clears all cards from the player's hand
    void clearHand();

    // Clears all cards from the player's bank
    void clearBank();

    // Game actions
    // Calculates the player's score based on cards in the bank
    void calculateScore();

    // Display
    // Displays the cards currently in the player's hand
    void displayHand() const;

    // Displays the cards currently in the player's bank
    void displayBank() const;

private:
    // Check if adding a card would cause a bust (score exceeding limit or game rule violation)
    bool wouldBust(const CardPtr& card) const;

    // Update the bust status based on the current play area (whether the player has busted)
    void checkBust();
};
