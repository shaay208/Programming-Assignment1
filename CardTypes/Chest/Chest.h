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
    // Marked as const since it doesn’t modify the object
    std::string str() const override;

    // Returns the description of the Chest card's special ability
    // Marked as const since it doesn’t modify the object
    std::string getAbilityDescription() const override;

    // Determines if the Chest card can be played on top of another card
    // Marked as const 
    bool canPlayOn(const CardPtr& other) const override;

    // Called when the card is about to be added to a player’s bank
    // May influence game logic like preventing busts
    // Marked as const because it doesn't modify the Chest card itself
    void willAddToBank(Game& game, Player& player) const override;

    // Executes the Chest card’s special ability, modifying game state
    // Not marked const because it changes the game
    void executeAbility(Game& game, Player& player) override;
};