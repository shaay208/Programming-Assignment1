#pragma once

// Include the CardCollection class to manage a group of cards
#include <memory>
#include <vector>
#include "../CardCollection/CardCollection.h"

// Represents a player's bank where scored cards are stored
class Bank {
private:
    // Collection of cards stored in the bank
    CardCollection cards;

    // Total score calculated from the cards
    int score;

public:
    // Constructor initializes the bank and score
    Bank();

    // Adds a single card to the bank
    void addCard(const std::shared_ptr<Card>& card);

    // Adds multiple cards to the bank from another collection
    void addCards(const CardCollection& newCards);

    // Returns the current score of the bank
    int getScore() const;

    // Calculates the total score based on the current cards
    void calculateScore();

    // Clears all cards and resets the score
    void clear();

    // Returns true if the bank has no cards
    bool isEmpty() const;

    // Prints all cards in the bank
    void print() const;

    // Provides modifiable access to the bank's card collection
    CardCollection& getCards();

    // Provides read-only access to the bank's card collection
    const CardCollection& getCards() const;
};
