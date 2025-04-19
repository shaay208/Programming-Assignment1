#include "Sword.h"
#include "../../Game/Game.h"
#include "../../Player/Player.h"
#include <iostream>

Sword::Sword(int value) : Card(CardType::SWORD, value) {}


// Returns a string representation of the Sword card
std::string Sword::str() const {
    return "Sword(" + std::to_string(value) + ")";
}

// execute the card ability
void Sword::executeAbility(Game& game, Player& player) {
    Player& opponent = game.getOtherPlayer();
    const auto& opponentBank = opponent.getBank();
    
    if (opponentBank.isEmpty()) {
        std::cout << "        No cards in other player's Bank. Play continues.\n";
        return;
    }

    // Display opponent's bank
    std::cout << "\nOther player's Bank:\n";
    opponent.displayBank();
    
    // Get available suits from opponent's bank
    std::cout << "\nChoose a suit to steal from (enter number):\n";
    std::vector<CardType> availableSuits;
    const auto& bankCards = opponentBank.getCards().getCards();
    
    // Collect unique suits
    for (const auto& card : bankCards) {
        if (std::find(availableSuits.begin(), availableSuits.end(), 
            card->getType()) == availableSuits.end()) {
            availableSuits.push_back(card->getType());
        }
    }
    
    // Display available suits
    for (size_t i = 0; i < availableSuits.size(); ++i) {
        std::cout << i << ": " << cardTypeToString(availableSuits[i]) << "\n";
    }
    
    // Get player choice
    int choice;
    std::cin >> choice;
    std::cin.ignore(); // Clear newline
    
    if (choice >= 0 && choice < static_cast<int>(availableSuits.size())) {
        CardType chosenSuit = availableSuits[choice];
        
        // Find the highest value card of the chosen suit
        CardPtr highestCard = nullptr;
        int highestValue = -1;
        
        for (const auto& card : bankCards) {
            if (card->getType() == chosenSuit && card->getValue() > highestValue) {
                highestCard = card;
                highestValue = card->getValue();
            }
        }
        
        if (highestCard) {
            std::cout << "Stealing " << highestCard->str() 
                      << " from other player's Bank.\n";
            opponent.getBank().removeCard(highestCard);  // Use Bank's removeCard method
            player.playCard(highestCard.get(), game);  // Add game parameter to playCard
        }
    }
}

// Describes the sword's ability for tooltips or help menus
void Sword::displayAbilityDescription() const {
    std::cout << "Steal the top card (i.e. the highest value) of any suit from "
              << "the other player's Bank into your Play Area.\n";
}

