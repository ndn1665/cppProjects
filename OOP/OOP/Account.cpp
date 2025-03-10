#include "Account.h"
#include "BankingCommonDecl.h"

Account::Account(int incdnum, char* inname, int inmoney)
	:creditNum(incdnum), money(inmoney)
{
	name = new char[strlen(inname) + 1];
	strcpy(name, inname);
};

Account::Account(const Account& copy)
	:creditNum(copy.creditNum), money(copy.money)
{
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
}

void Account::operator=(const Account& ref)
{
	creditNum = ref.creditNum;
	money = ref.money;
	delete[]name;
	name = new char[strlen(ref.name) + 1];
	strcpy(name, ref.name);
}



void Account::Deposit(int depositMoney)
{
	money += depositMoney;
}
	
int Account::Withdraw(int withdrawMoney)
{
	if (money < withdrawMoney)
	{
		return 0;
	}
	money -= withdrawMoney;
	return money;
}

int Account::GetCreditNum() const
{
	return creditNum;
}
	
int Account::GetMoney() const
{
	return money;
}
	
void Account::showAll() const
{
	cout << creditNum << endl;
	cout << name << endl;
	cout << GetMoney() << endl;
}

Account::~Account() {};