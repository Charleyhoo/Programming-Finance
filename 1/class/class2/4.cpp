#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y, r, value;
    double a=0;
    int N,pi;
    cout << "Enter how many numbers to consider:";
    cin >> N;

    for (int i=0; i<N; i++)
    {
        x = (double)rand()/RAND_MAX;
        y=(double)rand()/RAND_MAX;
        r=sqrt(x*x+y*y);

        if (r<=1)
        {
            a++;
        }
   cout << x << " " << y << " "
             << a << " " << N
             << " - " << pi << endl
             << endl;
    }
    value=a/N;
    double Pi=4*value;     //Q：细想为什么这里要用double Pi？
     
    cout<<"The value of Pi:"<<Pi<<endl;
    return 0;

}