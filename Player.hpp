#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
class Player {
private:
	std::string name;
	std::vector<int> hand;
	int brPobjeda=0;
	bool isNPC;
public:
	Player(const std::string& name, bool isNPC = false);
	void addCard(int card);
	int getScore()const;
	void printHand()const;
	void resetHand();
	const std::string& getName()const;
	void setName(const std::string& name);
	bool getisNPC() const;
	void setisNPC(bool isNPC);
	void getCards();
	const std::vector<int>& getHand() const;
	int getbrPobjeda()const;
	void setbrPobjeda(int i);
};
#endif // !PLAYER_HPP
