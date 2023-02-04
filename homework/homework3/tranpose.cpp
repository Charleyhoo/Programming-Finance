// transpose

/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
int matrix[20][20],row,col,i,j,transpose[20][20];
cout<<"Enter number of rows of matrix:=";
cin>>row;
cout<<"Enter number of column of matrix:=";
cin>>col;
if(row==col){
cout<<"Enter the elements of array:"<<endl;
for(i=0;i<row;i++){
for(j=0;j<col;j++){
cout<<"Enter the elements of matrix["<<i<<"]["<<j<<"]:";
cin>>matrix[i][j];
}
}
cout<<"Matrix before transposition:";
for(i=0;i<row;i++){
for(j=0;j<col;j++){
cout<<matrix[i][j]<<"\t";
}
cout<<"\n";
}
cout<<"Matrix after transposition:";
for(i=0;i<row;i++){
for(j=0;j<col;j++){
transpose[i][j]=matrix[j][i];
cout<<transpose[i][j]<<"\t";
}
cout<<"\n";
}}
else
cout<<"transpose not possible";
return 0;
}
*/

#include <iostream>
using namespace std;
int main()
{

    int rows, cols, i, j;
    int one[50][50], transpose[50][50];

    cout << "Enter Rows and Columns of Matrix\n";
    cin >> rows >> cols;

    cout << "Enter  Matrix : " << rows << "  X  " << cols << " \n";
    // fill matrix

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> one[i][j];
        }
    }

    cout << "Input matrix is:  \n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << one[i][j] << " ";
        }
        cout << endl;
    }
    // transpose matrix

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[i][j] = one[j][i];
        }
    }
    cout << "The transpose matrix is: \n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl; //会多一行空格
}
