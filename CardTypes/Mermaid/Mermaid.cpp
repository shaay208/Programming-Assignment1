#include "Mermaid.h"
#include "../../Game/Game.h"
#include "../../Player/Player.h"
#include <iostream>

// Constructor initializes the card as a MERMAID type with a specified value
Mermaid::Mermaid(int value) : Card(CardType::MERMAID, value) {}

// Returns a string representation of the card, useful for display or debugging
std::string Mermaid::str() const {
    return "Mermaid(" + std::to_string(getValue()) + ")";
}

void Mermaid::executeAbility(Game& game, Player& player) {
    // Check if the deck is empty before proceeding
    if (game.getDeck().isEmpty()) {
        std::cout << "The deck is empty. No cards to look at." << std::endl;
        return;
    }

    // Peek at the top card of the deck without removing it
    auto topCard = game.getDeck().peek();
    std::cout << "You see: " << topCard->str() << std::endl;

    // Prompt the player to decide whether to take the card or not
    char choice;
    std::cout << "Do you want to take this card? (y/n): ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        // If yes, draw the card and add it to the player's hand
        auto drawnCard = game.getDeck().drawCard();
        if (drawnCard) {
            player.addCardToHand(drawnCard);
            std::cout << "Added " << drawnCard->str() << " to your hand." << std::endl;
        }
    }
    else {
        // If no, card remains on the deck
        std::cout << "Card remains on top of the deck." << std::endl;
    }
}

// Describes the card's ability for UI/help text
std::string Mermaid::getAbilityDescription() const {
    return "No effect but Mermaids are worth more.";
}

// Defines the play condition: can only play on another Mermaid with a lower value
bool Mermaid::canPlayOn(const CardPtr& other) const {
    return other && other->getType() == CardType::MERMAID && other->getValue() < getValue();
}
