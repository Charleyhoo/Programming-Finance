// IntegerSet.cpp
// Member-function definitions for class IntegerSet.
#include <iostream>
#include <iomanip>
using namespace std;
/* Write include directive for IntegerSet.h here */
#include "IntegerSet.h"
// constructor
IntegerSet::IntegerSet(int array[], int size)
    : set(setSize)

{
    for (int i = 0; i < 101; i++)
        insertElement(array[i]);
    //set[i] = 0;
} // end IntegerSet constructor
/*IntegerSet::IntegerSet(int set[101]) // notice: defination is extern
{
    for (int i = 0; i < 101; i++)
    {
        if (validEntry(i))
        {
            set[i] = 1;
        }
        else
        {
            set[i] = 0;
        }
    }
}
*/
// input a set from the user
void IntegerSet::inputSet()
{
    int number;
    do
    {
        cout << "Enter an element (-1 to end): ";
        cin >> number;
        if (validEntry(number))
            set[number] = true;
        else if (number != -1)
            cout << "Invalid Element\n";
    } while (number != -1); // end do...while
    cout << "Entry complete\n";
} // end function inputSet
// prints the set to the output stream
void IntegerSet::printSet() const
{
    int x = 1;
    bool empty = true;
    cout << "{ ";
    for (int u = 0; u < setSize; u++)
        if (set[u])
        {

            cout << u << (x % 10 == 0 ? "\n" : "");
            empty = false;
            x++;
        }
    if (empty)
        cout << setw(4) << "----";
    cout << setw(4) << "}"
         << "\n";
}
// end function printSet
/* Write definition for unionOfSets */
IntegerSet IntegerSet::unionOfSets(const IntegerSet &mySet) const
{
    IntegerSet temp;
    for (int i = 0; i < setSize; i++)
    
        temp.set[i] = set[i] || mySet.set[i];
        return temp;
    
}
/* Write definition for intersectionOfSets */
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet &mySet) const
{
    IntegerSet temp;
    // if element is in both sets, add to temporary set
    for (int i = 0; i < 101; i++)
    
        temp.set[i] = set[i] && mySet.set[i];
        return temp;
    
}

void IntegerSet::insertElement( int k )
{
   if ( validEntry( k ) )
      set[ k ] = true;
   else
      cout << "Invalid insert attempted!\n";
} // end function insertElement

