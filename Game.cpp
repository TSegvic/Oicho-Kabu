#include "Game.hpp"

Game::Game(int brojHumanPlay, bool dealerIsHunam, std::string dealername, std::vector<std::string> humannames, std::vector<std::string> npcnames) :dealer(dealername, !dealerIsHunam), dealerIsHuman(dealerIsHuman) {
	resetDeck();
	for (int i = 1;i <= brojHumanPlay;++i) {
		players.emplace_back(humannames.at(i - 1));
	}
	for (int i = 0;i < 3 - brojHumanPlay;++i) {
		players.emplace_back(npcnames.at(i), true);
	}
}

void Game::resetDeck()
{
	std::random_device rd;
	std::mt19937 g(rd());
	deck.clear();
	for (int i = 1;i <= 10;++i)
	{
		deck.insert(deck.end(), 4, i);
	}
	std::shuffle(deck.begin(), deck.end(), g);
}
int Game::drawCard()
{
	int card=deck.back();
	deck.pop_back();
	return card;
}
void Game::dealCards()
{
	dealer.addCard(drawCard());
	nonDealerPick();
	for (auto& player : players) {
		player.addCard(drawCard());
	}
}
void Game::nonDealerPick()
{
	std::vector<int>cards;
	for (size_t i = 0;i < players.size()+1;++i)
	{
		cards.push_back(drawCard());
	}
	for (auto& player : players)
	{
		std::cout << player.getName() << "'s time to pick cards:\n";
		std::cout << "Available cards: ";
		for (size_t j = 0;j < cards.size();++j)
		{
			std::cout << "[" << j + 1 << "] (" << cards.at(j) << ") ";
		}
		std::cout << std::endl;
		if (player.getisNPC())
		{
			int choice = std::rand() % cards.size();
			std::cout << player.getName() << " picks (" <<  cards.at(choice) << " ).\n";
			player.addCard(cards.at(choice));
			cards.erase(cards.begin() + choice);
		}
		else {
			int choice;
			std::cout << "Pick a card by entering its number: ";
			std::cin >> choice;
			while (choice < 1 || choice > static_cast<int>(cards.size())) {
				std::cout << "Invalid choice. Pick a card by entering its number: ";
				std::cin >> choice;
			}
			player.addCard(cards[choice - 1]);
			cards.erase(cards.begin() + choice - 1);
		}

	}
}
void Game::waitForUser()
{
	std::cout << "Press Enter to continue..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();

}
void Game::decide_winner()
{
	for (auto& player : players)
	{
		player.printHand();
		player.seeIfCombo();
	}
	dealer.printHand();
	dealer.seeIfCombo();
	int dealerScore = dealer.getScore();
	std::cout << "\nDealer's score is: " << dealerScore << std::endl;
	for (auto& player : players) {
		if ((player.getScore() > dealerScore||player.gethasWinCombo())&&!dealer.gethasWinCombo()) {
			std::cout << "Congrats " << player.getName() << " you won\n";
			player.setbrPobjeda(player.getbrPobjeda() + 1);
		}
		else if (player.getScore() < dealerScore||dealer.gethasWinCombo()) {
			std::cout << "Too bad " << player.getName() << " you lost	" << "Congrats " << dealer.getName() << " you won" << std::endl;
			dealer.setbrPobjeda(dealer.getbrPobjeda() + 1);
		}
		else
			std::cout << player.getName() << ": " << "It's a tie" << std::endl;
	}
}
void Game::rotatePlayers()
{
	players.push_back(dealer);
	dealer = players.front();
	players.erase(players.begin());
}
void Game::play() {
	for (int round = 1;round <= 4;++round)
	{
		std::cout << "\n---Round " << round << " ---\n";
		resetDeck();
		for (auto& player : players)
		{
			player.resetHand();
		}
		dealer.resetHand();
		dealCards();
		for (auto& player : players)
		{
			player.printHand();
			player.seeIfCombo();
			if (player.getisNPC()) {
				if (player.gethasWinCombo()){
					std::cout << player.getName() << " decides to stop." << std::endl;
					break;
				}
				else if (player.getScore() <= 3) {
					std::cout << player.getName() << " decides to take another card." << std::endl;
					player.addCard(drawCard());
					player.printHand();
				}
				else if (player.getScore()>=7) {
					std::cout << player.getName() << " decides to stop." << std::endl;
					break;
				}
				else {
					int choice = std::rand() % 2;
					if (choice) {
						player.addCard(drawCard());
						player.printHand();
					}
					else {
						std::cout << player.getName() << " decides to stop." << std::endl;
					}
				}
			}
			else {
				if (player.gethasWinCombo()) {
					std::cout << std::endl << player.getName() << " your score is: " << player.getScore() << " do you want to take a card? (y/n): ";
					char choice;
					std::cin >> choice;
					if (choice == 'y' || choice == 'Y') {
						player.addCard(drawCard());
						player.printHand();
					}
					else {
						std::cout << player.getName() << " decided to stop." << std::endl;
						break;
					}
				}
				else if (player.getScore() <= 3) {
					std::cout << player.getName() << " has to take another card." << std::endl;
					player.addCard(drawCard());
					player.printHand();
				}
				else if (player.getScore() >= 7) {
					std::cout << player.getName() << " has to stop." << std::endl;
					break;
				}
				else {
					std::cout << std::endl << player.getName() << " your score is: " << player.getScore() << " do you want to take a card? (y/n): ";
					char choice;
					std::cin >> choice;
					if (choice == 'y' || choice == 'Y') {
						player.addCard(drawCard());
						player.printHand();
					}
					else {
						std::cout << player.getName() << " decided to stop." << std::endl;
						break;
					}
				}
			}
		}
		dealer.addCard(drawCard());
		while (true) {
			dealer.printHand();
			if (dealerIsHuman) {
				if (dealer.getScore() <= 3) {
					std::cout << dealer.getName() << " decides to take another card." << std::endl;
					dealer.addCard(drawCard());
					break;
				}
				else if (dealer.getScore() >= 7) {
					std::cout << dealer.getName() << " decides to stop." << std::endl;
					break;
				}
				else {
					std::cout << std::endl << dealer.getName() << " your score is: " << dealer.getScore() << " do you want to take a card? (y/n): ";
					char choice;
					std::cin >> choice;
					if (choice == 'y' || choice == 'Y') {
						dealer.addCard(drawCard());
						break;
					}
					else {
						std::cout << dealer.getName() << " decided to stop." << std::endl;
						break;
					}
				}
			}
			else {
				if (dealer.getScore() <= 3) {
					std::cout << dealer.getName() << " decides to take another card." << std::endl;
					dealer.addCard(drawCard());
					break;
				}
				else if (dealer.getScore() >= 7) {
					std::cout << dealer.getName() << " decides to stop." << std::endl;
					break;
				}
				else {
					int choice = std::rand() % 2;
					if (choice) {
						dealer.addCard(drawCard());
						break;
					}
					else {
						std::cout << dealer.getName() << " decided to stop." << std::endl;
						break;
					}
					break;
				}
			}
		}
		decide_winner();
		waitForUser();
		rotatePlayers();
	}
	std::vector<int> svi;
	for (const auto& player : players)
	{
		svi.push_back(player.getbrPobjeda());
	}
	svi.push_back(dealer.getbrPobjeda());
	int maksi = *std::max_element(svi.begin(), svi.end());
	auto dis = std::distance(svi.begin(), std::max_element(svi.begin(), svi.end()));
	if (dis == 5)
	{
		std::cout <<std::endl<< "The winner is " << dealer.getName() << " with " << dealer.getbrPobjeda() << " collective wins";
	}
	else {
		std::cout << std::endl << "The winner is " << players.at(dis).getName() << " with " << players.at(dis).getbrPobjeda() << " collective wins";
	}
		 
}