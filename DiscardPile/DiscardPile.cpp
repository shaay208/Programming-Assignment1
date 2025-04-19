#include "DiscardPile.h"
#include <iostream>

// Adds a single card to the discard pile
void DiscardPile::addCard(const std::shared_ptr<Card>& card) {
    if (card) {
        cards.addCard(card);
    }
}
// Adds multiple cards to the discard pile
void DiscardPile::addCards(const std::vector<std::shared_ptr<Card>>& cardsToAdd) {
    std::cout << "        Adding cards to discard pile:\n";
    for (const auto& card : cardsToAdd) {
        if (card) {
            cards.addCard(card);
            std::cout << "        - " << card->str() << "\n";
        }
    }
}

// Draws a specified number of cards from the discard pile (from the back)
std::shared_ptr<Card> DiscardPile::drawCard() {
    if (cards.isEmpty()) {
        return nullptr;
    }
    
    // Get the top card (last card added)
    auto card = cards.getCard(cards.size() - 1);
    cards.removeCard(card);
    return card;
}

// Displays the contents of the discard pile
void DiscardPile::print() const {
    if (cards.isEmpty()) {
        std::cout << "        Discard pile is empty\n";
        return;
    }
    
    std::cout << "Discard Pile:\n";
    cards.print();
}


// Returns a constant reference to the card collection
const CardCollection& DiscardPile::getCards() const {
    return cards;
}


// Clears all cards from the discard pile
void DiscardPile::clear() {
    cards.clear();
}

bool DiscardPile::isEmpty() const {
    return cards.isEmpty();
}