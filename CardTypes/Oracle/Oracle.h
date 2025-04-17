#pragma once

#include "../../Card/Card.h"

// Forward declarations to avoid circular dependency and reduce compilation time
class Game;
class Player;

// Oracle card class derived from the base Card class
class Oracle : public Card {
public:
    // Constructor: initializes Oracle card with a given value
    Oracle(int value);

    // Returns a string representation of the card (e.g., "Oracle(5)")
    std::string str() const override;

    // Defines the Oracle card's special ability when played
    void executeAbility(Game& game, Player& player) override;

    // Returns a string explaining the card's ability (for UI/help)
    std::string getAbilityDescription() const override;

    // Defines the rule for when this card can be played on another card
    bool canPlayOn(const CardPtr& other) const override;
};
