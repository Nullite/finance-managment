#include <vector>
#include <fstream>
#include<string>
#include "MoneyStorageFabric.h"
#pragma once
class SaveManager
{
public:
	SaveManager(std::vector<std::vector<int>>& expences, std::vector<MoneyStorage*>& cards);
	void saveExpences(std::vector<std::vector<int>> expences);
	void saveCards(std::vector<MoneyStorage*> cards);
};

