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
	void rec(const vector<int> &num, int left, int right, int &peak)
	{
	    int mid = (left + right) / 2;
	    if(num[mid] > num[right])
	    {
	    cout << "debug " <<mid << endl;
		    peak = mid;
		    return;
	    }

	    rec(num, left, mid, peak);
	    rec(num, mid , right, peak);

	    /*
	    if(num[left] < num[mid] && num[mid] > num[right])
		rec(num, left, mid, peak);
	    else
	    {
		rec(num, left, mid, peak);
		rec(num, mid , right, peak);
	    }
	    */

	}
	int findPeakElement(const vector<int> &num)
	{
	    /*
	    int big = numeric_limits<int>::min(), id = 0;
	    for(int i = 0; i < num.size(); i++)
		if(num[i] > big) big = num[i], id = i;
	    return id;
	    */
	    int left = 0, right = num.size() - 1;
	    int mid;
	    while(left < right)
	    {
		mid = (left + right) / 2;
		if(num[mid] < num[mid+1])
		    left = mid + 1;
		else right = mid;
	    }
	    return left;
	}

};
int main()
{
    Solution s;
    vector<int> num = {1, 2, 3, 1};
    cout << num.size() << endl;
    cout << s.findPeakElement(num)<< endl;
    return 0;
}
