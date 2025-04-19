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
    std::cout << "        No immediate effect. If banked with a Chest, draw as many bonus cards from the Discard pile as you moved into your Bank.\n";
}
// Provides a textual description of the Key card's ability
void Key::displayAbilityDescription() const {
    std::cout << "No immediate effect. If banked with a Chest, draw as many bonus cards from the Discard pile as you moved into your Bank.\n";
}

void Key::willAddToBank(Game& game, Player& player) {
    // The actual Chest+Key combination is handled in Game::handleChestKeyCombo
    // This is just a placeholder as the combo requires both cards
}