#pragma once
#include "../Card/Card.h"
#include "../CardCollection/CardCollection.h"
#include <random>  // For shuffling functionality

// Deck class inherits from CardCollection and represents a deck of cards
// Deck class that inherits from CardCollection to manage a collection of playing cards
class Deck : public CardCollection {
private:
    // Vector to store the cards in the deck using smart pointers
    std::vector<std::shared_ptr<Card>> cards;

public:
    // Constructor: Creates a new empty deck
    Deck();

    // Sets up the deck with a standard set of cards
    void initialize();

    // Takes and removes the top card from the deck (two different versions)
    CardPtr drawCard();
    std::shared_ptr<Card> drawCard();

    // Looks at the top card without removing it
    std::shared_ptr<Card> peekTop() const;

    // Randomizes the order of cards in the deck
    void shuffle();

    // Checks if the deck has no cards
    bool isEmpty() const { return cards.empty(); }
    
    // Returns the number of cards currently in the deck
    size_t size() const { return cards.size(); }
    
    // Displays all cards in the deck (useful for testing)
    void print() const;
};
