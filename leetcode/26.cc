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

using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int>& nums)
    {
	if (nums.size() < 2) {
	    return nums.size();
	}

	size_t count = 1;
	for (size_t i = 0; i < nums.size() - 1; ++i) {
	    if (nums[i] != nums[i + 1]) {
		nums[count] = nums[i + 1];
		++count;
	    }
	}
	nums.resize(count);
	return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums({1,1});
    s.removeDuplicates(nums);
    for (size_t i = 0; i != nums.size(); ++i) {
	cout << nums[i] << '\n';
    }

    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
