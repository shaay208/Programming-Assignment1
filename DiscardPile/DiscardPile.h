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
    void addCard(std::shared_ptr<Card> card);

    // Adds multiple cards to the discard pile
    void addCards(const CardCollection& cards);

    // Draws a specified number of cards from the discard pile
    CardCollection drawCards(int count);

    // Finds one card of a specific suit from the discard pile (returns first match)
    std::shared_ptr<Card> findOneCardOfSuit(CardType suit) const;

    // Removes a specific card from the discard pile
    bool removeCard(const std::shared_ptr<Card>& card);

    // Checks whether the discard pile is empty
    bool isEmpty() const;

    // Prints all cards in the discard pile
    void print() const;

    // Returns a modifiable reference to the card collection
    CardCollection& getCards();

    // Returns a constant reference to the card collection
    const CardCollection& getCards() const;
};
