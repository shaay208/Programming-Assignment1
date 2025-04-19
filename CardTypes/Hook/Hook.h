#pragma once

#include "../../Card/Card.h"

// The Hook class inherits from the base Card class and represents a special type of card
class Hook : public Card {
public:
    // Initializes a Hook card with a given value and sets its CardType to HOOK
    explicit Hook(int value);

    // Returns a string representation of the card (e.g., "Hook(3)")
    // Const function (DC7): does not modify object state
    std::string str() const override;

    // Provides a description of the card's special ability
    // Useful for tooltips, logs, or instructional display
    void displayAbilityDescription() const override;


    // Executes the card's ability when played
    // Non-const because it may alter game state (e.g., move cards)
    void executeAbility(Game& game, Player& player) override;
};
