#include "Map.h"
#include "../../Game/Game.h"
#include "../../Player/Player.h"
#include <iostream>
#include <sstream>
#include <algorithm>

// Constructor initializes a Map card with the specified value
Map::Map(int value) : Card(CardType::MAP, value) {}

// Returns a string representation of the card, e.g., "Map(4)"
std::string Map::str() const {
    return "Map(" + std::to_string(getValue()) + ")";
}

// Executes the special ability of the Map card
void Map::executeAbility(Game& game, Player& player) {
    // If the discard pile is empty, there's nothing to draw
    if (game.getDiscardPile().isEmpty()) {
        std::cout << "The discard pile is empty. No cards to draw." << std::endl;
        return;
    }

    // Display the current discard pile
    std::cout << "Current discard pile:" << std::endl;
    game.getDiscardPile().print();

    // Ask the player how many cards they want to draw (1-3)
    int numCards;
    std::cout << "Which card do you pick? ";
    std::cin >> numCards;

    // Clamp the number between 1 and 3
    numCards = std::clamp(numCards, 1, 3);

    // Draw the requested number of cards from the discard pile
    auto drawnCards = game.getDiscardPile().drawCards(numCards);

    // Add each drawn card to the player's hand
    for (const auto& card : drawnCards) {
        player.addCardToHand(card);
    }

    std::cout << "Drew " << drawnCards.size() << " cards from the discard pile." << std::endl;
}

// Describes the ability of the Map card
std::string Map::getAbilityDescription() const {
    return "Draw 3 cards from discard pile and pick one to add to the play area.";
}

// Determines if this Map card can be played on another Map card of lower value
bool Map::canPlayOn(const CardPtr& other) const {
    return other && other->getType() == CardType::MAP && other->getValue() < getValue();
}
