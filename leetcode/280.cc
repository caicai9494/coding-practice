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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* nxt) : val(x), next(nxt) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
  public:
    void wiggleSort(vector<int>& nums) 
    {
	if (nums.empty()) { return; }

	sort(nums.begin(), nums.end(), greater<int>());

	int upper = nums.size() % 2 == 0 ? nums.size() - 1 : nums.size() - 2;
	for (int i = 0; i < upper;) {
	    swap(nums[i], nums[i+1]);
	    i += 2;
	}
    }

#ifdef BETTER
    void wiggleSort(vector<int>& nums) 
    {
	for (int i = 1; i < nums.size(); ++i) {
	    if (i & 1 == 1) { // odd
		if (nums[i-1] > nums[i]) { swap(nums[i-1], nums[i]); }
	    }
	    else { // even
		if (nums[i-1] < nums[i]) { swap(nums[i-1], nums[i]); }
	    }
	}
    }
#endif
};

int main()
{
    Solution s;
    vector<int> nums = {3, 5, 2, 1, 6, 4, 8, 7, 9};
    s.wiggleSort(nums);
    DBG(nums);
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
