// Include the Cannon class definition
#include "Cannon.h"

// Include game-related classes for using game state and players
#include "../../Game/Game.h"
#include "../../Player/Player.h"
#include <iostream>

// Constructor: Initializes the Cannon card with its type and value
Cannon::Cannon(int value) : Card(CardType::CANNON, value) {}

// Defines the special ability of the Cannon card
void Cannon::executeAbility(Game& game, Player& player) {
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
    std::cout << "\nChoose a suit to discard from (enter number):\n";
    std::vector<CardType> availableSuits;
    const auto& bankCards = opponentBank.getCards().getCards(); // Get vector of cards
    
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
            std::cout << "Discarding " << highestCard->str() 
                      << " from other player's Bank.\n";
            opponent.getBank().removeCard(highestCard);  // Use Bank's removeCard method
            game.addToDiscardPile(highestCard);
        }
    }
}

// Displays a description of the Cannon card's ability
void Cannon::displayAbilityDescription() const {
    std::cout << "Discard the top card (i.e. the highest value) of any suit from "
              << "the other player's Bank to the Discard Pile.\n";
}

// Returns a string representation of the Cannon card with its value
std::string Cannon::str() const {
    return "Cannon(" + std::to_string(value) + ")";
}