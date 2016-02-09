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
class Solution {
public:
    int maxArea(vector<int> &height) {
	int marea = 0;
	int left = 0;
	int right = height.size() - 1;
	while(left < right)
	{
	    marea = max(marea, (right - left) * min(height[left], height[right]));
	    if(height[left] < height[right]) left++;
	    else right--;
	}
	/*
	for(unsigned int i = 0; i < height.size(); i++r
	j
	    for(unsigned int j = i; j < height.size(); j++)
	    {
		int h = min(height[i], height[j]);
		int a = (j - i) * h;
		if(a > marea)
		    marea = a;
	    }
	}
	*/

	return marea;
    }
};

int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    cout << s.maxArea(num) << endl;
    return 0;
}
