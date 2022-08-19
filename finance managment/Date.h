#pragma once
#include <string>

class Date
{
private:
	enum { Juniuary = 1, February, March, April, May, June, July, August, September, October, November, December };
	bool isLeapYear(int year);
	
public:
	std::string getDateThroughXDays(int days, std::string date);
	std::string dateTransformer(int date);
	int dateTransformer(std::string date);
	int getDays(int month, int year);
};

