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
    // Draw 3 cards from discard pile
    std::vector<CardPtr> drawnCards;
    
    std::cout << "\nDrawing up to 3 cards from discard pile:\n";
    
    for (int i = 0; i < 3; ++i) {
        auto card = game.drawFromDiscardPile();
        if (!card) {
            std::cout << "        No more cards in discard pile.\n";
            break;
        }
        drawnCards.push_back(card);
        std::cout << i << ": " << card->str() << "\n";
    }
    
    if (drawnCards.empty()) {
        std::cout << "        No cards available in discard pile.\n";
        return;
    }
    
    // Let player choose one card to play
    std::cout << "\nChoose a card to play (enter number): ";
    int choice;
    std::cin >> choice;
    std::cin.ignore(); // Clear newline
    
    if (choice >= 0 && choice < static_cast<int>(drawnCards.size())) {
        auto chosenCard = drawnCards[choice];
        
        // Return unchosen cards to discard pile
        for (size_t i = 0; i < drawnCards.size(); ++i) {
            if (i != static_cast<size_t>(choice)) {
                game.addToDiscardPile(drawnCards[i]);
            }
        }
        
        // Play the chosen card
        if (player.wouldBust(chosenCard)) {
            std::cout << "BUST! " << player.getName() << " loses all cards in play area.\n";
            auto playAreaCards = player.getPlayArea().getCards();
            for (const auto& card : playAreaCards) {
                game.addToDiscardPile(card);
            }
            player.getPlayArea().clear(); // Use getPlayArea().clear() instead of clearPlayArea()
            game.addToDiscardPile(chosenCard);
        } else {
            player.playCard(chosenCard.get(), game); // Convert shared_ptr to raw pointer
        }
    }
}

// Describes the ability of the Map card
void Map::displayAbilityDescription() const {
    std::cout << "Draw 3 cards from the discard pile and play one.\n";
}
