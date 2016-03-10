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
    int threeSumClosest(const vector<int>& nums, int target) {

	set<int> ret;
	for (size_t i = 0; i != nums.size(); ++i) {
	    for (size_t j = i + 1; j != nums.size(); ++j) {
		for (size_t k = j + 1; k != nums.size(); ++k) {
		    ret.insert(nums[i] + nums[j] + nums[k]);
		}
	    }
	}

	auto it = ret.lower_bound(target);
	for (auto t = ret.begin(); t != ret.end(); ++t) cout << *t << '\n';

        if (it = ret.end()) {
	    return *ret.back();
	}
	else if (*it == target) {
	    return target;
	}
	// guarentee to have an answer

	if (*it == target) {
	    return target;
	} 
	



    }


};

int main()
{
    Solution s;
    cout << s.threeSumClosest({1,2,2}, 5);
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
