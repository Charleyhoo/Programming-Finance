//multiplicatioin

/*
#include <iostream>
using namespace std;

int main()
{
    int a[10][10], b[10][10], mult[10][10], r1, c1, r2, c2, i, j, k;

    cout << "Enter rows and colum
    ns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    // If column of first matrix in not equal to row of second matrix,
    // ask the user to enter the size of matrix again.
    while (c1!=r2)
    {
        cout << "Error! column of first matrix not equal to row of second.";

        cout << "Enter rows and columns for first matrix: ";
        cin >> r1 >> c1;

        cout << "Enter rows and columns for second matrix: ";
        cin >> r2 >> c2;
    }

    // Storing elements of first matrix.
    cout << endl << "Enter elements of matrix 1:" << endl;
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c1; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }

    // Storing elements of second matrix.
    cout << endl << "Enter elements of matrix 2:" << endl;
    for(i = 0; i < r2; ++i)
        for(j = 0; j < c2; ++j)
        {
            cout << "Enter element b" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }

    // Initializing elements of matrix mult to 0.
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
        {
            mult[i][j]=0;
        }

    // Multiplying matrix a and b and storing in array mult.
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }

    // Displaying the multiplication of two matrix.
    cout << endl << "Output Matrix: " << endl;
    for(i = 0; i < r1; ++i)
    for(j = 0; j < c2; ++j)
    {
        cout << " " << mult[i][j];
        if(j == c2-1)
            cout << endl;
    }

    return 0;
}
*/

#include <iostream>

using namespace std;

int main() {
    cout << "\n\nWelcome to Studytonight :-)\n\n\n";
    cout << " =====  Program to demonstrate Multiplication of two Matrices ===== \n\n";

    //loop variable i to iterate rows and j to iterate columns.
    int row1, col1, row2, col2, i, j, k;

    //Declaring the 3 matrices (2D arrays) m1-first matrix, m2- second matrix and pro- stores the multiplication of the two matrices
    int m1[10][10], m2[10][10], pro[10][10];

    cout << "\n\nEnter the number of Rows and Columns of first matrix : ";
    cin >> row1 >> col1;

    cout << "\n\nEnter the number of Rows and Columns of second matrix : ";
    cin >> row2 >> col2;

    //Matrix multiplication property
    if (col1 == row2) {
        cout << "\nEnter the " << row1 * col1 << " elements of first matrix : \n";

        for (i = 0; i < row1; i++) {
            for (j = 0; j < col1; j++) {
                cin >> m1[i][j];
            }
        }

        cout << "\nEnter the " << row2 * col2 << " elements of second matrix : \n";

        for (i = 0; i < row2; i++) {
            for (j = 0; j < col2; j++) {
                cin >> m2[i][j];
            }
        }

        // cout << "\n\n"
        //calculating the Product matrix - containing #rows and #columns of the 1st and the 2nd matrix respectively.
        for (i = 0; i < row1; i++) {
            for (j = 0; j < col2; j++) {
                pro[i][j] = 0;

                for (k = 0; k < col1; k++)
                    pro[i][j] = pro[i][j] + (m1[i][k] * m2[k][j]);
            }
        }

        cout << "\n\nThe first matrix is : \n";

        for (i = 0; i < row1; i++) {
            for (j = 0; j < col1; j++) {
                cout << m1[i][j] << "  ";
            }
            cout << endl;
        }

        cout << "\n\nThe second matrix is : \n";

        for (i = 0; i < row2; i++) {
            for (j = 0; j < col2; j++) {
                cout << m2[i][j] << "  ";
            }
            cout << endl;
        }

        cout << "\n\nThe Product matrix is : \n";

        for (i = 0; i < row1; i++) {
            for (j = 0; j < col2; j++) {
                cout << pro[i][j] << "  ";
            }
            cout << endl;
        }

    } else {
        cout << "\n\nMatrix multiplication can't be done as the indices do not match!";
    }

    cout << "\n\n";

    return 0;
}