#pragma once
#include <iostream>
#include <string>
class MoneyStorage
{
protected:
	std::string number;
	int ballance = 0;
	int type = 0;
public:
	int getType();
	void addMoney(int sum);
	virtual bool cash(int sum);
	virtual bool spend(int sum) = 0;
	virtual int calcComission(int sum);
	friend std::ostream& operator << (std::ostream& out, const MoneyStorage& instance);
};

class DebetCard : public MoneyStorage
{
public:
	DebetCard(std::string number);
	bool cash(int sum) override;
	bool spend(int sum) override;
};

class Wallet : public MoneyStorage
{
public:
	Wallet(std::string number);
	bool spend(int sum) override;
};

class CreditCard : public MoneyStorage
{
private:
	int comission;

public:
	CreditCard(std::string number);
	bool cash(int sum) override;
	bool spend(int sum) override;
	int calcComission(int sum) override;
};