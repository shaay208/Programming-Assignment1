#pragma once
#include <string>
#include "CardType.h"

class Game;
class Player;

class Card {
protected:
    CardType type;
    int value;

public:
    Card(CardType type, int value);
    virtual ~Card() = default;

    CardType getType() const;
    int getValue() const;
    virtual int getScoreValue() const;
    virtual std::string str() const = 0;
    virtual void play(Game& game, Player& player) = 0;
    virtual void willAddToBank(Game& game, Player& player);
};
