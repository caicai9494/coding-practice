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
	    int ret = 0;
	    for(unsigned int i = 1; i < prices.size(); i++)
		ret = max(ret, ret + prices[i] - prices[i-1]);
	    return ret;
	}

};
int main()
{
    Solution s;
    vector<int> p = {3,2,6,5,0,3};
    cout << s.maxProfit(p)<<endl;
    return 0;
}
