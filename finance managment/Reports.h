#include "Date.h"
#include "Categories.h"
#include <vector>
#pragma once
class Reports
{
private:
	std::vector<std::vector <int>> expences;

	int searchExpence(std::vector<int> compare, std::vector<std::vector<int>> _where);
	std::vector <std::vector <int>> dayReport(int day);
	std::vector<std::vector<int>> weekReport(int day);
	std::vector<std::vector<int>> weekSpends(int day);
	std::vector<std::vector<int>> monthReport(int day);
	std::vector<std::vector<int>> top3WeekSpends(int day);
	
public:
	void addExpence(std::vector<int> expence);
	std::vector<std::vector<int>> report(int date, int duration);
	std::vector<std::vector<int>> spendsRaiting(int date, int duration);
	std::vector<std::vector <int>> getExpences();
	void setExpences(std::vector<std::vector <int>> loadExpences);
};

