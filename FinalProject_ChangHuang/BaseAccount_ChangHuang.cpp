#include "BaseAccount.h"
#include <iostream>
using namespace std;
// get balance
BaseAccount::BaseAccount()
{
	if (checkhistory("Account_balance.txt"))
	{
		ifstream ifile;
		ifile.open("Account_balance.txt");
		string record;
		if (getline(ifile, record))
		{
			istringstream iss(record);
			iss >> balance;
		}
	}
	else
	{
		balance = 10000;
		renew_balancefile();
	}
}

void BaseAccount::renew_balancefile()
{
	stringstream ss;
	ss << balance;
	string newBalance = ss.str();
	if (checkhistory("Account_balance.txt"))
	{
		ofstream ofile;
		ofile.open("Account_balance.txt");
		ofile << newBalance;
		ofile.close();
		return;
	}
	else
	{
		create_newhistory("Account_balance.txt");
		ofstream ofile;
		ofile.open("Account_balance.txt");
		ofile << newBalance;
		ofile.close();
		return;
	}
}

// set balance
void BaseAccount::setbalance(double balance)
{
	this->balance = balance;
}

// get balance
double BaseAccount::getbalance() const
{
	return this->balance;
}

//Design Pattern: template pattern.
//method in abstract class.
void BaseAccount::initialize_transhistroy(const string accountType)
{
	this->template_method();
}
//check history
bool BaseAccount::checkhistory(const char *fileName) const
{
	ifstream ifile(fileName);
	if (!ifile)
	{
		ifile.close();
		return false;
	}
	else
		return true;
	return false;
}

// create new history file
void BaseAccount::create_newhistory(const char *fileName)
{
	// const char*fileName = file.c_str();
	FILE *fp = NULL;
	errno_t err = 0;
	err = fopen_s(&fp, fileName, "w+");
	if (!err)
	{
		fclose(fp);
	}
}
//add new record in history
void BaseAccount::add_newhistory(char *fileName, string record)
{
	ofstream ofile;
	ofile.open(fileName, ios::app); // mode of open
	if (ofile.fail())
	{
		cout << "Fail when open " << fileName << endl;
		return;
	}
	else
	{
		ofile << record;
		ofile.close();
		return;
	}
}
BaseAccount::~BaseAccount()
{
}
//print history lines
void BaseAccount::printlines(const char *fileName) const
{
	ifstream ifile;
	ifile.open(fileName);
	string line;
	while (getline(ifile, line))
	{
		cout << line << endl;
	}
	ifile.close();
}
