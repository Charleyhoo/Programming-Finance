// Name: Chang Huang
#include <iostream>
using namespace std;

int main()
{
    int row;
    int column;
    int length;
    cout<<"input a length:";
    cin >> length;
    for (int row=0; row<= length; row++)
    {
        for(int column=0; column<=length; column++)
        {
            if (column<row){
                cout << "*";
            }
            else{
                cout<<" ";
            }
        
        }
        cout<<endl;
    }
    return 0;
}





/*
example code:
Name: Huang Chang
#include <iostream>
using namespace std;
 
int main()
{
    {
        int row;
        cout<<"input a number";
        cin >>row;
        if(row<8)
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
*/






