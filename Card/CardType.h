#pragma once
#include <string>
#include <ostream>

enum class CardType {
    CANNON,
    MERMAID,
    SWORD,
    CHEST,
    MAP,
    HOOK,
    KRAKEN,
    ORACLE,
    KEY
};

inline std::string cardTypeToString(CardType type) {
    switch (type) {
        case CardType::CANNON: return "Cannon";
        case CardType::MERMAID: return "Mermaid";
        case CardType::SWORD: return "Sword";
        case CardType::CHEST: return "Chest";
        case CardType::MAP: return "Map";
        case CardType::HOOK: return "Hook";
        case CardType::KRAKEN: return "Kraken";
        case CardType::ORACLE: return "Oracle";
        case CardType::KEY: return "Key";
        default: return "Unknown";
    }
}

inline std::ostream& operator<<(std::ostream& os, const CardType& type) {
    os << cardTypeToString(type);
    return os;
}
