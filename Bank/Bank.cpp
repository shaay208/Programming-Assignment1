#include "Bank.h"
#include <iostream>
#include <map>
#include <algorithm>

// Constructor initializes the bank and score to zero
Bank::Bank() : score(0) {}

void Bank::addCard(const std::shared_ptr<Card>& card) {
    // Add the card to the collection
    cards.addCard(card);

    // Recalculate the total score
    calculateScore();
}

void Bank::addCards(const CardCollection& newCards) {
    // Add all cards from the new collection to the bank
    cards.addCards(newCards);

    // Recalculate the total score
    calculateScore();
}

int Bank::getScore() const {
    // Returns the total score of the bank
    return score;
}

void Bank::calculateScore() {
    // Resets the score to zero before recalculating
    score = 0;

    // Map to store the highest value card of each type
    std::map<CardType, int> highestValues;

    // Iterate through all cards in the collection
    for (const auto& card : cards.getCards()) {
        CardType type = card->getType();
        int value = card->getValue();

        // Update the highest value for this card type
        if (highestValues.find(type) == highestValues.end() || value > highestValues[type]) {
            highestValues[type] = value;
        }
    }

    // Sum up the highest values across all card types
    for (const auto& pair : highestValues) {
        score += pair.second;
    }
}

void Bank::clear() {
    // Clears all cards from the bank
    cards.clear();

    // Resets the score to zero
    score = 0;
}

bool Bank::isEmpty() const {
    // Checks if the bank is empty
    return cards.isEmpty();
}

void Bank::print() const {
    // Prints the current score of the bank
    std::cout << "Bank Score: " << score << std::endl;

    // Prints all cards in the bank
    cards.print();
}

CardCollection& Bank::getCards() {
    // Returns a modifiable reference to the card collection
    return cards;
}

const CardCollection& Bank::getCards() const {
    // Returns a read-only reference to the card collection
    return cards;
}