#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
#include <bitset>
#include <set>
#include <queue>

using namespace std;

class Solution {
  public:
    bool isSymmetric(TreeNode* root) 
    {
	if (!root) {
	    return true;
	}
	return isSymImpl(root->left, root->right);
    }

    bool isSymImpl(TreeNode* left, TreeNode* right) 
    {
	if (left && right) {
	    return left->val == right->val ?
		isSymImpl(left->left, right->right) &&
		isSymImpl(left->right, right->left) : false;
	}

	return !left && !right;
    }

};
