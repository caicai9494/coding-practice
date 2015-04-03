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
	    
	    int p = x;
	    int q = 0;

	    while(p >= 10)
	    {
		q *= 10;
		q += p % 10;
		p /= 10;

	    }

	    return q == x / 10 && p == x%10;
	}

};
int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    if(s.isPalindrome(121))
    cout << "yes" << endl;
    return 0;
}
