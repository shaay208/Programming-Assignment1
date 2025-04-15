#include "Card.h"
#include "../Game/Game.h"
#include "../Player/Player.h"
#include <iostream>
#include <string>

// Constructor: Initializes the card with a specific type and value
Card::Card(CardType type, int value) : type(type), value(value) {}

// Returns the type (suit/category) of the card
CardType Card::getType() const {
    return type;
}

// Returns the numeric value of the card
int Card::getValue() const {
    return value;
}

// Returns the score value of the card (could be customized per card type if needed)
int Card::getScoreValue() const {
    return value;
}

// A placeholder method called when the card is about to be added to a player's bank
// This can be overridden in derived classes to define special behavior
void Card::willAddToBank(Game& game, Player& player) {
    // Currently no special behavior defined
}
