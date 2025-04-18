#include "CardCollection.h"
#include <iostream>
#include <algorithm>
#include <random>

// Adds a single card to the collection

void CardCollection::addCard(const CardPtr& card) {
    if (card) {
        cards.push_back(card);
    }
}

// Adds all cards from another CardCollection to this collection
void CardCollection::addCards(const CardCollection& other) {
    const auto& otherCards = other.getCards();
    cards.insert(cards.end(), otherCards.begin(), otherCards.end());
}

// Removes a specific card from the collection if it exists
void CardCollection::removeCard(const CardPtr& card) {
    // Locate the card in the collection
    auto it = std::find(cards.begin(), cards.end(), card);

    // If found, remove it
    if (it != cards.end()) {
        cards.erase(it);
    }
}

// Returns true if the collection has no cards
bool CardCollection::isEmpty() const {
    return cards.empty();
}

// Returns the number of cards currently in the collection
size_t CardCollection::size() const {
    return cards.size();
}

// Clears all cards from the collection
void CardCollection::clear() {
    cards.clear();
}

// Retrieves a card at the specified index or nullptr if out of bounds
CardPtr CardCollection::getCard(size_t index) const {
    if (index < cards.size()) {
        return cards[index];
    }
    return nullptr;
}

// Finds and returns the first card that matches the specified suit/type
// Returns nullptr if no matching card is found
CardPtr CardCollection::findOneCardOfSuit(CardType suit) const {
    auto it = std::find_if(cards.begin(), cards.end(),
        [suit](const CardPtr& card) {
            return card->getType() == suit;
        });
    
    return (it != cards.end()) ? *it : nullptr;
}

// Prints the string representations of all cards in the collection
void CardCollection::print() const {
    // Print "Empty" if no cards are present
    if (cards.empty()) {
        std::cout << "        (empty)\n";
        return;
    }

    // Print each card in the collection
     for (const auto& card : cards) {
        std::cout << "        " << card->str() << "\n";
    }
}
