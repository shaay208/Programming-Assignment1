#pragma once
#include "../../Card/Card.h"

// Mermaid class inherits from the base Card class
class Mermaid : public Card {
public:
    // Constructor using initializer list to set the Mermaid card's value
    Mermaid(int value);

    // Returns a string representation of the card, e.g., "Mermaid(3)"
    std::string str() const override;

    // Executes the special ability of the Mermaid card
    void executeAbility(Game& game, Player& player) override;

    // Returns a description of what the Mermaid card does
    void displayAbilityDescription() const override;

};