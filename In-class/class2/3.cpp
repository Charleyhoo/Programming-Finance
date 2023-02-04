// Name : Chang Huang
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

// we want to measure 100 dots

int main()
{
    int N, i;                               // "N" is the value we want to measure
    cout<<"How many dots do you want:"<<endl;
    cin>> N;

    double rand_x, rand_y;               // the dot's x_value and y_value
    int circle_points = 0;              // points in circle 
    double circle_s;                   // the area of circle 
    int pi;
// Create the txt.file         
    ofstream mycout;          
    mycout.open("3.txt", ios::out);    // Notice：ios::out ==>Have permission to store data to the file

    srand(time(0));               

    for (i = 0; i < N; i++)
    {
        rand_x = (double) rand() / RAND_MAX;
        rand_y = (double) rand() / RAND_MAX;
        circle_s = hypot(rand_x, rand_y);       //get the distance with the origin point
    
        if (circle_s <= 1)
        {
        circle_points++;
        }
        
        cout << rand_x << " " << rand_y << " "
             << circle_points<<endl;
        
    mycout <<rand_x <<","<< rand_y<< "\n"<<endl;
        
        
    }
    double Pi = 4 * ((double) circle_points)/N;        
    cout << "The estimated pi is: " << Pi << endl;

return 0;

}
