#pragma once

// Include the base Card class
#include "../../Card/Card.h"

// Cannon class represents a special type of card with a unique ability
class Cannon : public Card {
public:

    // Explicit constructor to prevent implicit conversions
    explicit Cannon(int value);

    // Returns a string representation of the Cannon card
    std::string str() const override;

    // Executes the Cannon's special ability, affecting the game and the opponent
    void executeAbility(Game& game, Player& player) override;

    // Returns a description of the Cannon's ability
    void displayAbilityDescription() const override;
};
