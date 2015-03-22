#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
#include <bitset>

using namespace std;
class Solution
{
    public:
	int maxProfit(vector<int> &prices)
	{
	    if(prices.empty()) return 0;

	    int win = 0;
	    int last_price = prices[0];
	    for(int& price: prices)
	    {
		int diff = price - last_price;
		if(diff > 0)
		    win += diff;
		last_price = price;
	    }
	    return win;
	}

};
int main()
{
    Solution s;
    vector<int> p = {3,2,6,5,0,3};
    cout << s.maxProfit(p)<<endl;
    return 0;
}
