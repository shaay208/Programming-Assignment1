#include "Card.h"
#include "../Game/Game.h"
#include "../Player/Player.h"
#include <iostream>
#include <algorithm>

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

// Executes the card's ability, but only if the player has not busted
void Card::play(Game& game, Player& player) {
    // Execute the card's ability only if the player hasn't busted
    if (!player.hasBusted()) {
        executeAbility(game, player);
    }
}

// A placeholder method called when the card is about to be added to a player's bank
// This can be overridden in derived classes to define special behavior
void Card::willAddToBank(Game& game, Player& player) const {
    // Default implementation does nothing
}

// Checks if playing this card would cause the player to bust, based on cards already in play
bool Card::wouldCauseBust(const std::vector<CardPtr>& playArea) const {
    // Check if there's already a card of the same type in the play area
    return std::any_of(playArea.begin(), playArea.end(),
        [this](const CardPtr& card) {
            return card && card->getType() == this->type;
        });
}
