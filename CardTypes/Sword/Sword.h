// Header guard to prevent multiple inclusions
#pragma once

// Include the base Card class
#include "../../Card/Card.h"

// Sword class inherits from Card and represents a card with a stealing ability
// Sword class derived from Card base class
class Sword : public Card {
public:
    // Constructor to initialize Sword with a specific value
    Sword(int value);

    // Override: Returns string representation of the Sword card
    std::string str() const override;

    // Override: Steals coins from opponent's bank and adds to player's bank
    void executeAbility(Game& game, Player& player) override;

    // Override: Displays the description of the Sword card's stealing ability
    void displayAbilityDescription() const override;
};
