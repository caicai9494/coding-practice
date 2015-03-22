#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
#include <bitset>

using namespace std;
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> result;
    vector<int> inorderTraversal(TreeNode *root) {
	/*
	if(!root)
	    return result;

	inorderTraversal(root->left);
	if(root)
	    result.push_back(root->val);
	inorderTraversal(root->right);
	*/


	stack<TreeNode*> treestack;

	while(!treestack.empty() || root != NULL)
	{
	    //TreeNode *ptr = treestack.top();
	    if(root)
	    {
		treestack.push(root);
		root = root->left;
	    }
	    else
	    {
		TreeNode *ptr = treestack.top();
		treestack.pop();
		result.push_back(ptr->val);
		root = root->right;
	    }

	}


	return result;
    }
};
int main()
{
    Solution s;
    return 0;
}
