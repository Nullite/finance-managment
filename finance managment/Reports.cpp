#include "Reports.h"

int Reports::searchExpence(std::vector<int> compare, std::vector<std::vector<int>> _where)
{
    for (int i{ 0 }; i < _where.size(); ++i)
    {
        if (_where.at(i).at(0) == compare.at(0)) return i;
    }
    return -1;
}

std::vector<std::vector<int>> Reports::dayReport(int day)
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

std::vector<std::vector<int>> Reports::weekReport(int day)
{
    Date dateController;
    std::vector<std::vector <int>> report;
    std::vector<int> dates;

    dates.push_back(day);

    for (int i{ 0 }; i < 6; ++i)
    {
        std::string dateStr = dateController.dateTransformer(day);
        std::string newDay = dateController.getDateThroughXDays(1, dateStr);
        day = dateController.dateTransformer(newDay);
        dates.push_back(day);
    }

    for (std::vector<int> expence : expences)
    {
        int date = expence.at(2);
        for (int i = 0; i < dates.size(); ++i)
        {
            if (date == dates.at(i))
            {
                int index = searchExpence(expence, report);
                if (index != -1) report.at(index).at(1) += expence.at(1);
                else (report.push_back(expence));
            }
        }
    }

    return report;
}

std::vector<std::vector<int>> Reports::weekSpends(int day)
{
    Date dateController;
    std::vector<std::vector <int>> report;
    std::vector<int> dates;

    dates.push_back(day);

    for (int i{ 0 }; i < 6; ++i)
    {
        std::string dateStr = dateController.dateTransformer(day);
        std::string newDay = dateController.getDateThroughXDays(1, dateStr);
        day = dateController.dateTransformer(newDay);
        dates.push_back(day);
    }

    for (std::vector<int> expence : expences)
    {
        int date = expence.at(2);
        for (int i = 0; i < dates.size(); ++i)
        {
            if (date == dates.at(i)) report.push_back(expence);
        }
    }

    return report;
}

std::vector<std::vector<int>> Reports::monthReport(int date)
{
    Date dateController;
    std::vector<std::vector <int>> report;

    int monthAndYear = std::stoi(dateController.dateTransformer(date).erase(0, 3).erase(2, 1));

    for (std::vector<int> expence : expences)
    {
        int compareMonthAndYear = std::stoi(dateController.dateTransformer(expence.at(2)).erase(0, 3).erase(2, 1));

        if (compareMonthAndYear == monthAndYear)
        {
            int index = searchExpence(expence, report);
            if (index != -1) report.at(index).at(1) += expence.at(1);
            else (report.push_back(expence));
        }
    }
    return report;
}

std::vector<std::vector<int>> Reports::top3WeekSpends(int date)
{
    std::vector<std::vector<int>> spends = weekSpends(date);
    std::vector<std::vector<int>> top;
    std::vector<int> top1Spend = spends.at(0);
    std::vector<int> top2Spend;
    std::vector<int> top3Spend;

    for (int i{ 1 }; i < spends.size(); ++i)
    {
        if (spends.at(i).at(1) > top1Spend.at(1))
        {
            if (!top2Spend.empty()) top3Spend = top2Spend;
            top2Spend = top1Spend;
            top1Spend = spends.at(i);
        }
        else if (!top2Spend.empty() && spends.at(i).at(1) > top2Spend.at(1))
        {
            if (!top2Spend.empty()) top3Spend = top2Spend;
            top2Spend = spends.at(i);
        }
        else if (!top3Spend.empty() && spends.at(i).at(1) > top3Spend.at(1))
        {
            top3Spend = spends.at(i);
        }
    }

    if (!top1Spend.empty()) top.push_back(top1Spend);
    if (!top2Spend.empty()) top.push_back(top2Spend);
    if (!top3Spend.empty()) top.push_back(top3Spend);

    return top;
}

void Reports::addExpence(std::vector<int> expence)
{
    expences.push_back(expence);
}

std::vector<std::vector<int>> Reports::report(int date, int duration)
{
    std::vector<std::vector<int>> report;
    if (duration == 1) report = dayReport(date);
    else if (duration == 2) report = weekReport(date);
    else if (duration == 3) report = monthReport(date);
    return report;
}

std::vector<std::vector<int>> Reports::spendsRaiting(int date, int duration)
{
    std::vector<std::vector<int>> raiting;
    if (duration == 1) raiting = top3WeekSpends(date);
    return raiting;
}

std::vector<std::vector<int>> Reports::getExpences()
{
    return expences;
}

void Reports::setExpences(std::vector<std::vector <int>> loadExpences)
{
    if (loadExpences.empty()) return;
    for (std::vector<int> instance : loadExpences)
    {
        if (instance.size() != 3) throw "incorrect data";
        expences.push_back(instance);
    }
}
