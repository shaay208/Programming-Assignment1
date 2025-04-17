#pragma once
#include "../../Card/Card.h"

// Kraken class definition, derived from the base Card class
class Kraken : public Card {
public:
    // Constructor using initializer list
    // Initializes a Kraken card with a specific value
    explicit Kraken(int value);

    // Returns a string representation of the card
    std::string str() const override;

    // Returns a description of the Kraken's special ability 
    std::string getAbilityDescription() const override;

    // Determines whether this card can be played on top of another card
    bool canPlayOn(const CardPtr& other) const override;

    // Executes the Kraken's special ability, modifying the game state
    void executeAbility(Game& game, Player& player) override;
};
