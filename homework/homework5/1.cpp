//Chang Huang
//Mon Oct.10 4:15PM
#include <iostream>
#include <vector>
using namespace std;

void square(int parameter);

int main()
{
    int parameter;
    cout << "Put a positive integer parameter n: " << endl;
    cin >> parameter;

    cout << "On input " << parameter << ", it should print:  " << endl;
    square(parameter);
    

    return 0;
}

void square(int parameter)
{

    // judge the parameter is odd/even number
    if (parameter % 2 == 1) // odd number
    {
        // create next sequence odd/even numbers depend on parameter

        if (parameter == 1)
        {
            cout << "1,";
        }
        /*else if (parameter==0)
        {}*/
        else
        {
            cout << parameter * parameter << ",";
            square(parameter - 2);
            cout << (parameter - 1) * (parameter - 1) << ",";
            
        }
    }
    else // even number
    {
        if (parameter == 1)
        {
            cout << "1,";
        }
        /*else if (parameter==0)
        {}*/
        else
        {
            cout << (parameter - 1) * (parameter - 1) << ",";
            square(parameter - 2);
            cout << parameter * parameter << "," ; //notice: no "endl" 
        }
    }
}