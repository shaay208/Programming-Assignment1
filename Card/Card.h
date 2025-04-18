#pragma once
#include <string>
#include <memory>
#include <vector>
#include "CardType.h"

// Forward declarations
class Game;
class Player;
class Bank;
class Card;

// Define CardPtr after forward declaration
using CardPtr = std::shared_ptr<Card>;

class Card {
protected:
    CardType type;
    int value;

public:
    Card(CardType type, int value);
    virtual ~Card() = default;

    // Core functionality
    virtual void play(Game& game, Player& player);
    virtual void willAddToBank(Game& game, Player& player);
    virtual void willAddToBank(Bank& bank) {}
    virtual void executeAbility(Game& game, Player& player) = 0;
    virtual void displayAbilityDescription() const = 0;
    virtual std::string str() const;

    // Accessors
    CardType getType() const;
    int getValue() const;

    // Bust checking
    bool wouldCauseBust(const std::vector<CardPtr>& playArea) const;
};