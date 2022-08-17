#pragma once
#include "MoneyStorage.h"
#include <ctime>
class MoneyStorageFabric
{
	std::string numberGenerator(int type);

public:
	MoneyStorage* createDebetCard();
	MoneyStorage* createCreditCard();
	MoneyStorage* createWallet();
};

