#pragma once
#include <string>
#include <ostream>

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

inline std::string cardTypeToString(CardType type) {
    switch (type) {
        case CardType::CANNON:  return "Cannon";
        case CardType::CHEST:   return "Chest";
        case CardType::KEY:     return "Key";
        case CardType::SWORD:   return "Sword";
        case CardType::HOOK:    return "Hook";
        case CardType::ORACLE:  return "Oracle";
        case CardType::MAP:     return "Map";
        case CardType::MERMAID: return "Mermaid";
        case CardType::KRAKEN:  return "Kraken";
        default:               return "Unknown";
    }
}

inline std::ostream& operator<<(std::ostream& os, const CardType& type) {
    os << cardTypeToString(type);
    return os;
}
