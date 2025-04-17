#include "Oracle.h"
#include "../../Game/Game.h"
#include "../../Player/Player.h"
#include <iostream>

// Constructor initializes the Oracle card with a specific value
Oracle::Oracle(int value) : Card(CardType::ORACLE, value) {}

// Returns a string representation of the Oracle card
std::string Oracle::str() const {
    return "Oracle(" + std::to_string(getValue()) + ")";
}

// Executes the Oracle's special ability
void Oracle::executeAbility(Game& game, Player& player) {
    // Peek at the top card of the deck without removing it
    auto topCard = game.getDeck().peek();

    if (topCard) {
        std::cout << "The Oracle sees a " << topCard->str() << "\n";

        // Ask player if they want to draw the revealed card
        std::string input;
        std::cout << "Would you like to draw this card? (y/n): ";
        std::getline(std::cin, input);

        if (input == "y" || input == "Y") {
            std::cout << "You will draw this card on your next draw.\n";
            // Optional: logic could be added here to 'lock' this card for the player
        }
        else {
            std::cout << "You chose not to draw the card.\n";
            // Optional: in future versions, the player could shuffle, skip draw, or do something else
        }
    }
    else {
        std::cout << "No cards left in the deck to peek at.\n";
    }
}

// Describes the Oracle's ability for tooltips or help menus
std::string Oracle::getAbilityDescription() const {
    return "Peek at the top card of the deck before choosing whether to draw.";
}

// Determines if this card can be played on the previous card
bool Oracle::canPlayOn(const CardPtr& other) const {
    // Can only be played on another Oracle card with a lower value
    return other && other->getType() == CardType::ORACLE && other->getValue() < getValue();
}
