#include <iostream>
using namespace std;

int main()
{
    int length;
    cout << "the length is: ";
    cin >> length;

    int midnum;
    midnum = (1 + length) / 2;
    cout << "the midnum is: " << midnum << endl;

    int L, R = midnum;
    for (int row = 0; row < length; row++)
    {
        for (int column = 0; column < length; column++)
        {
            if (L == column){
                cout << "*";}
            else if (R == column){
                cout << "*";}
            else{
                cout << " ";}
        }
        cout << endl;
    }
    int column=0;
    for (L = 1; L < midnum; L++)
    {
        if (L == column )

            cout << "*";

        else

            cout << "\t";
        cout << endl;
    }
    return 0;
}