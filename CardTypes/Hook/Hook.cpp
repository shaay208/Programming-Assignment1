#include "Hook.h"
#include "../../Game/Game.h"
#include "../../Player/Player.h"
#include <iostream>
#include <map>
#include <algorithm>

// Constructor using initializer list to initialize the card with type HOOK and the provided value
Hook::Hook(int value) : Card(CardType::HOOK, value) {}

// Returns a string representation of the Hook card
std::string Hook::str() const {
    return "Hook(" + std::to_string(getValue()) + ")";
}

// Ability of the Hook card: play the top card of any suit from your Bank into your play area
void Hook::executeAbility(Game& game, Player& player) {
    const auto& bank = player.getBank();
    if (bank.isEmpty()) {
        std::cout << "        No cards in your Bank. Play continues.\n";
        return;
    }

    // Display player's bank
    std::cout << "\nYour Bank:\n";
    player.displayBank();
    
    // Get available suits from bank
    std::vector<CardType> availableSuits;
    const auto& bankCards = bank.getCards().getCards();
    
    // Collect unique suits
    for (const auto& card : bankCards) {
        if (std::find(availableSuits.begin(), availableSuits.end(), 
            card->getType()) == availableSuits.end()) {
            availableSuits.push_back(card->getType());
        }
    }
    
    // Display available suits
    std::cout << "\nChoose a suit to play from (enter number):\n";
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
            std::cout << "Playing " << highestCard->str() << " from your Bank.\n";
            player.getBank().removeCard(highestCard);  // Use Bank's removeCard method
            player.playCard(highestCard.get(), game);  // Add game parameter to playCard
        }
    }
}

// Returns a description of the Hook's ability
void Hook::displayAbilityDescription() const {
    std::cout << "        Play the top card (i.e. the highest value) of any suit from your Bank into your play area.\n";
}
