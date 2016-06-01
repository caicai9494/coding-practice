#include <algorithm>
#include <cassert>
#include <limits>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "lz_error.h"

using namespace std;

class Solution {
  public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
	int lastDiff = 0x0fffffff;
	int lastSum = 0;

	sort(nums.begin(), nums.end());

	for (size_t i = 0; i != nums.size(); ++i) {
	    int leftOver = target - nums[i];
	    for (size_t j = i + 1, k = nums.size() - 1; j < k;) {
		int newSum = nums[j] + nums[k];
		int newDiff = abs(newSum - leftOver);
		if (newDiff < lastDiff) {
		    lastSum = newSum + nums[i];
		    lastDIff = newDiff;
		}

		if (newSum == leftOver) {
		    return target;
		}
		else if (newSum < leftOver) {
		    ++j;
		}
		else {
		    --k;
		}
	    }
	}

	return lastSum;
    }


};

int main()
{
    Solution s;
    //cout << s.threeSumClosest({1,2,2}, 5);
    vector<int> num = {-1,2,1,-4};
    DBG(s.threeSumClosest(num, 1));
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
