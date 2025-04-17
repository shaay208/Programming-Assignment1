#include "Sword.h"
#include "../../Game/Game.h"
#include "../../Player/Player.h"
#include <iostream>

Sword::Sword(int value) : Card(CardType::SWORD, value) {}

std::string Sword::str() const {
    return "Sword(" + std::to_string(value) + ")";
}

void Sword::executeAbility(Game& game, Player& player) {
    // Identify the opponent (assuming a 2-player game)
    auto& players = game.getPlayers();
    auto opponent = (players[0].get() == &player) ? players[1] : players[0];

    // Access the opponent's bank of cards
    const auto& opponentBank = opponent->getBank();
    if (opponentBank.isEmpty()) {
        std::cout << "No cards in opponent's Bank. Play continues.\n";
        return;
    }

    // Display the opponent's bank so the player can view available cards
    std::cout << "Opponent's bank:\n";
    opponent->displayBank();

    // Collect all unique card suits (types) from the opponent's bank
    std::vector<CardType> availableSuits;
    for (const auto& card : opponentBank.getCards()) {
        if (std::find_if(availableSuits.begin(), availableSuits.end(),
            [&card](CardType suit) { return suit == card->getType(); }) == availableSuits.end()) {
            availableSuits.push_back(card->getType());
        }
    }

    // Ask the player to choose a suit to steal from
    std::cout << "Choose a suit to steal (0-" << availableSuits.size() - 1 << "):\n";
    for (size_t i = 0; i < availableSuits.size(); ++i) {
        std::cout << i << ": " << static_cast<int>(availableSuits[i]) << "\n";
    }

    int choice;
    std::cin >> choice;
    std::cin.ignore(); // Clear newline from input buffer

    // If a valid suit is chosen
    if (choice >= 0 && choice < static_cast<int>(availableSuits.size())) {
        CardType chosenSuit = availableSuits[choice];

        // Find the highest value card of the chosen suit in the opponent's bank
        auto& bankCards = opponent->getBank().getCards();
        auto highestCard = std::max_element(bankCards.begin(), bankCards.end(),
            [chosenSuit](const auto& a, const auto& b) {
                if (a->getType() == chosenSuit && b->getType() == chosenSuit) {
                    return a->getValue() < b->getValue();
                }
                return a->getType() != chosenSuit;
            });

        // If a valid card was found, steal it and move it to the play area
        if (highestCard != bankCards.end() && (*highestCard)->getType() == chosenSuit) {
            std::cout << "Stealing " << (*highestCard)->str() << " from opponent's bank.\n";
            auto stolenCard = *highestCard;
            opponent->removeFromBank(stolenCard);
            game.getPlayArea().addCard(stolenCard);
        }
    }
}

std::string Sword::getAbilityDescription() const {
    return "Steal the top card of any suit from the other player's Bank into your Play Area.";
}

bool Sword::canPlayOn(const std::shared_ptr<Card>& other) const {
    // Can play if the other card is also a Sword and has a lower value
    return other->getType() == CardType::SWORD && other->getValue() < value;
}
