#pragma once

#include "../CardCollection/CardCollection.h"

// Represents a pile where discarded cards are stored
class DiscardPile {
private:
    CardCollection cards;  // Collection of discarded cards

public:
    // Default constructor and destructor
    DiscardPile() = default;
    ~DiscardPile() = default;

    // Adds a single card to the discard pile
   void addCard(const std::shared_ptr<Card>& card);

    // Adds a vector of cards to the discard pile at once
    void addCards(const std::vector<std::shared_ptr<Card>>& cardsToAdd);

    // Removes and returns the top card from the discard pile
    std::shared_ptr<Card> drawCard();
    
    // Checks whether the discard pile is empty
    bool isEmpty() const;

    // Prints all cards in the discard pile
    void print() const;

    // Returns a constant reference to the card collection
    const CardCollection& getCards() const;

    void clear(); 
};
