# CMakeList.txt : CMake project for Assignment 1, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project(Programming-Assignment1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add all source files
add_executable(Programming-Assignment1
    "Assignment 1.cpp"
    "Assignment 1.h"
    "Card/CardType.h"
    "Bank/Bank.cpp"
    "Bank/Bank.h"
    "Card/Card.cpp"
    "Card/Card.h"
    "CardCollection/CardCollection.cpp"
    "CardCollection/CardCollection.h"
    "Deck/Deck.cpp"
    "Deck/Deck.h"
    "DiscardPile/DiscardPile.cpp"
    "DiscardPile/DiscardPile.h"
    "Game/Game.cpp"
    "Game/Game.h"
    "PlayArea/PlayArea.cpp"
    "PlayArea/PlayArea.h"
    "Player/Player.cpp"
    "Player/Player.h"
    # Add all CardTypes files
    "CardTypes/Cannon/Cannon.cpp"
    "CardTypes/Cannon/Cannon.h"
    "CardTypes/Chest/Chest.cpp"
    "CardTypes/Chest/Chest.h"
    "CardTypes/Hook/Hook.cpp"
    "CardTypes/Hook/Hook.h"
    "CardTypes/Key/Key.cpp"
    "CardTypes/Key/Key.h"
    "CardTypes/Kraken/Kraken.cpp"
    "CardTypes/Kraken/Kraken.h"
    "CardTypes/Map/Map.cpp"
    "CardTypes/Map/Map.h"
    "CardTypes/Mermaid/Mermaid.cpp"
    "CardTypes/Mermaid/Mermaid.h"
    "CardTypes/Oracle/Oracle.cpp"
    "CardTypes/Oracle/Oracle.h"
    "CardTypes/Sword/Sword.cpp"
    "CardTypes/Sword/Sword.h"
)

# Include directories
target_include_directories(Programming-Assignment1 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Programming-Assignment1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
