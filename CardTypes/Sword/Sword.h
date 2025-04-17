// Header guard to prevent multiple inclusions
#pragma once

// Include the base Card class
#include "../../Card/Card.h"

// Sword class inherits from Card and represents a card with a stealing ability
class Sword : public Card {
public:
    // Constructor to initialize Sword with a specific value
    Sword(int value);

    // Returns a string representation of the card
    std::string str() const override;

    // Executes the Sword card's ability (steal from opponent's bank)
    void executeAbility(Game& game, Player& player) override;

    // Describes the card's special ability
    std::string getAbilityDescription() const override;

    // Determines if this card can be played on another card
    bool canPlayOn(const std::shared_ptr<Card>& other) const override;
};
