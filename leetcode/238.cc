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
    vector<int> productExceptSelf(const vector<int>& nums) 
    {
	vector<int> ret(nums.size(), 0);

	int prod = 1;
	for (size_t i = 0; i != nums.size(); ++i) {
	    ret[i] = prod;
	    prod *= nums[i];
	}

	prod = 1;
	for (size_t i = nums.size(); i != 0;) {
	    --i;
	    ret[i] *= prod;
	    prod *= nums[i];
	}
	return ret;
    }
};

int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
