#include <iostream>
#include <vector>
#include <functional>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
#include <queue>
#include <bitset>
#include <set>

using namespace std;
class Solution
{
    public:
	vector<int> ret;
	void sumTree(TreeNode *root, int temp) {
	    if(!root->left && !root->right)
		ret.push_back(temp);
	    if(root->left)
	        sumTree(root->left, temp * 10 + root->left->val);
	    if(root->right)
	        sumTree(root->right, temp * 10 + root->right->val);

	}
	int sumNumbers(TreeNode *root) {
	    if(!root) return 0;
	    sumTree(root, root->val);
	    return accumulate(ret.begin(), ret.end(), 0, plus<int>());
	}

};
