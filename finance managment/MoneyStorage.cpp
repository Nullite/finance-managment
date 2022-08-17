#include "MoneyStorage.h"

int MoneyStorage::getType()
{
	return type;
}

void MoneyStorage::addMoney(int sum)
{
	ballance += sum;
}

bool MoneyStorage::cash(int sum)
{
	return false;
}

int MoneyStorage::calcComission(int sum)
{
	return 0;
}

DebetCard::DebetCard(std::string  number)
{
	type = 1;
	ballance = 0;
	this->number = number;
}

bool DebetCard::cash(int sum)
{
	if (sum > ballance) return false;
	ballance -= sum;
	return true;
}

bool DebetCard::spend(int sum)
{
	if (sum > ballance) return false;
	ballance -= sum;
	return true;
}

Wallet::Wallet(std::string  number)
{
	type = 3;
	ballance = 0;
	this->number = number;
}

bool Wallet::spend(int sum)
{
	if (sum > ballance) return false;
	ballance -= sum;
	return true;
}

CreditCard::CreditCard(std::string number)
{
	comission = 2;
	type = 2;
	ballance = 50000;
	this->number = number;
}

bool CreditCard::cash(int sum)
{
	int comission = calcComission(sum);
	if (sum + comission > ballance) return false;
	ballance -= (sum + comission);
	return true;
}

bool CreditCard::spend(int sum)
{
	if (sum > ballance) return false;
	ballance -= sum;
	return true;
}

int CreditCard::calcComission(int sum)
{
	return sum / 100 * comission;
}

std::ostream& operator<<(std::ostream& out, const MoneyStorage& instance)
{
	std::string cardType = instance.type == 1 ? "Debet Card" : instance.type == 2 ? "Credit Card" : "Wallet";

	out << cardType << ":" << '\n' << "number: " << instance.number << "\n" << "ballance: " << instance.ballance << "\n\n\n";
	return out;
}
