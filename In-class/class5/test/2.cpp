// IntegerSet.h
// Header file for class IntegerSet
#ifndef INTEGER_SET_H
#define INTEGER_SET_H

#include <vector>
using namespace std;

class IntegerSet
{
public:
    static const int setSize=101;
    IntegerSet();
        
    IntegerSet(int[], int);
    //static const int setSize = 101;

    /* Write a member funcion prototype for UnionOfSets */
    void inputSet(); // read values from user
    void printSet() const;
   void insertElement(int);
    IntegerSet unionOfSets(const IntegerSet &) const;
    IntegerSet intersectionOfSets(const IntegerSet &) const;

private:
    vector<bool> set;
    //int set[101]; // range of 0 - 100
    // determines a valid entry to the set
    int validEntry(int x) const
    {
        return (x >= 0 && x <= 100);
    } // end function validEntry
};

#endif