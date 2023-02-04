#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution{
public:
    vector<int> corpFlightBookings(vector< vector<int> > & bookings, int n)
    {
        vector<int> res;
        vector<int> nums(n + 2, 0);
        for (int i = 0; i < bookings.size(); i++)
        {
            nums[bookings[i][0]] += bookings[i][2];
            nums[bookings[i][1] + 1] += -bookings[i][2];
            cout << nums[bookings[i][0]] << endl;
            cout << nums[bookings[i][1] + 1] << endl;
        }
         int sums=0;
        for(int i=1; i< n+1;i++){
            sums+=nums[i];
            res.push_back(sums);
        }
        return res;
    }
};
int main()
{
    return 0;
}
