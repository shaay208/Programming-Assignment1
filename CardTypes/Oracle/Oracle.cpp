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
    auto topCard = game.peekTopCard();
    if (!topCard) {
        std::cout << "        No cards left in deck to peek at.\n";
        return;
    }

    std::cout << "        Next card in deck is: " << topCard->str() << "\n";
    std::cout << "        ";
    topCard->displayAbilityDescription();
    
    std::string input;
    do {
        std::cout << "\nDraw this card? (y/n): ";
        std::getline(std::cin, input);
    } while (input != "y" && input != "n");
    
    if (input == "y") {
        // Draw and play the card
        auto drawnCard = game.drawCard(); // Actually draw the card
        if (player.wouldBust(drawnCard)) {
            std::cout << "BUST! " << player.getName() << " loses all cards in play area.\n";
            // Move cards from play area to discard pile
            auto cards = player.getPlayArea().getCards();
            for (const auto& card : cards) {
                game.addToDiscardPile(card);
            }
            player.getPlayArea().clear();
            game.addToDiscardPile(drawnCard);
        } else {
            player.playCard(drawnCard, game);
        }
    } else {
        std::cout << "        Chose not to draw the card. Turn ends.\n";
    }
}


// Describes the Oracle's ability for tooltips or help menus
void Oracle::displayAbilityDescription() const {
    std::cout << "Peek at the top card of the deck before choosing to draw.\n";
}

