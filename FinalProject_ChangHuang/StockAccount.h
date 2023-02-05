#pragma once
#ifndef STOCKACCOUNT_H
#define STOCKACCOUNT_H

#include <iostream>
#include "BaseAccount.h"
#include "DoubleLinkedList.h"
#include <fstream>
#include <time.h>
#define STOCK_HISTORY_FILE "stock_transaction_history.txt"
#define RESULT_FILE1 ".\\Result_1.txt"
#define RESULT_FILE2 ".\\Result_2.txt"
#define PORTFOLIO_FILE "portfolio_record.txt"
#define PORTFOLIO_VALUE_HISTORY "portfolio_value_history.txt"
#define BANK_FILE "bank_transaction_history.txt"
using namespace std;

// BankTransactionHistory.txt will store the history
class StockAccount : public BaseAccount
{

public:
	StockAccount();
	double getStockPrice(string stockName); // get the stock price
	void printStockPrice(string sName);		// print the stock price
	void getPortfolio();					// display the portfolio
	void printPortfolio();					// print the portfolio
	void updateStockPrice();				// update the stock price
	void sortPortfolio();					// sort th portfolio list
	void add_PortfolioHistory();			// add the portfolio history
	void renew_Portfolio();					// renew the portfolio
	string splitLine(string line, int pos) const;

	// sell and buy stock
	bool doSellStock(string sName, int sNum, double sPrice);
	bool doBuyStock(string sName, int sNum, double sPrice);

	// get stocks's price and name
	void doDeposit(double money); // do deposit
	void doWithdraw(double money);
	bool addHistory(string sName, int sNum, double sPrice, int mode) const;

	// withdraw the implement
	virtual bool addhistory(double money, int history) const; // add transaction history
	void printHistory() const;
	virtual void template_method();

	// print transaction history
	void drawGraph();
	int countLines();
	~StockAccount();

private:
	double portfolioAmout;
	DoubleLinkedList PFList; // portfolio double linked list
};
#endif
