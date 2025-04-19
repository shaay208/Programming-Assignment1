#pragma once
#include "../../Card/Card.h"

// Key class inherits from Card
class Key : public Card {
public:
    // Constructor using initializer list to initialize Key with a value
    explicit Key(int value);

    // Returns a string representation of the card
    std::string str() const override;

    // Returns the description of the Key cards ability
    void displayAbilityDescription() const override;

    // Called before the card is added to the bank
    void willAddToBank(Game& game, Player& player) override;

    // Executes the Key card�s ability when played (non-const as it modifies game state)
    void executeAbility(Game& game, Player& player) override;
};
