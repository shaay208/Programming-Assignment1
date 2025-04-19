#pragma once
#include "../../Card/Card.h"

// Map class derived from Card, representing a special card with its own behavior
class Map : public Card {
public:
    // Constructor using initializer list 
    // Initializes the Map card with a specific value
    explicit Map(int value);

    // Returns a string representation of the card (e.g., "Map(5)")
    std::string str() const override;

    // Returns a description of the Map's special ability
    void displayAbilityDescription() const override;

    // Non-const function as it alters game state
    // Executes the Map's ability when played
    void executeAbility(Game& game, Player& player) override;
};
