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

	    int win = 0, lastwin = 0;
	    int last_price = prices[0];
	    for(int &price: prices)
	    {
		if(win < 0) 
		    win = 0;

		//portofolio negative
		int diff = price - last_price;
		if(diff < 0)
		{
		    if(win > lastwin)
		        lastwin = win;
		}

		win += diff;
		last_price = price;
	    }
	    return lastwin > win ? lastwin : win;
	}

};
int main()
{
    Solution s;
    vector<int> p = {3,2,6,5,0,3};
    cout << s.maxProfit(p)<<endl;
    return 0;
}
