#pragma once
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
using namespace std;

class Node
{
	friend class DoubleLinkedList;
	friend class StockAccount;

public:
	Node(string Name, int Num) : 
	stockName(Name), stockNum(Num), stockPrice(0.0), pre(NULL), next(NULL)
	{
	}
	void setPrice(double); // set price
	void setNum(int);	   // set number
	void setName(string);  // set name
	string getName();	   // get name
	double getPrice();	   // get price
	int getNum();		   // get number
	~Node();

private:
	Node *pre;
	Node *next;
	string stockName;
	double stockPrice;
	int stockNum;
};
#endif
