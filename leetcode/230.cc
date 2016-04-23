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

/**
 *
 *  * Definition for a binary tree node.
 *
 *  * struct TreeNode {
 *
 *  *     int val;
 *
 *  *     TreeNode *left;
 *
 *  *     TreeNode *right;
 *
 *  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *
 *  * };
 *
 *  */

using namespace std;

class Solution {
  public:
    int kthSmallest(TreeNode* root, int k) 
    {
	assert(root != NULL);

	int thisCount = count(root->left) + 1;
	if (thisCount == k) {
	    return root->val;
	}
	else if (thisCount < k) {
	    return kthSmallest(root->right, k - thisCount);
	}
	else {
	    return kthSmallest(root->left, k);
	}
    }

    int count(TreeNode* root)
    {
	if (root == NULL) {
	    return 0;
	}

	return 1 + count(root->left) 
	         + count(root->right);
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
