#include "Deck.h"

// Include all card type headers
#include "../CardTypes/Cannon/Cannon.h"
#include "../CardTypes/Mermaid/Mermaid.h"
#include "../CardTypes/Sword/Sword.h"
#include "../CardTypes/Chest/Chest.h"
#include "../CardTypes/Map/Map.h"
#include "../CardTypes/Hook/Hook.h"
#include "../CardTypes/Kraken/Kraken.h"
#include "../CardTypes/Oracle/Oracle.h"
#include "../CardTypes/Key/Key.h"

#include <random>
#include <algorithm>
#include <memory>
#include <chrono>

// Constructor: Initializes the deck by resetting it
Deck::Deck() {
    reset();
}

// Draws the top card from the deck and removes it
CardPtr Deck::drawCard() {
    // If the deck is empty, return null
    if (isEmpty()) {
        return nullptr;
    }

    // Get the last card in the deck
    CardPtr drawnCard = getCards().back();

    // Remove the card from the deck
    getCards().pop_back();

    return drawnCard;
}

// Returns the top card from the deck without removing it
CardPtr Deck::peek() const {
    // If the deck is empty, return null
    if (isEmpty()) {
        return nullptr;
    }

    // Return the last card without removing it
    return getCards().back();
}

// Helper function to shuffle a card collection
void shuffleDeck(CardCollection& cards) {
    // Copy the card collection to a new collection for shuffling
    CardCollection shuffleDeck{ cards.begin(), cards.end() };

    // Shuffle the copied collection using a random generator
    std::shuffle(shuffleDeck.begin(), shuffleDeck.end(), std::mt19937{ std::random_device{}() });

    // Copy the shuffled cards back into the original collection
    std::copy(shuffleDeck.begin(), shuffleDeck.end(), cards.begin());
}

// Shuffles the deck
void Deck::shuffle() {
    shuffleDeck(*this);
}

// Resets the deck to its original state with all cards
void Deck::reset() {
    // Remove all existing cards from the deck
    clear();

    // Add cards of each type with values 1-13
    for (int value = 1; value <= 13; ++value) {
        getCards().push_back(std::make_shared<Cannon>(value));
        getCards().push_back(std::make_shared<Chest>(value));
        getCards().push_back(std::make_shared<Key>(value));
        getCards().push_back(std::make_shared<Sword>(value));
        getCards().push_back(std::make_shared<Hook>(value));
        getCards().push_back(std::make_shared<Map>(value));
        getCards().push_back(std::make_shared<Mermaid>(value));
        getCards().push_back(std::make_shared<Oracle>(value));
        getCards().push_back(std::make_shared<Kraken>(value));
    }

    // Shuffle the deck after resetting
    shuffle();
}
