#include "BankAccount.h"
#include <iostream>
using namespace std;

BankAccount::BankAccount()
{
	accountType = "BankAccount";
	initialize_transhistroy(accountType);
}

// design pattern: singleton pattern
// initialize the static pointer
BankAccount *BankAccount::myaccount = NULL;

void BankAccount::Deposit(double money)
{
	balance += money;
	renew_balancefile();
	addhistory(money, 1);
}

void BankAccount::Withdraw(double money)
{
	if (balance < money)
	{
		cout << "Error: money in your account less than " << fixed << money << " !" << endl;
	}
	else
	{
		balance -= money;
		renew_balancefile();
		addhistory(money, 2);
	}
}

// add new record to the history file.
bool BankAccount::addhistory(double money, int history) const
{
	string process = " ";
	switch (history)
	{
	case 1:
		process = "Deposit";
		break;
	case 2:
		process = "Withdraw";
		break;
	default:
		return false;
		break;
	}
	struct tm t;
	time_t nowTime;
	time(&nowTime);
	localtime_s(&t, &nowTime);

	stringstream ss1, ss2;
	ss1 << fixed << (setprecision(2)) << money;
	ss2 << fixed << (setprecision(2)) << balance;

	string timeString = to_string(t.tm_year + 1900) + "/" + to_string(t.tm_mon) + "/" + to_string(t.tm_mday);
	string moneyString = "$" + ss1.str();
	string balanceString = "$" + ss2.str();
	ofstream ofile(BANK_FILE, ios::app);
	ofile << left << setw(16) << process << setw(16) << moneyString << setw(16) << timeString << setw(16) << balanceString << endl;
	ofile.close();
	return true;
}

void BankAccount::printHistory() const
{
	cout << left << setw(20) << "Event" << setw(22) << "Amount" << setw(22) << "Date" << setw(22) << "Balance" << endl;
	printlines(BANK_FILE);
}

// design pattern: template pattern.
void BankAccount::template_method()
{
	if (!checkhistory(BANK_FILE))
	{
		create_newhistory(BANK_FILE);
	}
}

BankAccount::~BankAccount()
{
	myaccount = NULL;
}
