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
    void moveZeroes(vector<int>& nums) 
    {
	size_t idx = 0;
	for (size_t i = 0; i != nums.size(); ++i) {
	    if (nums[i] != 0) {
		swap(nums[idx], nums[i]);
		idx++;
	    }
	}
    }

    void moveZeroes2(vector<int>& nums) 
	// two-pass algorithm 
    {
	for (size_t i = 0; i != nums.size(); ++i) {
	    if (nums[i] != 0) {
		continue;
	    }

	    size_t j = i + 1;
	    while (j != nums.size() && nums[j] == 0) {
		++j;
	    }
	    if (j == nums.size()) {
		break;
	    }
	    else {
		swap(nums[i], nums[j]);
	    }
	}

    }
};

int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    vector<int> num1 = {4, 5, 6, 7 , 8, 0, 1, 2};
    vector<int> num2 = {0,0,0, 4, 5, 6, 7 , 8, 0, 1, 2};
    vector<int> num3 = {0};
    vector<int> num4 = {0,0,0,0};
    vector<int> num5 = {0,0,0,0, 1};
    s.moveZeroes(num1);
    DBG(num1);

    //cout << s. << endl;
    return 0;
}
