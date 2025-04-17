#include "Kraken.h"
#include "../../Game/Game.h"
#include "../../Player/Player.h"
#include <iostream>

// Constructor initializing a Kraken card with the given value
Kraken::Kraken(int value) : Card(CardType::KRAKEN, value) {}

// Returns a string representation of the Kraken card
std::string Kraken::str() const {
    return "Kraken(" + std::to_string(getValue()) + ")";
}

// Executes the Kraken's special ability: draw and play 3 cards
void Kraken::executeAbility(Game& game, Player& player) {
    std::cout << "Draw 3 cards from the deck and play each:" << std::endl;

    // Loop to draw and play up to 3 cards
    for (int i = 0; i < 3; ++i) {
        // Draw a card from the deck
        CardPtr drawnCard = game.getDeck().drawCard();
        if (!drawnCard) {
            // If the deck is empty, stop drawing
            std::cout << "No more cards in the deck!" << std::endl;
            break;
        }

        // Output the drawn card
        std::cout << "Drew: " << drawnCard->str() << std::endl;

        // Play the drawn card; if it causes a bust, stop and show bust message
        if (player.playCard(drawnCard)) {
            std::cout << "BUST! " << player.getName() << " loses all cards in play area." << std::endl;
            break;
        }
    }
}

// Returns the description of the Kraken's ability
std::string Kraken::getAbilityDescription() const {
    return "Draw 3 cards from the deck and play each one immediately.";
}

// Determines whether this Kraken card can be played on another Kraken with lower value
bool Kraken::canPlayOn(const CardPtr& other) const {
    return other && other->getType() == CardType::KRAKEN && other->getValue() < getValue();
}
