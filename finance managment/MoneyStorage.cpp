#include "MoneyStorage.h"

int MoneyStorage::getType()
{
	return type;
}

int MoneyStorage::getBallance()
{
	return ballance;
}

std::string MoneyStorage::getNumber()
{
	return number;
}

void MoneyStorage::setNumber(std::string number)
{
	this->number = number;
}

void MoneyStorage::setBallance(int ballance)
{
	this->ballance = ballance;
}

void MoneyStorage::setType(int type)
{
	this->type = type;
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

DebetCard::DebetCard(std::string  number, int ballance)
{
	type = 1;
	this->ballance = ballance;
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

Wallet::Wallet(std::string  number, int ballance)
{
	type = 3;
	this->ballance = ballance;
	this->number = number;
}

bool Wallet::spend(int sum)
{
	if (sum > ballance) return false;
	ballance -= sum;
	return true;
}

CreditCard::CreditCard(std::string number, int ballance)
{
	comission = 2;
	type = 2;
	this->ballance = ballance;
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
