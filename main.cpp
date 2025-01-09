#include "Game.hpp"

int main() {
    int numHumanPlayers;
    char dealerChoice;
    std::string dealername;
    std::vector<std::string> humannames;
    std::vector<std::string> npcnames = {"Kiriyu","Haruto","Haruka"};

    std::cout << "Should the dealer be a human? (y/n): ";
    std::cin >> dealerChoice;
    bool dealerIsHuman = (dealerChoice == 'y' || dealerChoice == 'Y');
    if (dealerIsHuman)
    {
        std::cout << "Enter the name for Dealer  :";
        std::cin >> dealername;
        std::cout << "Enter the number of human players (0-3): ";
        std::cin >> numHumanPlayers;
        if (numHumanPlayers < 0 || numHumanPlayers > 3) 
        {
        std::cout << "Invalid number of players. Please enter a value between 0 and 3." << std::endl;
        return 1;
        }
    }
    else
    {
        std::cout << "Enter the number of human players (1-3): ";
        std::cin >> numHumanPlayers;
        if (numHumanPlayers < 1 || numHumanPlayers > 3) {
            std::cout << "Invalid number of players. Please enter a value between 1 and 3." << std::endl;
            return 1;
        }
        dealername = npcnames.at(2);
    }
    

    
    for (int i = 0;i < numHumanPlayers;i++)
    {
        std::string name;
        std::cout << "Enter the name for Player " << i + 1 << " :";
        std::cin >> name;
        humannames.push_back(name);
    }

    Game game(numHumanPlayers, dealerIsHuman,dealername,humannames,npcnames);
    game.play();
    return 0;
}
