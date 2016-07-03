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
#include <unordered_set>
#include <vector>

#include "lz_error.h"

using namespace std;

class Solution {
  public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
	sort(nums1.begin(), nums1.end());
	unordered_set<int> table; 

	vector<int> ret;

	for (auto j = 0; j != nums2.size(); ++j) {
	    if (table.insert(nums2[j]).second &&
		binary_search(nums1.begin(), nums1.end(), nums2[j])) { // if not duplicate
		ret.push_back(nums2[j]);
	    }
	}

	return ret;
    }
};

int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    vector<int> num1 = {1, 1, 2, 2};
    vector<int> num2 = {2, 2};
    DBG(s.intersection(num1, num2));
    //cout << s. << endl;
    return 0;
}
