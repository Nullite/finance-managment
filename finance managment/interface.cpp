#include "interface.h"

void Interface::displayReport(int duration, int date, std::vector<std::vector<int>> report)
{
    Categories categories;
    Date dateController;
    std::string dateStr = dateController.dateTransformer(date);
    if (duration == 1) std::cout << "Your expenses by category for " << dateController.dateTransformer(date) << ":\n";
    else if (duration == 2)
    {
        std::string dateFrom = dateStr;
        std::string dateTo = dateController.getDateThroughXDays(6, dateFrom);
        std::cout << "Your expenses by category for " << dateFrom << " - " << dateTo << ":\n";
    }

    else if (duration == 3)
    {
        int month = std::stoi(dateController.dateTransformer(date).erase(0, 3).erase(2, dateStr.length() - 1));
        int year = std::stoi(dateController.dateTransformer(date).erase(0, 6));
        std::string lastDayofTheMonth = std::to_string(dateController.getDays(month, year));
        std::string dateFrom = dateController.dateTransformer(date);
        dateFrom.replace(dateFrom.begin(), dateFrom.begin() + 2, "01");
        std::string dateTo = dateController.dateTransformer(date);
        dateTo.replace(dateTo.begin(), dateTo.begin() + 2, lastDayofTheMonth);
        std::cout << "Your expenses by category for " << dateFrom << " - " << dateTo << ":\n";
    }
    for (std::vector<int> category : report)
    {
        std::cout << '\n' << "Category: " << categories.getCategory(category.at(0)) << '\n' << "Expenses: " << category.at(1) << "\n\n";
    }
}

void Interface::displayTop3WeekSpends(int date, std::vector<std::vector<int>> raiting)
{
    Categories categories;
    Date dateController;

    std::string dateFrom = dateController.dateTransformer(date);
    std::string dateTo = dateController.getDateThroughXDays(6, dateFrom);

    std::cout << "Top 3 max spends from " << dateFrom << " to " << dateTo << ":\n";

    for (std::vector<int> expence : raiting)
    {
        std::string date = dateController.dateTransformer(expence.at(2));
        std::string category = categories.getCategory(expence.at(0));
        int spend = expence.at(1);
        std::cout << "Date: " << date << '\n' << category << ": " << spend << "\n\n";
    }
}

void Interface::displayCategories(std::vector<std::vector<int>> expences)
{
    Categories categories;
    for (std::vector<int> expence : expences)
    {
        std::string date = std::to_string(expence.at(2));
        if (date.size() == 7) date.insert(0, "0");
        date.insert(2, ".");
        date.insert(5, ".");
        std::string category = categories.getCategory(expence.at(0));
        int spend = expence.at(1);
        std::cout << "Date: " << date << '\n' << category << ": " << spend << "\n\n";
    }
}
