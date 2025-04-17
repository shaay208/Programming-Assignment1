#include "Key.h"
#include "../../Game/Game.h"
#include "../../Player/Player.h"
#include <iostream>
#include <sstream>
#include <algorithm>

// Constructor: Initializes a Key card with the given value and sets its type to KEY
Key::Key(int value) : Card(CardType::KEY, value) {}

// Returns a string representation of the Key card
std::string Key::str() const {
    return "Key(" + std::to_string(getValue()) + ")";
}

// Executes the Key card's ability when played
void Key::executeAbility(Game& game, Player& player) {
    // Key has no effect when played to the play area
    std::cout << "No immediate effect. If banked with a chest, draw as many bonus cards from the Discard pile as you moved into your Bank." << std::endl;
}

// Provides a textual description of the Key card's ability
std::string Key::getAbilityDescription() const {
    return "When banked with a Chest, draw bonus cards from the Discard pile.";
}

// Determines if this Key card can be played on another card
bool Key::canPlayOn(const CardPtr& other) const {
    // Can only be played on another Key with lower value
    return other && other->getType() == CardType::KEY && other->getValue() < getValue();
}

// Called before the Key card is added to the bank
void Key::willAddToBank(Game& game, Player& player) const {
    // Check if there's a Chest card in the player's play area
    const auto& playArea = player.getPlayArea();
    bool hasChest = std::any_of(playArea.begin(), playArea.end(),
        [](const CardPtr& card) { return card->getType() == CardType::CHEST; });

    if (hasChest) {
        std::cout << "Chest and Key activated. ";

        // Create a comma-separated list of the cards being moved into the bank
        std::stringstream bankCards;
        bool first = true;
        for (const auto& card : playArea) {
            if (!first) {
                bankCards << ", ";
            }
            bankCards << card->str();
            first = false;
        }

        // Output the list of cards being added to the bank
        std::cout << "Added " << bankCards.str() << ", to your bank." << std::endl;

        // Note: Actual logic to move cards to bank is handled by the Player class
    }
}
