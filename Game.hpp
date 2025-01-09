#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Player.hpp"
class Game {
private:
	std::vector<int> deck;
	std::vector<Player> players;
	Player dealer;
	bool dealerIsHuman;
public:
	Game(int brojHumanPlay, bool dealerIsHunam, std::string dealername, std::vector<std::string> humannames, std::vector<std::string> npcnames);
	void dealCards();
	void play();
private:
	void resetDeck();
	int drawCard();
	void rotatePlayers();
	void nonDealerPick();
	void waitForUser();
};
#endif // !GAME_HPP
