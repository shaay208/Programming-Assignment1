#pragma once
#include "../CardCollection/CardCollection.h"
#include <memory>

// Class representing the play area where cards are placed during the game
class PlayArea {
private:
    CardCollection cards;  // Collection to store all cards in the play area

public:

    // Card management methods
    
    // Adds a new card to the play area using shared pointer for memory management
    void addCard(const std::shared_ptr<Card>& card);

    // Removes a specific card from the play area
    void removeCard(const std::shared_ptr<Card>& card);

    // Removes all cards from the play area, resetting it to empty state
    void clear();

    // Query methods for play area state
    // Checks if play area has no cards
    bool isEmpty() const;

    // Returns the total number of cards in play area
    size_t size() const;

     // Gets constant reference to card collection
    const CardCollection& getCards() const;
    
    // Gets modifiable reference to card collection
    std::vector<CardPtr>& getCards();

    // Output method
    void print() const;  // Displays the current state of play area
};