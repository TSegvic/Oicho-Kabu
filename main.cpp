#include "Game.hpp"

int main() {
    int numHumanPlayers;
    char dealerChoice;

    std::cout << "Enter the number of human players (1-4): ";
    std::cin >> numHumanPlayers;

    if (numHumanPlayers < 1 || numHumanPlayers > 4) {
        std::cout << "Invalid number of players. Please enter a value between 1 and 4." << std::endl;
        return 1;
    }

    std::cout << "Should the dealer be a human? (y/n): ";
    std::cin >> dealerChoice;
    bool dealerIsHuman = (dealerChoice == 'y' || dealerChoice == 'Y');

    Game game(numHumanPlayers, dealerIsHuman);
    game.play();
}
