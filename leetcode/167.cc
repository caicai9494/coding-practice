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
    unordered_map<int, int> table;
    vector<int> ans;

    vector<int> twoSum(vector<int>& numbers, int target) {

	for (auto it = numbers.begin(); it != numbers.end(); ++it) {
	    int diff = target - *it;
	    if (diff >= *it) {
		auto ret = lower_bound(it + 1, numbers.end(), diff);
		if (ret != numbers.end() && *ret == diff) {
		    return {it - numbers.begin() + 1, ret - numbers.begin() + 1};
		}
	    }
	}

	return ans;

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
