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

bool Player::playCard(std::shared_ptr<Card> card, Game& game) {
    if (wouldBust(card)) {
        busted = true;
        std::cout << "BUST! " << name << " loses all cards in play area.\n";
        auto cards = playArea.getCards();
        for (const auto& c : cards) {
            game.addToDiscardPile(c);
        }
        playArea.clear();
        game.addToDiscardPile(card);
        return true;
    }
    
    playArea.addCard(card);
    std::cout << name << " plays " << card->str() << "\n";
    card->executeAbility(game, *this);  // Execute card's ability
    return false;
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

// Checks if adding the given card would cause a bust by having matching card types
bool Player::wouldBust(const std::shared_ptr<Card>& card) const {
    const auto& cards = playArea.getCards();
    return std::any_of(cards.begin(), cards.end(),
        [&card](const std::shared_ptr<Card>& existingCard) {
            return existingCard->getType() == card->getType();
        });
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

// Returns a reference to the player's play area
PlayArea& Player::getPlayArea() {
    return playArea;
}

// Returns a const reference to the player's play area
const PlayArea& Player::getPlayArea() const {
    return playArea;
}

// Displays the cards in the player's play area
void Player::displayPlayArea() const {
    std::cout << "\n" << name << "'s Play Area:\n";
    playArea.print();
}
