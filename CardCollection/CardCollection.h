#pragma once
#include <vector>
#include <memory>
#include "../Card/Card.h"

class CardCollection {
private:
    std::vector<std::shared_ptr<Card>> cards;

public:
    CardCollection() = default;
    ~CardCollection() = default;

    void addCard(std::shared_ptr<Card> card);
    void addCards(const CardCollection& other);
    void removeCard(const std::shared_ptr<Card>& card);
    bool isEmpty() const;
    size_t size() const;
    void clear();
    std::vector<std::shared_ptr<Card>>& getCards();
    const std::vector<std::shared_ptr<Card>>& getCards() const;
    std::shared_ptr<Card> findOneCardOfSuit(CardType suit) const;
    void print() const;
};
