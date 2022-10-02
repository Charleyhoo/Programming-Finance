#include <iostream>
using namespace std;

int main()
{
    {
        int a[0];
        cout<<"input a number";
        cin >>a[0];
        if(a[0]<8)
        {
        cout<<"a is less than 8, output the shape :"<<endl;
        // output triangular shape
        const int N = 8;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= 10; j++)
            cout <<'\t';
        for (int j = 1; j <= 7-i; j++)
            cout <<'\t';
        for (int j = 1; j <= i ; j++)
            cout << '*';
        cout << endl;
    }
        }

        else
        {
        cout << "a is larger than 8"<<endl;
        }
        
    }
    
    return 0;
}