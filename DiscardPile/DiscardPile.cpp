#include "DiscardPile.h"
#include <iostream>

// Adds a single card to the discard pile
void DiscardPile::addCard(std::shared_ptr<Card> card) {
    cards.addCard(card);
}

// Adds multiple cards to the discard pile
void DiscardPile::addCards(const CardCollection& newCards) {
    cards.addCards(newCards);
}

// Draws a specified number of cards from the discard pile (from the back)
CardCollection DiscardPile::drawCards(int count) {
    CardCollection drawnCards;
    auto& cardVector = cards.getCards();

    // Calculate how many cards we can actually draw
    int actualCount = std::min(count, static_cast<int>(cardVector.size()));

    // Move the cards to the new collection
    for (int i = 0; i < actualCount; ++i) {
        drawnCards.addCard(cardVector.back());
        cardVector.pop_back();
    }

    return drawnCards;
}

// Finds and returns one card of a given suit, if available
std::shared_ptr<Card> DiscardPile::findOneCardOfSuit(CardType suit) const {
    return cards.findOneCardOfSuit(suit);
}

// Removes a specific card from the discard pile, if it exists
bool DiscardPile::removeCard(const std::shared_ptr<Card>& card) {
    auto& cardVector = cards.getCards();
    auto it = std::find(cardVector.begin(), cardVector.end(), card);
    if (it != cardVector.end()) {
        cardVector.erase(it);
        return true;
    }
    return false;
}

// Checks whether the discard pile is empty
bool DiscardPile::isEmpty() const {
    return cards.isEmpty();
}

// Displays the contents of the discard pile
void DiscardPile::print() const {
    std::cout << "Discard Pile: ";
    cards.print();
}

// Returns a modifiable reference to the card collection
CardCollection& DiscardPile::getCards() {
    return cards;
}

// Returns a constant reference to the card collection
const CardCollection& DiscardPile::getCards() const {
    return cards;
}
