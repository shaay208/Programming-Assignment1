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

// Adds a card to the specified pile if the index is valid
void PlayArea::addToPile(int pileIndex, std::shared_ptr<Card> card) {
    if (pileIndex >= 0 && pileIndex < NUM_PILES) {
        playPiles[pileIndex].addCard(card);
    }
}

// Returns a reference to the card collection at the given pile index
CardCollection& PlayArea::getPile(int pileIndex) {
    return playPiles[pileIndex];
}

// Returns a const reference to the card collection at the given pile index
const CardCollection& PlayArea::getPile(int pileIndex) const {
    return playPiles[pileIndex];
}

// Checks if all piles in the play area have at least one card
bool PlayArea::isFull() const {
    for (const auto& pile : playPiles) {
        if (pile.isEmpty()) {
            return false;
        }
    }
    return true;
}

// Adds a card to the first available matching pile or an empty pile
void PlayArea::addCard(std::shared_ptr<Card> card) {
    for (auto& pile : playPiles) {
        if (pile.isEmpty() || pile.getCards().front()->getType() == card->getType()) {
            pile.addCard(card);
            return;
        }
    }
}

// Determines if playing the card would cause a bust (duplicate suit in play area)
bool PlayArea::wouldCauseBust(std::shared_ptr<Card> card) const {
    for (const auto& pile : playPiles) {
        if (!pile.isEmpty() && pile.getCards().front()->getType() == card->getType()) {
            return true;
        }
    }
    return false;
}

// Returns all cards currently in the play area as a single vector
std::vector<std::shared_ptr<Card>> PlayArea::getAllCards() {
    std::vector<std::shared_ptr<Card>> allCards;
    for (const auto& pile : playPiles) {
        const auto& pileCards = pile.getCards();
        allCards.insert(allCards.end(), pileCards.begin(), pileCards.end());
    }
    return allCards;
}

// Returns a const reference to a vector containing all cards (cleared and rebuilt each time)
const std::vector<std::shared_ptr<Card>>& PlayArea::getCards() const {
    static std::vector<std::shared_ptr<Card>> allCards;
    allCards.clear();
    for (const auto& pile : playPiles) {
        const auto& pileCards = pile.getCards();
        allCards.insert(allCards.end(), pileCards.begin(), pileCards.end());
    }
    return allCards;
}

// Checks if a specific suit is currently present in the play area
bool PlayArea::hasSuit(CardType suit) const {
    for (const auto& pile : playPiles) {
        if (!pile.isEmpty() && pile.getCards().front()->getType() == suit) {
            return true;
        }
    }
    return false;
}

// Checks if the play area has no cards
bool PlayArea::isEmpty() const {
    for (const auto& pile : playPiles) {
        if (!pile.isEmpty()) {
            return false;
        }
    }
    return true;
}

// Clears all piles in the play area
void PlayArea::clear() {
    for (auto& pile : playPiles) {
        pile.clear();
    }
}

// Displays the contents of each pile to the console
void PlayArea::display() const {
    for (size_t i = 0; i < playPiles.size(); ++i) {
        std::cout << "Pile " << i + 1 << ": ";
        playPiles[i].print();
    }
}
