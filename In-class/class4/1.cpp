//Chang Huang
//Sept.30 5:27PM
/*
Write a recursive method countBinStr that takes one integer parameter n as input, 
and returns the number of binary strings of length n that do not have two consecutive 0's. 
For example, for n = 4, the number of binary strings of length 4 that do not contain two consecutive 0's is 8, 
and they are: 1111, 1110, 1101, 1011, 1010, 0111, 0110, 0101
*/
#include <iostream>
using namespace std;
// use recrusive method
int count(int n);
int main(){
    cout<<"Put the integer n: \n";
    int n;
    cin>>n;
    cout<<"the "<< n <<" output is : " << count(n)<<endl;
    return 0;
}
int count(int n){
    int a=1, b=1;
    for (int i=1; i<n ; i++){
        int temp=a+b;
        b=a;
        a=temp;
    }
    return a+b;
    
}
/*
int main(){
    
    int n;
    cout<<"Put the integer n: \n";
    cin>>n;
    int i, a=1,b=1;
    for (int i=1; i< n; i++){
        int temp=a+b;
        b=a;
        a=temp;

    }
    
    cout<<"the "<< n << " output is:  "<< a+b <<endl;
    return 0;

}
*/

// 1: 1,0
// 2: 01, 10, 11
// 3: 001, 010, 101, 110, 111
// 4: 0101, 0111, 1111, 1010, 1110, 1011, 1101, 0110