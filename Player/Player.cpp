#include "Player.h"
#include "../Game/Game.h"
#include <iostream>
#include <algorithm>

Player::Player(const std::string& name) : name(name), busted(false) {}

const std::string& Player::getName() const {
    // Returns the player's name
    return name;
}

const CardCollection& Player::getHand() const {
    // Returns the player's hand (cards currently held)
    return hand;
}

const Bank& Player::getBankConst() const {
    // Returns the player's bank (cards in the bank)
    return bank;
}

int Player::getScore() const {
    // Returns the player's score based on cards in the bank
    return bank.getScore();
}

void Player::addToHand(std::shared_ptr<Card> card) {
    // Adds a card to the player's hand
    hand.addCard(card);
}

void Player::addToBank(std::shared_ptr<Card> card) {
    // Adds a card to the player's bank
    bank.addCard(card);
}

void Player::removeFromBank(const CardPtr& card) {
    // Removes a specific card from the player's bank
    bank.getCards().removeCard(card);
}

void Player::clearHand() {
    // Clears all cards from the player's hand
    hand.clear();
}

void Player::clearBank() {
    // Clears all cards from the player's bank
    bank.clear();
}

bool Player::playCard(const CardPtr& card) {
    // Checks if playing the card would cause the player to bust
    if (wouldBust(card)) {
        busted = true;
        return true; // Card can't be played as it causes a bust
    }

    // Adds the card to the player's play area and removes it from the hand
    playArea.addCard(card);
    removeFromHand(card);
    return false; // Card successfully played
}

void Player::clearPlayArea() {
    // Clears all cards from the player's play area and resets bust status
    playArea.clear();
    busted = false;
}

void Player::movePlayAreaToBank() {
    // Moves all cards from the play area to the bank
    bank.addCards(playArea);
    clearPlayArea();
}

void Player::addCardToHand(const CardPtr& card) {
    // Adds a card to the player's hand (same as addToHand)
    hand.addCard(card);
}

void Player::removeFromHand(const CardPtr& card) {
    // Removes a specific card from the player's hand
    hand.removeCard(card);
}

void Player::print() const {
    // Prints the player's status (name, hand, play area, bank, and score)
    std::cout << "Player: " << name << "\n";
    std::cout << "Hand: ";
    hand.print();
    std::cout << "Play Area: ";
    playArea.print();
    std::cout << "Bank: ";
    bank.print();
    std::cout << "Score: " << getScore() << "\n";
}

bool Player::wouldBust(const CardPtr& card) const {
    // Creates a temporary play area with the new card
    CardCollection tempPlayArea = playArea;
    tempPlayArea.addCard(card);

    // Checks if adding the card would cause a bust
    for (const auto& c : tempPlayArea.getCards()) {
        if (c->wouldCauseBust(tempPlayArea.getCards())) {
            return true; // A bust would occur with this card
        }
    }
    return false; // No bust would occur
}

void Player::checkBust() {
    // Checks if the player has busted based on the current play area
    busted = wouldBust(nullptr);
}

void Player::displayHand() const {
    // Displays the cards in the player's hand
    std::cout << name << "'s hand: ";
    hand.print();
}

void Player::displayBank() const {
    // Displays the cards in the player's bank along with their score
    std::cout << name << "'s bank (Score: " << getScore() << "): ";
    bank.print();
}
