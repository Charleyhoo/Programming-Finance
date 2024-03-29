#include "StockAccount.h"
#include <iostream>
using namespace std;

StockAccount::StockAccount()
{
	accountType = "STOCKACCOUNT";
	initialize_transhistroy(accountType);
	if (!checkhistory(PORTFOLIO_FILE))
	{
		create_newhistory(PORTFOLIO_FILE);
	}
	else
	{
		getPortfolio();
		updateStockPrice();
	}
}

// search a stock's price by the result file
double StockAccount::getStockPrice(string stockName)
{
	double result = 0.0;
	ifstream ifile;
	srand(time(0));
	int randNum = rand() % 2;
	switch (randNum)
	{
	case 0:
	{
		ifile.open(RESULT_FILE1);
		if (ifile.fail())
		{
			cout << "Error: cannot open Result_1.txt" << endl;
			return 0.0;
		}
		break;
	}
	case 1:
	{
		ifile.open(RESULT_FILE2);
		if (ifile.fail())
		{
			cout << "Error: cannot open Result_2.txt" << endl;
			return 0.0;
		}
		break;
	}
	default:
		cout << "Error: wrong rand!" << endl;
		return 0.0;
		break;
	}

	string lineResult = "";
	string findLine = "";
	while (getline(ifile, lineResult))
	{
		if (splitLine(lineResult, 1) == stockName)
		{
			findLine = lineResult;
			break;
		}
	}
	if (findLine == "")
	{
		cout << "Error: cannot find price!" << endl;
		return 0.0;
	}
	else
	{
		result = atof(splitLine(findLine, 2).c_str());
		return result;
	}

	return result;
}

// print one stock's price
void StockAccount::printStockPrice(string sName)
{
	double result = getStockPrice(sName);
	if (result == 0.0)
	{
		cout << "Error: rong stock name!" << endl;
	}
	else
	{
		cout << left << setw(16) << "Company Symbol" << setw(16) << "Price per share" << endl;
		cout << setw(16) << sName << "$" << setw(15) << fixed << setprecision(2) << result << endl;
	}
}

// get portfolio from PORTOLIO_FILE
void StockAccount::getPortfolio()
{
	ifstream ifile;
	ifile.open(PORTFOLIO_FILE);
	if (ifile.fail())
	{
		cout << "Error: cannot open portfolio_record.txt" << endl;
	}
	else
	{
		string line;
		while (getline(ifile, line))
		{
			string sName = splitLine(line, 1);
			int sNum = atoi(splitLine(line, 2).c_str());
			Node *node = new Node(sName, sNum);
			PFList.insertNode(node);
		}
	}
}

// print the whole portfolio
void StockAccount::printPortfolio()
{
	cout << endl
		 << "Cash balance = $" << fixed << setprecision(2) << balance << endl;
	cout << left << setw(16) << "Company-Symbol" << setw(10) << "Number" << setw(20) << "Price-per-share" << setw(16) << "Total Value" << endl;
	Node *pTemp = PFList.getHead()->next;
	if (PFList.getSize() == 0)
	{
		cout << "Portfolio list empty" << endl;
	}
	while (pTemp != PFList.pTail)
	{

		cout << left << setw(18) << pTemp->stockName << setw(18)
			 << pTemp->stockNum << "$" << setw(20) << pTemp->getPrice()
			 << "$" << setw(20) << pTemp->getNum() * pTemp->getPrice() << endl;
		pTemp = pTemp->next;
	}
	cout << "Total portfolio value: $" << fixed << setprecision(2) << balance + portfolioAmout << endl;
}

// update all the stockprice in the PFLIST;
void StockAccount::updateStockPrice()
{
	Node *pTemp = PFList.getHead()->next;
	double newAmount = 0.0;
	while (pTemp != PFList.pTail)
	{
		double sPrice = 0.0;
		sPrice = getStockPrice(pTemp->getName());
		if (sPrice != 0.0 && pTemp->getNum() > 0)
		{
			pTemp->setPrice(sPrice);
			newAmount += sPrice * pTemp->getNum();
		}
		pTemp = pTemp->next;
	}
	portfolioAmout = newAmount;
	add_PortfolioHistory();
	sortPortfolio();
}

