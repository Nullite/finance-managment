#pragma once
#include "MoneyStorageFabric.h"
#include "categories.h"
#include <Vector>

class Controller
{
	MoneyStorageFabric* fabric;
	std::vector<MoneyStorage*> cards;
	std::vector<std::vector <int>> expences;
	Controller();
	int searchExpence(std::vector<int> compare, std::vector<std::vector<int>> _where);
	std::string getCategory(int category);
	std::vector <std::vector <int>> dayReport(int day);
	std::string dateTransformer(int date);
  
public:
	static Controller& getInstance();
    void addCard(int type);
	void cardList();
	void addMoney(int index, int sum);
	bool cash(int sum, int index, int date);
	void categoriesList();
	void report(int date, int duration);
};

