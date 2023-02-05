#include <iostream>
#include <string>
#include "BankAccount.h"
#include "BankAccount_ChangHuang.cpp"
#include "StockAccount.h"
#include "StockAccount_ChangHuang.cpp"
#include "Node.h"
#include "Node_ChangHuang.cpp"
#include "DoubleLinkedList.h"
#include "DoubleLinkedList_ChangHuang.cpp"
#include "BaseAccount.h"
#include "BaseAccount_ChangHuang.cpp"
using namespace std;
int mainMenu();
int bankMenu();
int stockMenu();

int main()
{
	cout << endl << "Welcome to the Account Management System." << endl;
	int choice = mainMenu();
	while (choice != 3) {
		switch (choice) {
		case 1: {
			StockAccount myAccount;
			int stockchoice = stockMenu();
			while (stockchoice!=7)
			{
				switch (stockchoice) {
				case 1: {
					cout << "Please enter the stock symbol: ";
					string sName;
					cin >> sName;
					double result;
					result = myAccount.getStockPrice(sName);
					if (result != 0.0)
						cout << sName << " $" << result << endl;
					else
						cout << "Stock Not Found!" << endl;
					break;
				}
				case 2: {
					myAccount.printPortfolio();
					break;
				}
				case 3: {
					cout << "Please eneter the stock symbol you wish to purchase: ";
					string sName;
					int sNum;
					double sPrice;
					cin >> sName;
					cout << "Please enter the number of shares: ";
					cin >> sNum;
					cout << "Please enter the maximum amount you are willing to pay per share: ";
					cin >> sPrice;
					myAccount.doBuyStock(sName, sNum, sPrice);
					break;
				}
				case 4: {
					string sName;
					int sNum;
					double sPrice;
					cout << "Please eneter the stock symbol you wish to sell: ";
					cin >> sName;
					cout << "Please enter the number of shares: ";
					cin >> sNum;
					cout << "Please enter the maximum amount you are willing to sell per share: ";
					cin >> sPrice;
					myAccount.doSellStock(sName, sNum, sPrice);
					break;
				}
				case 5: {
					cout << "waiting" << endl;
					//myAccount.drawGraph();
					break;
				}
				case 6: {
					myAccount.printHistory();
					break;
				}
				case 7: {
					break;
				}
				default:break;
				}
				stockchoice = stockMenu();
			}
			break;
		}
		case 2:
		{
			BankAccount *myAccount=BankAccount::Getaccount();
			int bankchoice = bankMenu();
			while (bankchoice != 5) {
				switch (bankchoice) {
				case 1: {
					double result = myAccount->getbalance();
					cout << "You have $" << fixed << setprecision(2) << result << " in your bank account." << endl;
					break;
				}
				case 2: {
					cout << "Please select the amount you wish to deposit: $";
					double money = 0.0;
					cin >> money;
					myAccount->Deposit(money);
					break;
				}
				case 3: {
					cout << "Please select the amount you wish to withdraw: $";
					double money = 0.0;
					cin >> money;
					myAccount->Withdraw(money);
					break;
				}
				case 4: {
					myAccount->printHistory();
					break;
				}
				default:break;
				}
				bankchoice = bankMenu();
			}
			delete myAccount;
			break;
		}
		case 3:
			return 0;
			break;
		default:
			break;
		}
		choice = mainMenu();
	}
	return 0;
}

int mainMenu() {
	cout << endl;
	cout << "Please select an account to access:" << endl;
	cout << "1. Stock Portfolio Account" << endl;
	cout << "2. Bank Account" << endl;
	cout << "3. Exit" << endl << endl;
	cout << "Option:";
	int choice = 0;
	cin >> choice;
	return choice;
}

//print stock account menu
int stockMenu() {
	cout << endl << "Please select an option:" << endl;
	cout << "1. Display the price for a stock symbol" << endl;
	cout << "2. Displaythe currnet portfolio" << endl;
	cout << "3. Buy shares" << endl;
	cout << "4. Sell shares" << endl;
	cout << "5. View a graph for the port folio value" << endl;
	cout << "6. View transaction history" << endl;
	cout << "7. Return to previous menu" << endl;
	cout <<endl<< "Option:";
	int choice = 0;
	cin >> choice;
	return choice;
}

//print bank account menu
int bankMenu() {
	cout << endl;
	cout << "Please select an option:" << endl;
	cout << "1. View account balance" << endl;
	cout << "2. Deposit money" << endl;
	cout << "3. Withdraw money" << endl;
	cout << "4. Print out history" << endl;
	cout << "5. Return to previous menu" << endl << endl;
	cout << "Option:";
	int choice = 0;
	cin >> choice;
	return choice;
}
