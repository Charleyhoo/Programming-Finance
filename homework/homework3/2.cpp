//Chang Huang
//Spet.29.2022 9:49pm 
//Have A Good Night
#include <iostream>
using namespace std;

int main()
{
    bool menu = true;
    while (menu)
    {
        int choice;
        cout << endl;
        cout << "\n Menu";
        cout << "\n Choice 1: Addition";
        cout << "\n Choice 2: Substraction";
        cout << "\n Choice 3: Multiplication";
        cout << "\n Choice 4: Transpose";
        cout << "\n Choice 5: Determinant";
        cout << "\n Choice 6: Inverse";
        cout << "\n Choice 7: Quit";
        cout << "\n Enter your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int rows, cols, i, j;
            int one[10][10], two[10][10], sum[10][10];

            cout << "Enter Rows and Columns of Matrix\n";
            cin >> rows >> cols;

            cout << "Enter first Matrix of size: " << rows << " X " << cols;
            //  Input first matrix*/
            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    cin >> one[i][j];
                }
            }
            cout << "\n\nThe first matrix is : \n";

            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    cout << one[i][j] << "  ";
                }
                cout << endl;
            }

            //  Input second matrix
            cout << "\nEnter second Matrix of size: " << rows << " X " << cols;
            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    cin >> two[i][j];
                }
            }

            cout << "\n\nThe Second Matrix is :\n";
            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    cout << two[i][j] << " ";
                }
                cout << endl;
            }
            /* adding corresponding elements of both matrices
               sum[i][j] = one[i][j] + two[i][j] */
            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    sum[i][j] = one[i][j] + two[i][j];
                }
            }

            cout << "Sum Matrix\n";
            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    cout << sum[i][j] << " ";
                }
                cout << "\n";
            }
            break;
        }
        case 2:
        {
            int rows, cols, i, j;
            int one[10][10], two[10][10], sum[10][10];

            cout << "Enter Rows and Columns of Matrix\n";
            cin >> rows >> cols;

            cout << "Enter first Matrix of size: " << rows << " X " << cols;
            //  Input first matrix*/
            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    cin >> one[i][j];
                }
            }
            cout << "\n\nThe first matrix is : \n";

            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    cout << one[i][j] << "  ";
                }
                cout << endl;
            }
            //  Input second matrix
            cout << "\nEnter second Matrix of size: " << rows << " X " << cols;
            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    cin >> two[i][j];
                }
            }
            cout << "\n\nThe Second Matrix is :\n";
            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    cout << two[i][j] << " ";
                }
                cout << endl;
                /* adding corresponding elements of both matrices
                   sum[i][j] = one[i][j] + two[i][j] */
                for (i = 0; i < rows; i++)
                {
                    for (j = 0; j < cols; j++)
                    {
                        sum[i][j] = one[i][j] - two[i][j];
                    }
                }

                cout << "Sum Matrix\n";
                for (i = 0; i < rows; i++)
                {
                    for (j = 0; j < cols; j++)
                    {
                        cout << sum[i][j] << " ";
                    }
                    cout << "\n";
                }
                break;
            }
        case 3:
        {
            // loop variable i to iterate rows and j to iterate columns.
            int row1, col1, row2, col2, i, j, k;

            // Declaring the 3 matrices (2D arrays) m1-first matrix, m2- second matrix and pro- stores the multiplication of the two matrices
            int m1[10][10], m2[10][10], pro[10][10];

            cout << "\n\nEnter the number of Rows and Columns of first matrix : ";
            cin >> row1 >> col1;

            cout << "\n\nEnter the number of Rows and Columns of second matrix : ";
            cin >> row2 >> col2;

            // Matrix multiplication property
            if (col1 == row2)
            {
                cout << "\nEnter the " << row1 * col1 << " elements of first matrix : \n";

                for (i = 0; i < row1; i++)
                {
                    for (j = 0; j < col1; j++)
                    {
                        cin >> m1[i][j];
                    }
                }

                cout << "\nEnter the " << row2 * col2 << " elements of second matrix : \n";

                for (i = 0; i < row2; i++)
                {
                    for (j = 0; j < col2; j++)
                    {
                        cin >> m2[i][j];
                    }
                }

                // cout << "\n\n"
                // calculating the Product matrix - containing #rows and #columns of the 1st and the 2nd matrix respectively.
                for (i = 0; i < row1; i++)
                {
                    for (j = 0; j < col2; j++)
                    {
                        pro[i][j] = 0;

                        for (k = 0; k < col1; k++)
                            pro[i][j] = pro[i][j] + (m1[i][k] * m2[k][j]);
                    }
                }

                cout << "\n\nThe first matrix is : \n";

                for (i = 0; i < row1; i++)
                {
                    for (j = 0; j < col1; j++)
                    {
                        cout << m1[i][j] << "  ";
                    }
                    cout << endl;
                }

                cout << "\n\nThe second matrix is : \n";

                for (i = 0; i < row2; i++)
                {
                    for (j = 0; j < col2; j++)
                    {
                        cout << m2[i][j] << "  ";
                    }
                    cout << endl;
                }

                cout << "\n\nThe Product matrix is : \n";

                for (i = 0; i < row1; i++)
                {
                    for (j = 0; j < col2; j++)
                    {
                        cout << pro[i][j] << "  ";
                    }
                    cout << endl;
                }
            }
            else
            {
                cout << "\n\nMatrix multiplication can't be done as the indices do not match!";
            }

            cout << "\n\n";
            break;
        }
        case 4:
        {
            int rows, cols, i, j;
            int one[10][10], transpose[10][10];

            cout << "Enter Rows and Columns of Matrix\n";
            cin >> rows >> cols;

            cout << "Enter  Matrix of size: " << rows << " X " << cols << " \n";
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
            cout << endl; //会多一行空格出来

            break;
        }
        case 5:
        {
            int a[3][3], i, j, deter = 0;
            cout << "Enter 3*3 Matrix number: " << endl;
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    cout << "Enter number in pocket [" << i << "][" << j << "]";
                    cin >> a[i][j];
                }
            }
            cout << "The 3*3 Matrix is : " << endl;
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    deter = a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[0][2] * a[1][2] * a[2][1] - a[0][2] * a[1][1] * a[2][0] - a[0][0] * a[1][2] * a[2][1] - a[0][1] * a[1][0] * a[2][2];
                }
            }
            cout << "The Determinant of 3*3 matrix is: " << deter;
            break;
        }
        case 6:
        {
            int a[3][3], i, j;
            float determinant = 0;
            cout << "Enter elements of 3x3 matrix:\n";
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    cin >> a[i][j];
                }
            }
            cout << "\nThe entered matrix is:\n";
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    cout << a[i][j] << "  ";
                }
                cout << "\n";
            }
            for (i = 0; i < 3; i++)
            {
                determinant = determinant + (a[0][i] * (a[1][(i + 1) % 3] * a[2][(i + 2) % 3] -
                                                        a[1][(i + 2) % 3] * a[2][(i + 1) % 3]));
            }
            if (determinant == 0)
            {
                cout << "Inverse does not exist (Determinant=0).\n";
            }
            else
            {
                cout << "\nInverse of matrix is: \n";
            }
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    cout << (a[(i + 1) % 3][(j + 1) % 3] *
                             a[(i + 2) % 3][(j + 2) % 3]) -
                                (a[(i + 1) % 3][(j + 2) % 3] *
                                 a[(i + 2) % 3][(j + 1) % 3]) /
                                    determinant
                         << "\t";
                }
                cout << "\n";
            }
            break;
        }
        case 7:
        {
            menu = false;
            break;
        }
        default:
            cout << "Invalid choice, try again." << endl;
        }
        }
        return 0;
    }
}