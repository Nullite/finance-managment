#pragma once
#include <string>

class Date
{
private:
	enum { Juniuary = 1, February, March, April, May, June, July, August, September, October, November, December };
	bool isLeapYear(int year);
	int getDays(int month, int year);
public:
	std::string getDateThroughXDays(int days, std::string date);
};

