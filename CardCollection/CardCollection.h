#pragma once

#include "../Card/Card.h"
#include <vector>
#include <memory>
#include <algorithm>

using CardPtr = std::shared_ptr<Card>;

// Manages a collection of cards using shared pointers
class CardCollection {
private:
    // Stores the collection of cards
    std::vector<CardPtr> cards;

public:
    // Default constructor
    CardCollection() = default;

    // Default destructor
    ~CardCollection() = default;

    // Constructs a CardCollection using a range of iterators
    template<typename Iterator>
    CardCollection(Iterator begin, Iterator end) {
        cards.assign(begin, end);
    }

    // Adds a single card to the collection
    void addCard(const CardPtr& card);

    // Adds all cards from another CardCollection to this one
    void addCards(const CardCollection& other);

    // Removes a specific card from the collection
    void removeCard(const CardPtr& card);

    // Clears all cards from the collection
    void clear();

    // Checks whether the collection is empty
    bool isEmpty() const;

    // Returns the number of cards in the collection
    size_t size() const;

    // Card retrieval
    CardPtr getCard(size_t index) const;

    // Returns a const reference to the card pointers
    const std::vector<CardPtr>& getCards() const { return cards; }

    // Finds and returns the first card matching the given suit/type
    // Returns nullptr if none found
    CardPtr findOneCardOfSuit(CardType suit) const;

    // Prints a string representation of all cards in the collection
    void print() const;

    // Iterator support
    using iterator = std::vector<CardPtr>::iterator;
    using const_iterator = std::vector<CardPtr>::const_iterator;

    iterator begin() { return cards.begin(); }
    iterator end() { return cards.end(); }
    const_iterator begin() const { return cards.begin(); }
    const_iterator end() const { return cards.end(); }
    const_iterator cbegin() const { return cards.cbegin(); }
    const_iterator cend() const { return cards.cend(); }
};
