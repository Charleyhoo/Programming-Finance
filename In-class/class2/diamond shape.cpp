// Name: Chang Huang
#include <iostream>
using namespace std;

int main()
{
int row, column;
int length;
cout << "Input the length: ";
cin >> length;

if (length%2==0)
{
    cout << "It is a even number, please try a odd number"<<endl;
}
else{

int mid = (length - 1) / 2;
int L= mid;
int R= mid;

    for (int row = 0; row < length; row++)
    {
        for (int column = 0; column < length; column++)
        {
            if (L == column)
            {
                cout << "*";
            }
            else if (R == column)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
        if (L == 0)
        {
            R += L;
            R = R + L;
            L = R + L;
            R = R - L;
        }
        L--;
        R++;
    }
    return 0;
}
}