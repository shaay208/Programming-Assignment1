#pragma once
#include "../../Card/Card.h"

class Anchor : public Card {
public:
    explicit Anchor(int value);
    void executeAbility(Game& game, Player& player) override;
    void displayAbilityDescription() const override;
};