//determinant 3*3

#include <iostream>
using namespace std;

int main(){
    int a[3][3], i, j, deter=0;
    cout<<"Enter Matrix number"<<endl;
    for(i=0; i<3; i++){
        for (j=0; j<3; j++){
            cout<<"Enter number in pocket ["<<i<<"]["<<j<<"]";
            cin>>a[i][j];
        }
    }
    cout<<"Matrix is : "<<endl;
    for(i=0; i<3;i++){
        for(j=0;j<3;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            deter=a[0][0]* a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]+a[0][2]*a[1][2]*a[2][1]
            -a[0][2]*a[1][1]*a[2][0]-a[0][0]*a[1][2]*a[2][1]-a[0][1]*a[1][0]*a[2][2];
        }
    }
    cout<<"The Determinant of 3x3 matrix is: "<<deter;
    return 0;
}