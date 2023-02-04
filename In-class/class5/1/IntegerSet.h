// Exercise 10.8 Solution: IntegerSet.h
// Header file for class IntegerSet
#ifndef INTEGER_SET_H
#define INTEGER_SET_H

#include <vector>
using namespace std;

class IntegerSet
{
public:
   static const int setSize = 101; // number of set elements

   // default constructor
   IntegerSet()
       : set(setSize)
   {
   } // end IntegerSet constructor

   IntegerSet(int[], int); // constructor that takes an initial set
   IntegerSet unionOfSets(const IntegerSet &) const;
   IntegerSet intersectionOfSets(const IntegerSet &) const;
   void inputSet(); // read values from user
   void insertElement(int);
   void deleteElement(int);
   void printSet() const;
   bool isEqualTo(const IntegerSet &) const;

private:
   vector<bool> set; // range of 0 - 100

   // determines a valid entry to the set
   int validEntry(int x) const
   {
      return (x >= 0 && x < setSize);
   } // end function validEntry
};   // end class IntegerSet

#endif