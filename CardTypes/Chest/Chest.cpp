#include "Chest.h"
#include "../../Game/Game.h"
#include "../../Player/Player.h"
#include <iostream>
#include <sstream>
#include <algorithm>

// Constructor: Initializes a Chest card with a given value and sets its type to CHEST
Chest::Chest(int value) : Card(CardType::CHEST, value) {}

// Returns a string representation of the Chest card, e.g., "Chest(4)"
std::string Chest::str() const {
    return "Chest(" + std::to_string(getValue()) + ")";
}

// Executes the ability of the Chest card when played (not banked)
// According to the rule, there's no immediate effect unless it's banked with a Key
void Chest::executeAbility(Game& game, Player& player) {
    std::cout << "No immediate effect. If banked with a key, draw as many bonus cards from the Discard pile as you moved into your Bank." << std::endl;
}

// Called right before the Chest is added to the bank
// This checks for synergy with a Key card — if a Key is also in the play area,
// then a bonus action is *potentially* triggered (handled externally)
void Chest::willAddToBank(Game& game, Player& player) const {
    // Access the current player's play area (cards being banked)
    const auto& playArea = player.getPlayArea();

    // Check if a Key card is present in the play area
    bool hasKey = std::any_of(playArea.begin(), playArea.end(),
        [](const CardPtr& card) {
            return card->getType() == CardType::KEY;
        });

    if (hasKey) {
        std::cout << "Chest and Key activated. ";

        // Create a string listing all the cards being added to the bank
        std::stringstream bankCards;
        bool first = true;
        for (const auto& card : playArea) {
            if (!first) {
                bankCards << ", ";
            }
            bankCards << card->str();
            first = false;
        }

        std::cout << "Added " << bankCards.str() << ", to your bank." << std::endl;
    }
}

// Returns a short description of the card's ability, used in UI or tooltips
std::string Chest::getAbilityDescription() const {
    return "When banked with a Key, draw bonus cards from the Discard pile.";
}

// Defines playability rules: Chest cards can be played on other Chest cards,
// but only if their value is greater than the one already in play
bool Chest::canPlayOn(const CardPtr& other) const {
    return other && other->getType() == CardType::CHEST && other->getValue() < getValue();
}