// use bubble sort to sort the list
void StockAccount::sortPortfolio()
{
	for (int i = 1; i <= PFList.getSize(); i++)
	{
		for (int j = i; j <= PFList.getSize(); j++)
		{
			Node *point1 = PFList.findPosition(i);
			Node *point2 = PFList.findPosition(j);
			if (point1->getPrice() * point1->getNum() < point2->getNum() * point2->getPrice())
			{
				PFList.swap(point1, point2);
			}
		}
	}
}

// add new portfolio_amount to the end of portfolio history.
void StockAccount::add_PortfolioHistory()
{

	if (!checkhistory(PORTFOLIO_VALUE_HISTORY))
	{
		create_newhistory(PORTFOLIO_VALUE_HISTORY);
	}
	ofstream ofile(PORTFOLIO_VALUE_HISTORY, ios::app);

	struct tm t;
	time_t nowTime;
	time(&nowTime);
	localtime_s(&t, &nowTime);

	time_t seconds;
	seconds = time(NULL);

	// tm* timeinfo;
	// timeinfo = localtime(&seconds);

	ofile << balance << "\t" << portfolioAmout << "\t" << seconds << endl;
	ofile.close();
}

// renew the account's portfolio
void StockAccount::renew_Portfolio()
{
	// init the PORFOLIO_FILE
	if (!checkhistory(PORTFOLIO_FILE))
	{
		create_newhistory(PORTFOLIO_FILE);
	}
	else
	{
		ofstream ofile;
		ofile.open(PORTFOLIO_FILE);
		{
			if (ofile.fail())
			{
				cout << "Error: cannot open " << PORTFOLIO_FILE << endl;
			}
			else
			{
				ofile << "";
				ofile.close();
			}
		}
	}

	ofstream ofile;
	ofile.open(PORTFOLIO_FILE);
	Node *pTemp = PFList.getHead()->next;
	while (pTemp != PFList.pTail)
	{
		ofile << pTemp->getName() << "\t" << pTemp->getNum() << "\n";
		pTemp = pTemp->next;
	}
}

string StockAccount::splitLine(string line, int pos) const
{
	stringstream ss(line);
	string partOfLine;
	for (int i = 0; getline(ss, partOfLine, '\t') && ((++i) != pos);)
	{
	}
	return partOfLine;
}

// sell stock
bool StockAccount::doSellStock(string sName, int sNum, double sPrice)
{
	Node *pStock = PFList.findName(sName);
	if (pStock == nullptr)
	{
		cout << "Sell Stock Failed: doesn't own this stock." << endl;
		return false;
	}
	double curPrice = getStockPrice(sName);
	if (curPrice <= 0.0)
	{
		cout << "Error: cannot find stock " << sName << " in result.txt !" << endl;
		return false;
	}
	if (sNum > pStock->getNum())
	{
		cout << "Sell Stock Failed: you do not have enough share." << endl;
		return false;
	}
	if (curPrice < sPrice)
	{
		cout << "Sell Stock Failed: current price of stock is lower than the price you want." << endl;
		return false;
	}
	if (sNum == pStock->getNum())
	{
		PFList.deleteNode(pStock->getName());
	}
	else
	{
		pStock->setNum(pStock->getNum() - sNum);
	}
	updateStockPrice();
	doDeposit(sNum * sPrice);
	addHistory(sName, sNum, sPrice, 2);
	renew_Portfolio();
	cout << "You have selled " << sNum << " shares of " << sName << " at $" << fixed << setprecision(2) << sPrice << " each for a total of $" << fixed << setprecision(2) << sNum * sPrice << "." << endl;
	return true;
}

