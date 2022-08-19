#include "SaveManager.h"

SaveManager::SaveManager(std::vector<std::vector<int>>& expences, std::vector<MoneyStorage*>& cards)
{
	std::ifstream getExpences("saveExpences.fn");
	if (!getExpences.is_open())
	{
		std::ofstream create("saveExpences.fn");
		create.close();
	}

	while (getExpences.good())
	{
		std::string line;
		std::vector<int> part;
		std::getline(getExpences, line);
		if (line.empty()) break;
		int index = std::stoi(line);
		for (int i{ 0 }; i < index; ++i)
		{
			std::getline(getExpences, line);
			part.push_back(std::stoi(line));
		}
		expences.push_back(part);
	}
	getExpences.close();

	std::ifstream getCards("saveCards.fn");
	if (!getCards.is_open())
	{
		std::ofstream create("saveCards.fn");
		create.close();
	}

	while (getCards.good())
	{
		std::string line;
		std::string number;
		int ballance;
		int type;
		std::getline(getExpences, number);
		if (number == "") break;
		std::getline(getExpences, line);
		ballance = std::stoi(line);
		std::getline(getExpences, line);
		type = std::stoi(line);
		if (type == 1)
		{
			MoneyStorage* card = new DebetCard(number, ballance);
			cards.push_back(card);
		}
		else if (type == 2)
		{
			MoneyStorage* card = new CreditCard(number, ballance);
			cards.push_back(card);
		}
		else
		{
			MoneyStorage* card = new Wallet(number, ballance);
			cards.push_back(card);
		}

	}
	getExpences.close();

}

void SaveManager::saveExpences(std::vector<std::vector<int>> expences)
{
	std::ofstream file("saveExpences.fn");
	for (std::vector<int> instance : expences)
	{
		file << instance.size() << '\n' << instance.at(0) << "\n" << instance.at(1) << "\n" << instance.at(2) << "\n";
	}
	file.close();
}

void SaveManager::saveCards(std::vector<MoneyStorage*> cards)
{
		std::ofstream file("saveCards.fn");
		for (MoneyStorage* instance : cards)
		{
			file << instance->getNumber() << '\n' << instance->getBallance() << "\n" << instance->getType() << "\n";
		}
		file.close();
}
