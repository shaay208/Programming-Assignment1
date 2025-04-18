#include "PlayArea.h"
#include <iostream>
#include <algorithm>

// Adds a card to the play area if the provided card pointer is not null
void PlayArea::addCard(const std::shared_ptr<Card>& card) {
    if (card) {
        cards.addCard(card);
    }
}

// Removes a card from the play area if it exists
void PlayArea::removeCard(const std::shared_ptr<Card>& card) {
    cards.removeCard(card);
}

// Clears all cards from the play area
void PlayArea::clear() {
    cards.clear();
}

// Returns a card at the specified index, or nullptr if index is out of bounds
CardPtr CardCollection::getCard(size_t index) const {
    if (index < cards.size()) {
        return cards[index];
    }
    return nullptr;
}

// Finds and returns the first card of the specified suit, or nullptr if not found
CardPtr CardCollection::findOneCardOfSuit(CardType suit) const {
    auto it = std::find_if(cards.begin(), cards.end(),
        [suit](const CardPtr& card) {
            return card->getType() == suit;
        });
    
    return (it != cards.end()) ? *it : nullptr;
}

// Checks if the card collection is empty
bool CardCollection::isEmpty() const {
    return cards.empty();
}

// Returns the number of cards in the collection
size_t CardCollection::size() const {
    return cards.size();
}

// Prints all cards in the collection, showing "(empty)" if there are no cards
void CardCollection::print() const {
    if (cards.empty()) {
        std::cout << "        (empty)\n";
        return;
    }

    for (const auto& card : cards) {
        std::cout << "        " << card->str() << "\n";
    }
}