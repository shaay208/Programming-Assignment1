#include "Anchor.h"
#include "../../Game/Game.h"
#include "../../Player/Player.h"
#include <iostream>

Anchor::Anchor(int value) : Card(CardType::ANCHOR, value) {}

void Anchor::executeAbility(Game& game, Player& player) {
    // When an Anchor is played, move all previous cards to bank before potential bust
    const auto& playArea = player.getPlayArea();
    const auto& cards = playArea.getCards();
    
    // Find this Anchor's position in play area
    auto anchorPos = std::find_if(cards.begin(), cards.end(),
        [this](const std::shared_ptr<Card>& card) {
            return card.get() == this;
        });
    
    if (anchorPos != cards.end()) {
        // Move all cards before the Anchor to bank
        for (auto it = cards.begin(); it != anchorPos; ++it) {
            player.getBank().addCard(*it);
        }
        std::cout << "Anchor saves previous cards by moving them to bank!\n";
    }
}

void Anchor::displayAbilityDescription() const {
    std::cout << "Any cards drawn before the Anchor card are safe and moved to the bank, even if you bust.\n";
}