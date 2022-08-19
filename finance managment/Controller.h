#include "Reports.h"
#include "interface.h"
#include "SaveManager.h"
#pragma once


class Controller
{
	MoneyStorageFabric* fabric;
	Reports* reportMaker;
	Interface* interFace;
	SaveManager* saveManager;
	std::vector<MoneyStorage*> cards;
	Controller(); 
public:
	static Controller& getInstance();
    void addCard(int type);
	void cardList();
	void addMoney(int index, int sum);
	bool cash(int sum, int index, int date);
	bool spend(int sum, int index, int date, int category);
	void report(int date, int duration);
	void spendsRaiting(int date, int duration);
	void categoriesList();
	void saveExpences();
	void saveCards();
};

