#include "Chest.h"
#include "../../Game/Game.h"
#include "../../Player/Player.h"
#include <iostream>

Chest::Chest(int value) : Card(CardType::CHEST, value) {}

void Chest::executeAbility(Game& game, Player& player) {
    std::cout << "        No immediate effect. If banked with a key, draw as many bonus cards from the Discard pile as you moved into your Bank.\n";
}

void Chest::displayAbilityDescription() const {
    std::cout << "No immediate effect. If banked with a Key, draw as many bonus cards from the Discard pile as you moved into your Bank.\n";
}

std::string Chest::str() const {
    return "Chest(" + std::to_string(getValue()) + ")";
}

void Chest::willAddToBank(Game& game, Player& player) {
    // The actual Chest+Key combination is handled in Game::handleChestKeyCombo
    // This is just a placeholder as the combo requires both cards
}