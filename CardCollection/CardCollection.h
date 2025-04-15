#pragma once

#include <vector>
#include <memory>
#include "../Card/Card.h"

// Class to manage a collection of cards using shared pointers
class CardCollection {
private:
    // Stores the collection of cards
    std::vector<std::shared_ptr<Card>> cards;

public:
    // Default constructor
    CardCollection() = default;

    // Default destructor
    ~CardCollection() = default;

    // Adds a single card to the collection
    void addCard(std::shared_ptr<Card> card);

    // Adds all cards from another CardCollection to this collection
    void addCards(const CardCollection& other);

    // Removes a specific card from the collection
    void removeCard(const std::shared_ptr<Card>& card);

    // Checks if the collection is empty
    bool isEmpty() const;

    // Returns the number of cards in the collection
    size_t size() const;

    // Clears all cards from the collection
    void clear();

    // Returns a reference to the vector of cards (modifiable)
    std::vector<std::shared_ptr<Card>>& getCards();

    // Returns a const reference to the vector of cards (read-only)
    const std::vector<std::shared_ptr<Card>>& getCards() const;

    // Finds and returns a card of the specified suit/type, if any exists
    std::shared_ptr<Card> findOneCardOfSuit(CardType suit) const;

    // Prints information about all cards in the collection
    void print() const;
};
