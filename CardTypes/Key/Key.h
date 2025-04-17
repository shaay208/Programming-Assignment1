#pragma once
#include "../../Card/Card.h"

// Key class inherits from Card
class Key : public Card {
public:
    // Constructor using initializer list to initialize Key with a value (DC8)
    explicit Key(int value);

    // Returns a string representation of the card (DC7)
    std::string str() const override;

    // Returns the description of the Key card’s ability (DC7)
    std::string getAbilityDescription() const override;

    // Determines whether this Key card can be played on another card (DC7)
    bool canPlayOn(const CardPtr& other) const override;

    // Called before the card is added to the bank (DC7)
    void willAddToBank(Game& game, Player& player) const override;

    // Executes the Key card’s ability when played (non-const as it modifies game state)
    void executeAbility(Game& game, Player& player) override;
};
