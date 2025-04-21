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
#include "../CardTypes/Anchor/Anchor.h"

#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>

void Deck::initialize() {
    // clearing the deck before initializing
    cards.clear();
    
    // Add Cannon cards (values 2-7)
    for (int i = 2; i <= 7; ++i) {
        cards.push_back(std::make_shared<Cannon>(i));
    }
    
    // Add Chest cards (values 2-7)
    for (int i = 2; i <= 7; ++i) {
        cards.push_back(std::make_shared<Chest>(i));
    }
    
    // Add Key cards (values 2-7)
    for (int i = 2; i <= 7; ++i) {
        cards.push_back(std::make_shared<Key>(i));
    }
    
    // Add Sword cards (values 2-7)
    for (int i = 2; i <= 7; ++i) {
        cards.push_back(std::make_shared<Sword>(i));
    }
    
    // Add Hook cards (values 2-7)
    for (int i = 2; i <= 7; ++i) {
        cards.push_back(std::make_shared<Hook>(i));
    }
    
    // Add Oracle cards (values 2-7)
    for (int i = 2; i <= 7; ++i) {
        cards.push_back(std::make_shared<Oracle>(i));
    }
    
    // Add Map cards (values 2-7)
    for (int i = 2; i <= 7; ++i) {
        cards.push_back(std::make_shared<Map>(i));
    }
    
    // Add Mermaid cards (values 4-9)
    for (int i = 4; i <= 9; ++i) {
        cards.push_back(std::make_shared<Mermaid>(i));
    }
    
    // Add Kraken cards (values 2-7)
    for (int i = 2; i <= 7; ++i) {
        cards.push_back(std::make_shared<Kraken>(i));
    }

    // this is commented beacuse this change is braking the code run
    // for (int i = 2; i <= 7; ++i) {
    //     cards.push_back(std::make_shared<Anchor>(i));
    // }
    // shuffle the deck after initializing
    shuffle();
}

// Shuffles the deck using a random number generator seeded with current time
void Deck::shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

// Draws and removes the top card from the deck
// Returns nullptr if deck is empty
std::shared_ptr<Card> Deck::drawCard() {
    if (cards.empty()) {
        return nullptr;
    }
    
    auto card = cards.back();
    cards.pop_back();
    return card;
}

// Returns the top card without removing it from deck
// Returns nullptr if deck is empty
std::shared_ptr<Card> Deck::peekTop() const {
    if (cards.empty()) {
        return nullptr;
    }
    return cards.back();
}

// Prints all cards in the deck
// Displays "Deck is empty" if there are no cards
void Deck::print() const {
    if (cards.empty()) {
        std::cout << "        Deck is empty\n";
        return;
    }
    
    for (const auto& card : cards) {
        std::cout << "        " << card->str() << "\n";
    }
}