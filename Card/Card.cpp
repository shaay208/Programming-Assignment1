#include "Card.h"
#include "../Game/Game.h"
#include "../Player/Player.h"
#include <iostream>
#include <string>

Card::Card(CardType type, int value) : type(type), value(value) {}

CardType Card::getType() const {
    return type;
}

int Card::getValue() const {
    return value;
}

int Card::getScoreValue() const {
    return value;
}

void Card::willAddToBank(Game& game, Player& player) {
    
}
