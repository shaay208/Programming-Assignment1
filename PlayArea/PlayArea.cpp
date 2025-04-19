#include "PlayArea.h"
#include <iostream>

// Adds a card to the play area if the card pointer is valid
void PlayArea::addCard(const std::shared_ptr<Card>& card) {
    if (card) {
        cards.addCard(card);
    }
}

// Removes a specified card from the play area
void PlayArea::removeCard(const std::shared_ptr<Card>& card) {
    cards.removeCard(card);
}

// Removes all cards from the play area
void PlayArea::clear() {
    cards.clear();
}

// Checks if the play area has no cards
bool PlayArea::isEmpty() const {
    return cards.isEmpty();
}

// Returns the number of cards in the play area
size_t PlayArea::size() const {
    return cards.size();
}

// Returns a const reference to the card collection
const CardCollection& PlayArea::getCards() const {
    return cards;
}

// Returns a modifiable reference to the vector of card pointers
std::vector<CardPtr>& PlayArea::getCards() {
    return cards.getCards();
}

// Prints the cards in the play area or "(empty)" if no cards exist
void PlayArea::print() const {
    if (cards.isEmpty()) {
        std::cout << "        (empty)\n";
        return;
    }

    cards.print();
}