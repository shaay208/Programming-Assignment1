#include "Mermaid.h"
#include "../../Game/Game.h"
#include "../../Player/Player.h"
#include <iostream>

// Constructor initializes the card as a MERMAID type with a specified value
Mermaid::Mermaid(int value) : Card(CardType::MERMAID, value) {
    // Mermaid values range from 4-9
    if (value < 4 || value > 9) {
        throw std::invalid_argument("Mermaid cards must have values between 4 and 9");
    }
}
// Returns a string representation of the card, useful for display or debugging
std::string Mermaid::str() const {
    return "Mermaid(" + std::to_string(getValue()) + ")";
}

void Mermaid::executeAbility(Game& game, Player& player) {
    std::cout << "        No special ability. Worth " << getValue() << " points when banked.\n";
}

// Describes the card's ability for UI/help text
void Mermaid::displayAbilityDescription() const {
    std::cout << "No special ability. Mermaid cards have higher point values (4-9).\n";
}
