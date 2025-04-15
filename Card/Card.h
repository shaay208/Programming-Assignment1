#pragma once
#include <string>
#include "CardType.h"

// Forward declarations
class Game;
class Player;

class Card {
protected:
    CardType type;  // Type of the card
    int value;      // Value of the card

public:
    // Constructor
    Card(CardType type, int value);

    // Destructor
    virtual ~Card() = default;

    // Getters
    CardType getType() const;
    int getValue() const;

    // methods to be implemented in the card classes
    virtual int getScoreValue() const;
    virtual std::string str() const = 0;
    virtual void play(Game& game, Player& player) = 0;
    virtual void willAddToBank(Game& game, Player& player);
};
