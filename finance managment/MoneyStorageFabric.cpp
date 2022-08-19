#include "MoneyStorageFabric.h"

std::string MoneyStorageFabric::numberGenerator(int type)
{
    std::string begin = type == 1 ? "5300" : type == 2 ? "2323" : "9500";
    
    for (int i = 0; i < 12; ++i)
    {
        int part = rand() % 10;
        if (!(i % 4)) begin += " ";
        begin += std::to_string(part);
    }
    return begin;
}

MoneyStorage* MoneyStorageFabric::createDebetCard()
{
    std::string number = numberGenerator(1);
    int ballance = 0;
    return new DebetCard(number, ballance);
}

MoneyStorage* MoneyStorageFabric::createCreditCard()
{
    std::string number = numberGenerator(2);
    int ballance = 50000;
    return new CreditCard(number, ballance);
}

MoneyStorage* MoneyStorageFabric::createWallet()
{
    std::string number = numberGenerator(3);
    int ballance = 0;
    return new Wallet(number, ballance);
}
