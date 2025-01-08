#include "Player.hpp"

Player::Player(const std::string& name, bool isNPC):name(name),isNPC(isNPC){}

void Player::addCard(int card)
{
	if (hand.size() >= 4) {
		std::cout << name << " cannot hold more than 4 cards!" << std::endl;
		return;
	}
	hand.push_back(card);
}


int Player::getScore() const
{
	return std::accumulate(hand.begin(),hand.end(),0)%10;
}

void Player::printHand() const
{
	std::cout << name << "'s hand: ";
	for (int card : hand)
	{
		std::cout << card << " ";
	}
	std::cout << "\n Score: " << getScore() << std::endl;
}

void Player::resetHand(){

	hand.clear();
}

const std::string& Player::getName() const
{
	return name;
}

void Player::setName(const std::string& name)
{
	this->name = name;
}

bool Player::getisNPC() const
{
	return isNPC;
}

void Player::setisNPC(bool isNPC)
{
	this->isNPC = isNPC;
}

void Player::getCards()
{
	for (auto& c : hand)
	{
		std::cout << c<<" ";
	}
	std::cout << std::endl;
}

const std::vector<int>& Player::getHand() const
{
	return hand;
}

int Player::getbrPobjeda()const
{
	return brPobjeda;
}

void Player::setbrPobjeda(int i)
{
	brPobjeda = i;
}

