#include "MoneyStorage.h"
#include <ctime>
#pragma once

class MoneyStorageFabric
{
	std::string numberGenerator(int type);

public:
	MoneyStorage* createDebetCard();
	MoneyStorage* createCreditCard();
	MoneyStorage* createWallet();
};

