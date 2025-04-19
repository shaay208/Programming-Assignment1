#pragma once

// Include the base Card class
#include "../../Card/Card.h"

// The Chest class represents a special type of card with unique behavior
class Chest : public Card {
public:
    // Constructor using initializer list
    // 'explicit' prevents accidental conversions from int to Chest
    explicit Chest(int value);

    // Returns a string representation of the card (e.g., "Chest(3)")
    // Returns a string representation of the Chest card
    std::string str() const override;

    // Displays the description of the Chest card's ability
    void displayAbilityDescription() const override;

    // Called before adding card to bank, handles special effects
    void willAddToBank(Game& game, Player& player) override;


    // Executes the Chest cards special ability, modifying game state
    // Not marked const because it changes the game
    void executeAbility(Game& game, Player& player) override;
};