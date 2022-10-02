#include <iostream>
using namespace std;

int main()
{
	int length = 9;
	int middle = (length - 1)/2;
	
	int L = middle;
	int R = middle;
	
	for (int row = 0; row < length; row++) {
		for (int column = 0; column < length; column++) {
			if (L == column) {
				cout << "*";
			}else if (R == column) {
				cout << "*";
			} else {
				cout << " ";
			}

		}
		cout << endl;
		if (L == 0) {
			R += L;
			L = R - L;
			R = R - L;
		}
		L--;
		R++;
	}
	
	return 0;
	
}