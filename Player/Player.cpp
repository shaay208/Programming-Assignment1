#include "Player.h"
#include "../Game/Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>


// Array of possible player names
const std::string Player::names[10] = {
    "Sam", "Billy", "Jen", "Bob", "Sally",
    "Joe", "Sue", "Sasha", "Tina", "Marge"
};

// Constructor that randomly assigns a name from the names array
Player::Player(const std::string& playerName) : name(playerName), busted(false) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    name = names[std::rand() % 10];
}

const std::string& Player::getName() const {
    // Returns the player's name
    return name;
}

// Returns a const reference to the player's bank
const Bank& Player::getBank() const {
    return bank;
}

// Returns a reference to the player's bank
Bank& Player::getBank() {
    return bank;
}

// Returns a const reference to the player's play area
const PlayArea& Player::getPlayArea() const {
    return playArea;
}

// Returns a reference to the player's play area
PlayArea& Player::getPlayArea() {
    return playArea;
}

// Returns the player's current score from their bank
int Player::getScore() const {
    return bank.getScore();
}

// Returns whether the player has busted or not
bool Player::hasBusted() const {
    return busted;
}

// Attempts to play a card from the player's hand to their play area, returns true if player busts
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

// Moves all cards from play area to bank and resets bust status
void Player::movePlayAreaToBank() {
    // Moves all cards from the play area to the bank
    if (!busted) {
        const auto& cards = playArea.getCards();
        for (const auto& card : cards) {
            bank.addCard(card);
        }
        std::cout << name << " banks " << cards.size() << " cards.\n";
    }
    playArea.clear();
    busted = false;
}

// Moves all cards from play area to discard pile and resets bust status
void Player::bustPlayArea(DiscardPile& discardPile) {
    const auto& cards = playArea.getCards();
    for (const auto& card : cards) {
        discardPile.addCard(card);
    }
    playArea.clear();
    busted = false;
}

// Checks if playing the given card would cause a bust by having duplicate types
bool Player::wouldBust(const std::shared_ptr<Card>& card) const {
    const auto& cards = playArea.getCards();
    return std::any_of(cards.begin(), cards.end(),
        [&card](const std::shared_ptr<Card>& existingCard) {
            return existingCard->getType() == card->getType();
        });
}

// Checks if player has busted by having duplicate card types in play area
void Player::checkBust() {
    // Checks if the player has busted based on the current play area
    std::vector<CardType> types;
    const auto& cards = playArea.getCards();

    for (const auto& card : cards) {
        if (std::find(types.begin(), types.end(), card->getType()) != types.end()) {
            busted = true;
            return;
        }
        types.push_back(card->getType());
    }
    busted = false;
}

// Displays the player's play area
void Player::displayPlayArea() const {
    std::cout << "\n" << name << "'s Play Area:\n";
    playArea.print();
}

// Displays the player's bank and score
void Player::displayBank() const {
    std::cout << "\n" << name << "'s Bank:\n";
    bank.print();
    std::cout << "| Score: " << getScore() << "\n";
}