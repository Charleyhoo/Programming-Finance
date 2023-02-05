#pragma once
#ifndef BASEACCOUNT_H
#define BASEACCOUNT_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <sstream>
using namespace std;
// Abstract base class

class BaseAccount
{
public:
	double getbalance() const;									  // get balance
	void setbalance(double balance);							  // set balance
	void printlines(const char *fileName) const;				  // print lines.
	virtual bool addhistory(double money, int history) const = 0; // add transaction history
	bool checkhistory(const char *fileName) const;				  // check wheather a historyfile exist.
	void create_newhistory(const char *fileName);				  // create new history txt.
	void add_newhistory(char *fileName, string reocrd);			  // add new line at the end of the file.
	virtual void printHistory() const = 0;						  // print history
// design pattern: template method
	void initialize_transhistroy(const string accountType);		  // initialize transaction history file
	void renew_balancefile();									  // renew the balancefile
	BaseAccount();
	~BaseAccount();

protected:
	double balance;
	string accountType;
	virtual void template_method() = 0;
};
#endif