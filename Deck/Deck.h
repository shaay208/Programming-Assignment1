#pragma once

// Include the Card and CardCollection headers for using CardPtr and base functionality
#include "../Card/Card.h"
#include "../CardCollection/CardCollection.h"
#include <random>  // For shuffling functionality

// Deck class inherits from CardCollection and represents a deck of cards
class Deck : public CardCollection {
public:
    // Constructor: Initializes a new deck
    Deck();

    // Draw the top card from the deck and remove it
    CardPtr drawCard();

    // View the top card without removing it from the deck
    CardPtr peek() const;

    // Shuffle the cards in the deck randomly
    void shuffle();

    // Reset the deck to its original state (full, ordered set of cards)
    void reset();
};
