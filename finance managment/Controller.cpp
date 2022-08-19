#include "Controller.h"
Controller::Controller() 
{
    std::vector<std::vector<int>> expences;
    std::vector<MoneyStorage*> oldCards;
    fabric = new MoneyStorageFabric;
    reportMaker = new Reports;
    interFace = new Interface;
    saveManager = new SaveManager(expences, oldCards);
    reportMaker->setExpences(expences);

    for (MoneyStorage* card : oldCards)
    {
        this->cards.push_back(card);
    }
}

Controller& Controller::getInstance()
{
        static Controller instance;
        return instance;
}

void Controller::addCard(int type)
{
    MoneyStorage* card = type == 1 ? fabric->createDebetCard() : type == 2 ? fabric->createCreditCard() : fabric->createWallet();
    cards.push_back(card);
}

void Controller::cardList()
{
    for (MoneyStorage* card : cards)
    {
        std::cout << *card;
    }
}

void Controller::addMoney(int index, int sum)
{
    if (!cards.size()) return;

    cards.at(index)->addMoney(sum);
}

bool Controller::cash(int sum, int index, int date)
{
    Categories categories;
    MoneyStorage* card = cards.at(index);
    int type = card->getType();
    if (type == 3) return false;
    if (type == 2)
    {
        if (!card->cash(sum)) return false;
        int comission = card->calcComission(sum);
        int category = categories.CREDITS;
        std::vector<int> fee = { category, comission, date };
        reportMaker->addExpence(fee);
    }
    else if (!card->cash(sum)) return false;

    std::vector<int> cashWithdrawal = { categories.CASH, sum, date };
    reportMaker->addExpence(cashWithdrawal);
    return true;
}

bool Controller::spend(int sum, int index, int date, int category)
{
    MoneyStorage* card = cards.at(index);  
    if (!card->spend(sum)) return false;
    std::vector<int> spend = { category, sum, date };
    reportMaker->addExpence(spend);
    return true;
}

void Controller::report(int date, int duration)
{
    std::vector<std::vector<int>> report = reportMaker->report(date, duration);
    interFace->displayReport(duration, date, report);
}

void Controller::spendsRaiting(int date, int duration)
{
    std::vector<std::vector<int>> spendsRaiting = reportMaker->spendsRaiting(date, duration);
    if (duration == 1) interFace->displayTop3WeekSpends(date, spendsRaiting);
}

void Controller::categoriesList()
{
    
    interFace->displayCategories(reportMaker->getExpences());
}

void Controller::saveExpences()
{
    saveManager->saveExpences(reportMaker->getExpences());
}

void Controller::saveCards()
{
    saveManager->saveCards(cards);
}
