#include "DoubleLinkedList.h"
#include <iostream>
using namespace std;

// Get the list 
DoubleLinkedList::DoubleLinkedList()
{
	this->listLength = 0;
	// set head and tail
	this->pHead = new Node("head", -1);
	this->pTail = new Node("tail", -1);
	pHead->next = pTail;
	pTail->pre = pHead;
}
DoubleLinkedList::~DoubleLinkedList()
{
	Node *pCur = pHead;
	while (pCur->next)
	{
		Node *pTemp = pCur;
		pCur = pCur->next;
		delete pTemp;
		pTemp = NULL;
	}
	pHead = NULL;
	pTail = NULL;
	listLength = 0;
}

// bubble sort
void DoubleLinkedList::sort()
{
}

Node *DoubleLinkedList::findPosition(int pos) const
{
	if (pos > listLength)
	{
		cout << "Error: wrong position" << endl;
		return nullptr;
	}
	else
	{
		Node *pTemp = pHead->next;
		for (int count = 1; count != pos; count++)
		{
			pTemp = pTemp->next;
			if (pTemp == pTail)
			{
				cout << "Error: get tail" << endl;
				break;
			}
		}
		return pTemp;
	}
}

// insert a node at the end of the list
void DoubleLinkedList::insertNode(Node *node)
{
	node->next = pTail;
	node->pre = pTail->pre;
	pTail->pre->next = node;
	pTail->pre = node;
	listLength++;
}

// find a stock by its name
Node *DoubleLinkedList::findName(string name)
{
	Node *pTemp = pHead;
	while (pTemp != pTail)
	{
		// cout << pTemp->stockName << endl;
		if (pTemp->stockName == name)
		{
			return pTemp;
		}
		pTemp = pTemp->next;
	}
	return nullptr;
}

// delete a node by its name
void DoubleLinkedList::deleteNode(string name)
{
	Node *pTemp = findName(name);
	if (pTemp == nullptr)
	{
		cout << "Error: Stock Not Found!" << endl;
	}
	else
	{
		pTemp->pre->next = pTemp->next;
		pTemp->next->pre = pTemp->pre;
		pTemp->next = NULL;
		pTemp->pre = NULL;
		delete pTemp;
		listLength--;
	}
}

// print the list
void DoubleLinkedList::printList()
{
	Node *pTemp = pHead->next;
	while (pTemp != pTail)
	{
		cout << "Stock: " << pTemp->stockName << " Num: " << pTemp->stockNum << endl;
		pTemp = pTemp->next;
	}
}

// swap the order of two nodes
void DoubleLinkedList::swap(Node *lp, Node *rp)
{
	if (lp->next == rp)
	{
		lp->pre->next = rp;
		lp->next = rp->next;

		rp->next->pre = lp;
		rp->pre = lp->pre;

		lp->pre = rp;
		rp->next = lp;
	}
	else if (lp->pre = rp)
	{
		rp->pre->next = lp;
		rp->next = lp->next;

		lp->next->pre = rp;
		lp->next = rp->pre;

		rp->pre = lp;
		lp->next = rp;
	}
	else
	{
		Node *pTemp = new Node("", 0);

		pTemp->next = lp->next;
		pTemp->pre = lp->pre;

		lp->pre->next = rp;
		lp->next->pre = rp;

		lp->pre = rp->pre;
		lp->next = rp->next;

		rp->pre->next = lp;
		rp->next->pre = lp;

		rp->next = pTemp->next;
		rp->pre = pTemp->pre;

		pTemp->next = NULL;
		pTemp->pre = NULL;
		delete pTemp;
	}
}

// find wheather a stock exist.
bool DoubleLinkedList::isNode(string name)
{
	Node *pTemp = pHead;
	while (pTemp->next != pTail)
	{
		if (pTemp->stockName == name)
		{
			return true;
		}
		pTemp = pTemp->next;
	}
	return false;
}

Node *DoubleLinkedList::getNode(string name)
{
	return findName(name);
}

Node *DoubleLinkedList::getHead()
{
	return pHead;
}

int DoubleLinkedList::getSize()
{
	return listLength;
}
