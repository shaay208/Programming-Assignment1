#pragma once
#include "../Card/Card.h"
#include "../CardCollection/CardCollection.h"

// The Bank class manages a collection of cards and calculates a score based on them
class Bank {
private:
    // Stores the cards in the bank
    CardCollection cards;

    // The score calculated from the highest value card of each type
    int score;

    // Recalculates the score based on cards in bank
    void calculateScore();

public:
    // Constructor
    Bank();

    // Adds a single card to the bank
    void addCard(const CardPtr& card);

    // Adds multiple cards to the bank
    void addCards(const CardCollection& newCards);

    // Clears all cards and resets the score
    void clear();

    // Checks if the bank has no cards
    bool isEmpty() const;

    // Returns a const reference to the card collection in the bank
    const CardCollection& getBank() const;

    // Returns the current score of the bank
    int getScore() const;

    // Returns a modifiable reference to the cards
    CardCollection& getCards();

    // Returns a const reference to the cards
    const CardCollection& getCards() const;

    // Prints the contents and score of the bank
    void print() const;
};
