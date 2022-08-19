#include "Date.h"
#include "Categories.h"
#include <iostream>
#include <vector>
#pragma once

class Interface
{
public:
	void displayReport(int duration, int date, std::vector<std::vector<int>> report);
	void displayTop3WeekSpends(int date, std::vector<std::vector<int>> raiting);
	void displayCategories(std::vector<std::vector<int>> expences);
};