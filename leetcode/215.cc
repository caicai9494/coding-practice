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

    int findKthLargest(vector<int>& nums, int k) 
    {
	assert (!nums.empty()); 
	return findKth(nums, 0, nums.size() - 1, (int)nums.size() - k);
    }

    int findKth(vector<int>& nums, size_t low, size_t high, size_t k) 
    {
	size_t ret = partitionFirst(nums, low, high);
	if (ret == k) {
	    return nums[ret];
	}

	if (ret < k) {
	    return findKth(nums, ret + 1, high, k);
	}
	else {
	    return findKth(nums, low, ret - 1, k);
	}
    }

    size_t partitionFirst(vector<int>& nums, size_t low, size_t high)
    {
	assert(low <= high);
	size_t i = low;
	size_t j = high + 1;
	int key = nums[low];

	while (true) {
	    while (nums[++i] <= key) { if (i == high) break; }
	    while (nums[--j] > key) { if (j == low) break; }
	    if (i >= j) break;
	    swap(nums[i], nums[j]);
	}
	swap(nums[low], nums[j]);
	return j;
    }

};

int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    vector<int> num = {3, 2, 1, 5, 6, 4};
    DBG(s.findKthLargest(num, 2));
    DBG(num);
    //cout << s. << endl;
    return 0;
}
