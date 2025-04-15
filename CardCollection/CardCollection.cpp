#include "CardCollection.h"
#include <iostream>
#include <algorithm>
#include <random>

// Adds a single card to the collection
void CardCollection::addCard(std::shared_ptr<Card> card) {
    cards.push_back(card);
}

// Adds all cards from another CardCollection to this collection
void CardCollection::addCards(const CardCollection& other) {
    cards.insert(cards.end(), other.cards.begin(), other.cards.end());
}

// Removes a specific card from the collection if it exists
void CardCollection::removeCard(const std::shared_ptr<Card>& card) {
    // Locate the card
    auto it = std::find(cards.begin(), cards.end(), card);
    if (it != cards.end()) {
        // Remove it from the collection
        cards.erase(it);
    }
}

// Returns true if there are no cards in the collection
bool CardCollection::isEmpty() const {
    return cards.empty();
}

// Returns the number of cards currently in the collection
size_t CardCollection::size() const {
    return cards.size();
}

// Removes all cards from the collection
void CardCollection::clear() {
    cards.clear();
}

// Provides modifiable access to the vector of cards
std::vector<std::shared_ptr<Card>>& CardCollection::getCards() {
    return cards;
}

// Provides read-only access to the vector of cards
const std::vector<std::shared_ptr<Card>>& CardCollection::getCards() const {
    return cards;
}

// Finds and returns the first card that matches the given suit/type
// Returns nullptr if no matching card is found
std::shared_ptr<Card> CardCollection::findOneCardOfSuit(CardType suit) const {
    for (const auto& card : cards) {
        if (card->getType() == suit) {
            return card;
        }
    }
    return nullptr;
}

// Prints a string representation of all cards in the collection
void CardCollection::print() const {
    for (const auto& card : cards) {
        std::cout << card->str() << " ";
    }
    std::cout << std::endl;
}
