# CMakeList.txt : CMake project for Assignment 1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Assignment 1")

# Add source to this project's executable.
add_executable (CMakeTarget "Assignment 1.cpp" "Assignment 1.h" "Card/Card.h" "Card/Card.cpp" "Card/CardType.h" "CardCollection/CardCollection.h" "CardCollection/CardCollection.cpp" "CardTypes/Cannon/Cannon.cpp"  "CardTypes/Mermaid/Mermaid.cpp" "CardTypes/Mermaid/Mermaid.h" "CardTypes/Sword/Sword.h" "CardTypes/Sword/Sword.cpp" "CardTypes/Chest/Chest.h" "CardTypes/Chest/Chest.cpp" "CardTypes/Map/Map.h" "CardTypes/Map/Map.cpp" "CardTypes/Hook/Hook.h" "CardTypes/Hook/Hook.cpp" "CardTypes/Kraken/Kraken.h" "CardTypes/Kraken/Kraken.cpp" "CardTypes/Oracle/Oracle.h" "CardTypes/Oracle/Oracle.cpp" "CardTypes/Key/Key.cpp" "CardTypes/Key/Key.h" "Bank/Bank.h" "Bank/Bank.cpp" "Deck/Deck.h" "Deck/Deck.cpp" "DiscardPile/DiscardPile.h" "DiscardPile/DiscardPile.cpp" "Game/Game.h" "Game/Game.cpp" "PlayArea/PlayArea.h" "PlayArea/PlayArea.cpp" "Player/Player.h" "Player/Player.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
