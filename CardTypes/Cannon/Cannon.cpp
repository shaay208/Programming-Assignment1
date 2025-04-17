// Include the Cannon class definition
#include "Cannon.h"

// Include game-related classes for using game state and players
#include "../../Game/Game.h"
#include "../../Player/Player.h"
#include <iostream>

// Constructor: Initializes the Cannon card with its type and value
Cannon::Cannon(int value) : Card(CardType::CANNON, value) {}

// Returns a string representation of the Cannon card
std::string Cannon::str() const {
    return "Cannon(" + std::to_string(value) + ")";
}

// Defines the special ability of the Cannon card
void Cannon::executeAbility(Game& game, Player& player) {
    // Find opponent (assuming 2-player game)
    auto& players = game.getPlayers();
    auto opponent = (players[0].get() == &player) ? players[1] : players[0];

    // Access the opponent’s bank
    const auto& opponentBank = opponent->getBank();

    // If opponent's bank is empty, no action is taken
    if (opponentBank.isEmpty()) {
        std::cout << "No cards in other player's Bank. Play continues.\n";
        return;
    }

    // Show opponent’s bank cards to the player
    std::cout << opponent->getName() << "'s Bank:\n";
    opponent->displayBank();

    // Identify all unique card types (suits) in opponent's bank
    std::vector<CardType> availableSuits;
    for (const auto& card : opponentBank.getCards()) {
        if (std::find_if(availableSuits.begin(), availableSuits.end(),
            [&card](CardType suit) { return suit == card->getType(); }) == availableSuits.end()) {
            availableSuits.push_back(card->getType());
        }
    }

    // Ask the player to choose a suit to discard
    std::cout << "Choose a suit to discard (0-" << availableSuits.size() - 1 << "):\n";
    for (size_t i = 0; i < availableSuits.size(); ++i) {
        std::cout << i << ": " << static_cast<int>(availableSuits[i]) << "\n";
    }

    // Get player input for suit selection
    int choice;
    std::cin >> choice;
    std::cin.ignore(); // Clear newline from input buffer

    // Validate choice and proceed if valid
    if (choice >= 0 && choice < static_cast<int>(availableSuits.size())) {
        CardType chosenSuit = availableSuits[choice];

        // Find the highest value card of the selected suit in opponent's bank
        auto& bankCards = opponent->getBank().getCards();
        auto highestCard = std::max_element(bankCards.begin(), bankCards.end(),
            [chosenSuit](const auto& a, const auto& b) {
                if (a->getType() == chosenSuit && b->getType() == chosenSuit) {
                    return a->getValue() < b->getValue();
                }
                return a->getType() != chosenSuit;
            });

        // If a matching card is found, discard it and remove from opponent’s bank
        if (highestCard != bankCards.end() && (*highestCard)->getType() == chosenSuit) {
            std::cout << "Discarding " << (*highestCard)->str() << " from opponent's bank.\n";
            game.getDiscardPile().addCard(*highestCard);
            opponent->removeFromBank(*highestCard);
        }
    }
}

// Returns a brief description of the Cannon card's ability
std::string Cannon::getAbilityDescription() const {
    return "Discard the top card of any suit from the other player's Bank to the Discard Pile.";
}
