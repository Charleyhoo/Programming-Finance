#include <iostream>
using namespace std;

int main()
{
    int length;
    cout << "the length is: ";
    cin >> length;

    int midnum;
    midnum = (length - 1) / 2;
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
    if (L == 0) {
			R += L;
			L = R - L;
			R = R - L;
		
		L--;
		R++;
    }
    return 0;
}