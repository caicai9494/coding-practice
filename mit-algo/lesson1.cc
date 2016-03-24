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
      /*
    pair<int, int> findAPeak2D(const vector<vector<int> >& nums) 
    {
    }
    */

    int findAPeak(const std::vector<int>& nums) 
    {
	if (nums.empty()) {
	    return -1;
	}

	return findAPeak_(nums, 0, nums.size() - 1);
    }

  private:
    int findAPeak_(const std::vector<int>& nums, size_t lhs, size_t rhs) 
    {
	size_t pos = (lhs + rhs) / 2;
	if (nums[pos] < nums[pos + 1]) {
	    return findAPeak_(nums, pos, rhs);
	}
	else if (nums[pos] < nums[pos - 1]) {
	    return findAPeak_(nums, lhs, pos);
	}
	else {
	    return pos;
	}
    }
};

int main()
{
    Solution s;
    cout << s.findAPeak({1,2,3,4,3,2});
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
