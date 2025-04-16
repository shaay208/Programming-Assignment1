#include "Bank.h"
#include <iostream>
#include <map>
#include <algorithm>

// Constructor initializes score to 0
Bank::Bank() : score(0) {}

// Adds a card to the bank and recalculates the score
void Bank::addCard(const CardPtr& card) {
    cards.addCard(card);
    calculateScore();
}

// Adds multiple cards to the bank and recalculates the score
void Bank::addCards(const CardCollection& newCards) {
    cards.addCards(newCards);
    calculateScore();
}

// Returns the current score of the bank
int Bank::getScore() const {
    return score;
}

// Recalculates the score based on the highest card value of each type
void Bank::calculateScore() {
    score = 0;
    std::map<CardType, int> highestValues;

    // Get the list of cards currently in the bank
    const auto& cardList = cards.getCards();

    // Determine the highest value card for each card type
    for (const auto& card : cardList) {
        CardType type = card->getType();
        int value = card->getValue();

        // Store the highest value found for each card type
        if (highestValues.find(type) == highestValues.end() ||
            value > highestValues[type]) {
            highestValues[type] = value;
        }
    }

    // Sum the highest values from each card type to compute the score
    for (const auto& pair : highestValues) {
        score += pair.second;
    }
}

// Clears all cards from the bank and resets the score
void Bank::clear() {
    cards.clear();
    score = 0;
}

// Returns true if the bank has no cards
bool Bank::isEmpty() const {
    return cards.isEmpty();
}

const CardCollection& Bank::getBank() const {
    return cards;
}

// Prints all cards in the bank and the current score
void Bank::print() const {
    if (isEmpty()) {
        std::cout << "Bank is empty" << std::endl;
        return;
    }

    const auto& cardList = cards.getCards();
    for (const auto& card : cardList) {
        std::cout << card->str() << " ";
    }
    std::cout << std::endl;
    std::cout << "Score: " << score << std::endl;
}

// Returns a modifiable reference to the card collection
CardCollection& Bank::getCards() {
    return cards;
}

// Returns a const reference to the card collection
const CardCollection& Bank::getCards() const {
    return cards;
}
