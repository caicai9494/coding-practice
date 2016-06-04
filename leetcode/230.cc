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
    int d_count;
    int d_k;
    int d_val;
    int kthSmallest(TreeNode* root, int k) 
    {
	assert(root != NULL);

	d_count = 0;
	d_k = k;

	traverse(root);

	return ;
    }

    void traverse(TreeNode* root)
    {
	if (!root || d_count == d_k) {
	    return;
	}

	traverse(root->left);

	++count;
	if (d_count == d_k) {
	    d_val = root->val;
	}
	
	traverse(root->right);
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
