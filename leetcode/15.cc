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
    vector<vector<int>> ret;
    vector<vector<int>> threeSum(vector<int> nums) 
    {
	if (nums.size() < 3) return ret;

	sort(nums.begin(), nums.end());
	for (size_t i = 0; i != nums.size() - 2;) {
	   for (size_t j = i + 1, k = nums.size() - 1; j < k;) {
	       int sum = nums[i] + nums[j] + nums[k];
	       if (sum == 0) {
		   ret.push_back({nums[i], nums[j], nums[k]});
	       }

	       if (sum <= 0) {
		   while (nums[j] == nums[++j] && j < k);
	       }

	       if (sum >= 0) {
		   while (nums[k] == nums[--k] && j < k);
	       }
	   }
	   while (nums[i] == nums[++i] && i < nums.size() - 2);
	}

	return ret;
    }
};

int main()
{
    Solution s;
    //auto vvec = s.threeSum({1, 2, -3});
    auto vvec = s.threeSum({-1,0,1,2,-1,-4});
    for (auto it = vvec.begin(); it != vvec.end(); ++it) {
	DBG(*it);
    }
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