// buy stock
bool StockAccount::doBuyStock(string sName, int sNum, double sPrice)
{

	double curPrice = getStockPrice(sName);

	if (curPrice <= 0.0)
	{
		cout << "Error: cannot find stock " << sName << " in result.txt !" << endl;
		return false;
	}

	if (curPrice > sPrice)
	{
		cout << "Buy Stock Failed: current price of stock is higher than the price you want." << endl;
		return false;
	}
	if (sNum * sPrice > balance)
	{
		cout << "Buy Stock Failed: not enough balance in your account." << endl;
		return false;
	}

	Node *pStock = PFList.findName(sName);
	if (pStock == nullptr)
	{
		pStock = new Node(sName, sNum);
		PFList.insertNode(pStock);
	}
	else
	{
		pStock->setNum(pStock->getNum() + sNum);
	}

	updateStockPrice();
	renew_Portfolio();
	doWithdraw(sNum * sPrice);

	addHistory(sName, sNum, sPrice, 1);
	cout << "You have Purchased " << sNum << " shares of " << sName << " at $" << fixed << setprecision(2) << sPrice << " each for a total of $" << fixed << setprecision(2) << sNum * sPrice << "." << endl;
	return true;
}

// do deposit when sell a stock
void StockAccount::doDeposit(double money)
{
	balance += money;
	renew_balancefile();
	addhistory(money, 1);
}

// do withdrawal when buy a stock
void StockAccount::doWithdraw(double money)
{
	if (balance < money)
	{
		cout << endl
			 << "Error: money in your account less than " << money << " !" << endl
			 << endl;
	}
	else
	{
		balance -= money;
		renew_balancefile();
		addhistory(money, 2);
	}
}

// add new record to the bank account history file.
bool StockAccount::addHistory(string sName, int sNum, double sPrice, int mode) const
{
	string process = "";
	switch (mode)
	{
	case 1:
		process = "Buy";
		break;
	case 2:
		process = "Sell";
		break;
	default:
		return false;
		break;
	}
	struct tm t;
	time_t nowTime;
	time(&nowTime);
	localtime_s(&t, &nowTime);

	stringstream ss1;
	ss1 << fixed << (setprecision(2)) << sNum * sPrice;
	string min = "00";

	if (to_string(t.tm_min) == "0")
	{
		min = "00";
	}
	else
	{
		min = to_string(t.tm_min);
	}

	char timeStr[40];
	strftime(timeStr, 50, "%X", &t);
	string amountStr = "$" + ss1.str();
	ofstream ofile(STOCK_HISTORY_FILE, ios::app);
	ofile << left << setw(16) << process << setw(16) << sName << setw(10) << sNum << "$" << setw(15) << sPrice << setw(16) << amountStr << setw(16) << timeStr << endl;
	;
	ofile.close();
	return true;
}

// overload addHistory
bool StockAccount::addhistory(double money, int history) const
{
	string process = "";
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

	string timeStr = to_string(t.tm_year + 1900) + "/" + to_string(t.tm_mon) + "/" + to_string(t.tm_mday);
	string moneyStr = "$" + ss1.str();
	string balanceStr = "$" + ss2.str();
	ofstream ofile(BANK_FILE, ios::app);
	ofile << left << setw(16) << process << setw(16) << moneyStr << setw(16) << timeStr << setw(16) << balanceStr << endl;
	ofile.close();
	return true;
}

void StockAccount::printHistory() const
{
	cout << left << setw(16) << "Event" << setw(16) << "CompanySymbol" << setw(10) << "Number" << setw(16) << "PricePerShare" << setw(16) << "TotalValue" << setw(16) << "Time" << endl;
	printlines(STOCK_HISTORY_FILE);
}

// design pattern: template pattern.
void StockAccount::template_method()
{
	if (!checkhistory(STOCK_HISTORY_FILE))
	{
		create_newhistory(STOCK_HISTORY_FILE);
	}
}

StockAccount::~StockAccount()
{
	// updateStockPrice();
}
