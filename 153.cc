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
	int findMin(vector<int> &num)
	{
	    int left = 0;
	    int right = num.size() - 1;
	    int mid;
	    if(num[left] <= num[right]) return num[left];

	    while(left < right)
	    {
		mid = (left + right) / 2;
		
		if(num[mid] > num[right])
		    left = mid + 1;
		else
		    right = mid;

		/*
		if(num[left] > num[right])
		{
		    if(num[left] <= num[mid])
			left = mid + 1;
		    else
			if(num[mid] < num[mid - 1] && num[mid] < num[mid + 1])
			    return num[mid];
			else 
			    right = mid - 1;
		    	
		}
		else
		{
		    if(num[left] < num[right])
			return num[left];
		    else
		    {

			if(num[mid] < num[mid - 1] && num[mid] < num[mid + 1])
			    return num[mid];
			else
			    left = mid+ 1;

		    }
		}
		*/
	    }

	    return num[left];
	}
};
int main()
{
    Solution s;
    //vector<int> num = {3,4, 5,  1, 2};
    //vector<int> num = {4, 5, 6, 7,8,9, 0, 1, 2};
    vector<int> num = {4, 5, 6, 1, 2 ,3};
    cout << s.findMin(num) << endl;
    return 0;
}
