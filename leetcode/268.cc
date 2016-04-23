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
    int missingNumber(vector<int>& nums) 
    {
	int sum = 0; 
	size_t i = 0;
	for (; i != nums.size(); ++i) {
	    sum += i - nums[i];
	}
	return sum + i;
    }
};

int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    vector<int> num = {0, 1, 3};
    DBG(s.missingNumber(num));
    //cout << s. << endl;
    return 0;
}
