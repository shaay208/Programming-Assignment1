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
    // Get the player's bank cards
    const auto& playerBank = player.getBank().getCards();

    // If the player's bank is empty, there's no card to play
    if (playerBank.isEmpty()) {
        std::cout << "No cards in your bank to play." << std::endl;
        return;
    }

    // Display a list of highest-value cards by suit
    std::cout << "Select the top card from any suit in your Bank to play into your play area:" << std::endl;

    // Map to store the highest-value card for each CardType (suit)
    std::map<CardType, CardPtr> highestCards;
    int optionNumber = 1;

    // Loop through the player's bank to find the top card of each type
    for (const auto& card : playerBank) {
        CardType type = card->getType();

        // Replace only if this is the first of its type or has a higher value than existing
        if (highestCards.find(type) == highestCards.end() ||
            card->getValue() > highestCards[type]->getValue()) {
            highestCards[type] = card;
        }
    }

    // Display the list of options to the player
    for (const auto& [type, card] : highestCards) {
        std::cout << "(" << optionNumber++ << ") " << card->str() << std::endl;
    }

    // Prompt player to select a card to play
    int choice;
    std::cout << "Which card do you pick? ";
    std::cin >> choice;

    // Clamp input to a valid range to avoid crashes
    choice = std::clamp(choice, 1, static_cast<int>(highestCards.size()));

    // Get the chosen card based on the player's input
    auto it = highestCards.begin();
    std::advance(it, choice - 1);
    CardPtr chosenCard = it->second;

    // Remove the selected card from player's bank
    player.removeFromBank(chosenCard);

    // Add the chosen card to player's play area
    player.playCard(chosenCard);

    std::cout << "Played " << chosenCard->str() << " into your play area." << std::endl;
}

// Returns a description of the Hook's ability
std::string Hook::getAbilityDescription() const {
    return "Play the top card of any suit from your Bank into your play area. You must select one card.";
}

// Hook cards can be played on other Hook cards with a lower value
bool Hook::canPlayOn(const CardPtr& other) const {
    return other && other->getType() == CardType::HOOK && other->getValue() < getValue();
}
