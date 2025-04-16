#include "CardCollection.h"
#include <iostream>
#include <algorithm>
#include <random>

// Adds a single card to the collection
void CardCollection::addCard(const CardPtr& card) {
    cards.push_back(card);
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

// Provides modifiable access to the card vector
std::vector<std::shared_ptr<Card>>& CardCollection::getCards() {
    return cards;
}

// Provides read-only access to the card vector
const std::vector<std::shared_ptr<Card>>& CardCollection::getCards() const {
    return cards;
}

// Finds and returns the first card that matches the specified suit/type
// Returns nullptr if no matching card is found
CardPtr CardCollection::findOneCardOfSuit(CardType suit) const {
    for (const auto& card : cards) {
        if (card && card->getType() == suit) {
            return card;
        }
    }
    return nullptr;
}

// Prints the string representations of all cards in the collection
void CardCollection::print() const {
    // Print "Empty" if no cards are present
    if (isEmpty()) {
        std::cout << "Empty" << std::endl;
        return;
    }

    // Print each card in the collection
    for (const auto& card : cards) {
        std::cout << card->str() << " ";
    }
    std::cout << std::endl;
}
