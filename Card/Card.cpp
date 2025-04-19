#include "Card.h"
#include "../Game/Game.h"
#include "../Player/Player.h"
#include "../Bank/Bank.h"
#include <algorithm>
#include <sstream>

Card::Card(CardType type, int value) : type(type), value(value) {
    if (value < 2 || value > 9) {
        throw std::invalid_argument("Card values must be between 2 and 9");
    }
}

void Card::play(Game& game, Player& player) {
    executeAbility(game, player);
}

void Card::willAddToBank(Game& game, Player& player) {
    // Default implementation does nothing
}

std::string Card::str() const {
    std::stringstream ss;
    ss << cardTypeToString(type) << "(" << value << ")";
    return ss.str();
}

int Card::getValue() const {
    return value;
}

bool Card::wouldCauseBust(const std::vector<CardPtr>& playArea) const {
    return std::any_of(playArea.begin(), playArea.end(),
        [this](const CardPtr& card) {
            return card->getType() == this->type;
        });
}