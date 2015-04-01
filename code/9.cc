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
	/*
	bool isPalindrome(int x)
	{
	    string numstr = to_string(x);
	    return equal(numstr.begin(), numstr.end(), numstr.rbegin());
	}
	*/
	bool isPalindrome(int x)
	{
	    if(x < 0) return false;
	    int count = getCount(x);
	    int l,r;
	    l = count, r = 0;
	    while(l > r)
	    {
		int lhs,rhs;
		rhs = x / pow(10, r) % 10;
	    }

	    while(1)
	    {
		if(x < 10) return true;
		int right, left, count;
		right = x % 10;
		x /= 10;

		count = getCount(x);
		left = getHight(x);
		x -= left*pow(10, count-1);
		cout << x << endl;

		if(left != right)
		    return false;

		if(count <= 1)
		    break;
	    }
	    return true;
	}
	int getCount(int x)
	{
	    int count = 0;
	    while(x != 0)
		x /= 10, count++;
	    return count;
	}
	int getHight(int x)
	{
	    int count = getCount(x);
	    return x / pow(10, count-1);
	}

};
int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    if(s.isPalindrome(1000021))
    cout << "yes" << endl;
    return 0;
}
