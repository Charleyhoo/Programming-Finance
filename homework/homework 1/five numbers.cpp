#include <iostream>
using namespace std;
int max(int b[],int n),min(int b[],int n);
int main()
{
	int a[5];
	cout<<"input 5 integers:";
	for(int i=0;i<5;i++)
	cin>>a[i];
	cout<<"max is "<<max(a,5)<<','<<"min is "<<min(a,5)<<endl;
}
int max(int b[],int n)
{
	int max=b[0];
	for(int i=0;i<n;i++)
	if(b[i]>max)
	max=b[i];
	return max;
}
int min(int b[],int n)
{
	int min=b[0];
	for(int i=0;i<n;i++)
	if(b[i]<min)
	min=b[i];
	return min;
}