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
	float func(int x, int s)
	{
	    return x * x - s;
	}
	int sqrt(int x)
	{
	    
	    int left = 0;
	    int right = 46341;
	    int mid = right / 2;

	    while(mid != left)
	    {
		int product = mid * mid;
		cout << product << endl;
		if(product < x)
		    left = mid;
		else if(product > x)
		    right = mid;
		else
		    break;

		mid = (left + right)/2;
	    }

	    return mid;
	}
};
int main()
{
    Solution s;
    cout << s.sqrt(2147395599) << endl;
    return 0;
}
