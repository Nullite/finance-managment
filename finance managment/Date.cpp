#include "Date.h"

bool Date::isLeapYear(int year)
{
	return  !(year % 4) && (year % 100) || !(year % 400);
}

int Date::getDays(int month, int year)
{
	switch (month)
	{
	case Juniuary: return 31;
	case February:
		if (isLeapYear(year)) return 29;
		else return 28;
	case March: return 31;
	case April: return 30;
	case May: return 31;
	case June: return 30;
	case July: return 31;
	case August: return 31;
	case September: return 30;
	case October: return 31;
	case November: return 30;
	case December: return 31;
	}
}

std::string Date::getDateThroughXDays(int days, std::string date)
{
	int day = std::stoi(date.substr(0, 2));
	int month = std::stoi(date.substr(3, 2));
	int year = std::stoi(date.substr(6, 4));

	int thisMonthDays = getDays(month, year);

	for (int i{ 0 }; i < days; ++i)
	{
		++day;

		if (day > thisMonthDays)
		{
			day = 1;
			++month;
			thisMonthDays = getDays(month, year);
		}

		if (month > 12)
		{
			month = 1;
			++year;
			day = 1;
			thisMonthDays = getDays(month, year);
		}
	}

	std::string newDay = std::to_string(day);
	if (newDay.size() == 1) newDay.insert(0, "0");

	std::string newMonth = std::to_string(month);
	if (newMonth.size() == 1) newMonth.insert(0, "0");

	return newDay + "." + newMonth + "." + std::to_string(year);
}

std::string Date::dateTransformer(int date)
{
	std::string dateStr = std::to_string(date);
	if (dateStr.size() == 7) dateStr.insert(0, "0");
	dateStr.insert(2, ".");
	dateStr.insert(5, ".");
	return dateStr;
}

int Date::dateTransformer(std::string date)
{
	date.erase(date.begin() + 2);
	date.erase(date.begin() + 4);
	return std::stoi(date);
}
