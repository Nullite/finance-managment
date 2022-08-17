#include "Controller.h"
Controller::Controller() 
{
    fabric = new MoneyStorageFabric;
}

int Controller::searchExpence(std::vector<int> compare, std::vector<std::vector<int>> _where)
{
    for (int i{ 0 }; i < _where.size(); ++i)
    {
        if (_where.at(i).at(0) == compare.at(0)) return i;
    }
    return -1;
}

std::string Controller::getCategory(int category)
{
    switch (category)
    {
    case CASH: return "Cash";
    case UTILITYBILLS: return "Utility bills";
    case CREDITS: return "Credits";
    case FOOD: return "Food";
    case AUTOMOBILE: return "Automobile";
    case ENTERTEIMENTS: return "Enterteiments";
    case EDUCATION: return "Education";
    case CLOTHES: return "Clothes";
    case RESTAURANTS: return "Restaurants";
    case PRESENTS: return "Presents";
    case  HOBBY: return "Hobby";
    case  APPLIANCES: return "Appliances";
    case OTHER: return "Other";       
    }
}

std::vector<std::vector<int>> Controller::dayReport(int day)
{
    std::vector<std::vector <int>> report;
    for (std::vector<int> expence : expences)
    {
        if (day == expence.at(2))
        {
            int category = expence.at(0);
            int index = searchExpence(expence, report);
            if (index != -1) report.at(index).at(0) += expence.at(0);
            else (report.push_back(expence));
        }   
    }
    return report;
}

std::string Controller::dateTransformer(int date)
{
    std::string dateStr = std::to_string(date);
    if (dateStr.size() == 7) dateStr.insert(0, "0");
    dateStr.insert(2, ".");
    dateStr.insert(5, ".");
    return dateStr;
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
    MoneyStorage* card = cards.at(index);
    int type = card->getType();
    if (type == 3) return false;
    if (type == 2)
    {
        if (!card->cash(sum)) return false;
        int comission = card->calcComission(sum);
        int category = CREDITS;
        std::vector<int> fee = { category, comission, date };
        expences.push_back(fee);
    }
    else if (!card->cash(sum)) return false;

    std::vector<int> cashWithdrawal = { CASH, sum, date };
    expences.push_back(cashWithdrawal);
    return true;
}

void Controller::categoriesList()
{
    for (std::vector<int> expence : expences)
    {
        std::string date = std::to_string(expence.at(2));
        if (date.size() == 7) date.insert(0, "0");
        date.insert(2, ".");
        date.insert(5, ".");
        std::string category = getCategory(expence.at(0));
        int spend = expence.at(1);
        std::cout <<"Date: " << date <<'\n' << category << ": " << spend << "\n\n";
    }
}

void Controller::report(int date, int duration)
{
    std::vector<std::vector<int>> report;
    if (duration == 1) report = dayReport(date);
    for (std::vector<int> category : report)
    {
        std::cout <<"Date: " << dateTransformer(category.at(2))<< '\n' << "Category: " << getCategory(category.at(0)) << '\n' << "Expenses: " << category.at(1) << "\n\n";
    }
}
