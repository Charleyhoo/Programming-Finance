#pragma once
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

class DoubleLinkedList
{
	friend class StockAccount;

public:
	DoubleLinkedList();
	~DoubleLinkedList();

	void sort();					   // sort the list
	Node *findPosition(int pos) const; // find the position
	void insertNode(Node *);		   // insert the node
	Node *findName(string name);	   // find the name
	void deleteNode(string);		   // delete the node
	void printList();				   // print the list
	void swap(Node *, Node *);		   // swap the node
	bool isNode(string);			   // tell if node
	Node *getNode(string);			   // get node
	Node *getHead();				   // get the head name
	int getSize();					   // get the size of list
private:
	Node *pHead;
	Node *pTail;
	int listLength;
};
#endif 
