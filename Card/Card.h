#pragma once
#include <string>
#include <vector>
#include <memory>
#include "CardType.h"

// Forward declarations
class Game;
class Player;
class Card;

// Define the smart pointer type alias before using it
using CardPtr = std::shared_ptr<Card>;
using CardCollection = std::vector<CardPtr>;

enum class CardType {
    CANNON,
    CHEST,
    KEY,
    SWORD,
    HOOK,
    ORACLE,
    MAP,
    MERMAID,
    KRAKEN
};

class Card {
protected:
    // Type of the card (made const as it shouldn't change)
    const CardType type; 
    // Value of the card (made const as it shouldn't change)
    const int value;      

public:
    // Constructor
    Card(CardType type, int value);

    // Virtual destructor for proper cleanup of derived classes
    virtual ~Card() = default;

    // Getters - all marked const as they don't modify state
    CardType getType() const { return type; }
    int getValue() const { return value; }

    // Card abilities - all marked const except play which modifies game state
    virtual void executeAbility(Game& game, Player& player) = 0;
    virtual std::string getAbilityDescription() const = 0;

    // Utility methods - all marked const as they don't modify state
    virtual int getScoreValue() const;
    virtual std::string str() const = 0;

    // Game mechanics
    virtual void play(Game& game, Player& player);
    virtual void willAddToBank(Game& game, Player& player) const;

    // Check if this card would cause a bust in the given play area
    bool wouldCauseBust(const std::vector<CardPtr>& playArea) const;

    // Check if this card can be played on top of another card
    virtual bool canPlayOn(const CardPtr& other) const = 0;
};
