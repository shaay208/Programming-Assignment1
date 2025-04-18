#pragma once

#include <vector>
#include <memory>
#include "../Card/Card.h"
#include "../CardCollection/CardCollection.h"

class PlayArea {
private:
    static const int NUM_PILES = 4;  // Number of piles in the play area
    std::vector<CardCollection> playPiles;  // Each pile holds a collection of cards
    CardCollection cards;

public:
    // Constructor
    PlayArea();

    // Card management
    // Adds a card to the play area, given a shared pointer to the Card object
    void addCard(const std::shared_ptr<Card>& card);

    // Removes a card from the play area
    void removeCard(const std::shared_ptr<Card>& card);

    // Clears all cards from the play area
    void clear();



    // Adds a card to the first suitable pile (empty or matching suit)
    void addCard(std::shared_ptr<Card> card);

    // Checks if adding this card would duplicate its suit in the play area
    bool wouldCauseBust(std::shared_ptr<Card> card) const;

    // Retrieves all cards from all piles as a single list
    std::vector<std::shared_ptr<Card>> getAllCards();

    // Returns a const reference to all cards (rebuilds on each call)
    const std::vector<std::shared_ptr<Card>>& getCards() const;

    // Checks if any pile already contains a card of the specified suit
    bool hasSuit(CardType suit) const;

    // Pile management

    // Checks whether a card can legally be played on the given pile
    bool canPlayOnPile(int pileIndex, std::shared_ptr<Card> card) const;

    // Adds a card directly to a specific pile (index-validated)
    void addToPile(int pileIndex, std::shared_ptr<Card> card);

    // Gets a modifiable reference to a specific pile
    CardCollection& getPile(int pileIndex);

    // Gets a const reference to a specific pile
    const CardCollection& getPile(int pileIndex) const;

    // Returns true if all piles are occupied
    bool isFull() const;

    // Game state

    // Returns true if all piles are empty
    bool isEmpty() const;

    // Clears all piles in the play area
    void clear();

    // Display

    // Prints each pile and its contents to the console
    void display() const;
};
