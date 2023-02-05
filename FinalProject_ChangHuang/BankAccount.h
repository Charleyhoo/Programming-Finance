#pragma once
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#define BANK_FILE "bank_transaction_history.txt"
#include "BaseAccount.h"
#include "DoubleLinkedList.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <sstream>
using namespace std;

class BankAccount : public BaseAccount
{
public:
	// design pattern: singleton pattern
	// ensure there would only be one bank account at anytime.

	// get myaccount
	static BankAccount *Getaccount()
	{
		if (myaccount == NULL)
			myaccount = new BankAccount();
		return myaccount;
	}
	void Deposit(double money);						  // deposit
	void Withdraw(double money);					  // withdraw
	bool addhistory(double money, int history) const; // add transaction history
	void printHistory() const;						  // print transaction history

	// design pattern: template pattern
	void template_method();
	~BankAccount();
	// BankAccount();

private:
	// design pattern: singleton pattern
	BankAccount();
	static BankAccount *myaccount;
	static int a;
};
#endif
