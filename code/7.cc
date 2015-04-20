#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
#include <bitset>
#include <set>

using namespace std;
class Solution
{
    public:
	int reverse(int x)
	{
	    if(x < 0 && -x < 0) return 0;
	    if(x < 0) return -reverse(-x);

	    int ret = 0, rm;
	    while(x > 0)
	    {
		rm = x % 10;
		if(numeric_limits<int>::max() / 10 < ret) return 0;

		ret = ret * 10 + rm;
		x /= 10;
	    }

	    return ret;
	}

};
int main()
{
    //cout << -1 * numeric_limits<int>::min() << endl;
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    int x;
    //while(1)
    {
    cin >> x;
    cout << s.reverse(numeric_limits<int>::min()) << endl;
    }
    return 0;
}
