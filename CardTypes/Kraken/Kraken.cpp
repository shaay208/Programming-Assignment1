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
    std::cout << "        Drawing and playing 3 cards:\n";
    
    // Draw and play 3 cards
    for (int i = 0; i < 3; ++i) {
        auto drawnCard = game.drawCard();
        if (!drawnCard) {
            std::cout << "        No more cards in the deck!\n";
            break;
        }

        std::cout << "\n" << player.getName() << " draws a " << drawnCard->str() << "\n";
        std::cout << "        ";
        drawnCard->displayAbilityDescription();
        
        if (player.wouldBust(drawnCard)) {
            std::cout << "BUST! " << player.getName() << " loses all cards in play area.\n";
            // Move cards from play area to discard pile
            auto cards = player.getPlayArea().getCards();
            for (const auto& card : cards) {
                game.addToDiscardPile(card);
            }
            game.addToDiscardPile(drawnCard);
            player.getPlayArea().clear();
            game.nextTurn();  // Move to next player immediately
            break;
        }
        
        // Pass the shared_ptr directly
        player.playCard(drawnCard, game);
        
        std::cout << player.getName() << "'s Play Area:\n";
        player.displayPlayArea();
    }
}


// Returns the description of the Kraken's ability
void Kraken::displayAbilityDescription() const {
    std::cout << "Draw 3 cards from the deck and play each.\n";
}
