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
    vector<int> postorderTraversal(TreeNode *root) {
	/*
	if(!root)
	    return result;

	postorderTraversal(root->left);
	postorderTraversal(root->right);
	if(root)
	    result.push_back(root->val);

	return result;
	*/

	stack<TreeNode*> treestack;
	treestack.push(root);

	while(!treestack.empty())
	{
	    TreeNode *ptr = treestack.top();
	    //if(ptr)
//		result.push_back(ptr->val);
	    //treestack.pop();

	    if(ptr->left)
	    treestack.push(ptr->left);
	    else
	    {
		TreeNode *ptr = treestack.top();
		result.push_back(ptr->val);
		treestack.pop();
	    }
	    if(ptr->right)
	    treestack.push(ptr->right);
	    else
	    {
		TreeNode *ptr = treestack.top();
		result.push_back(ptr->val);
		treestack.pop();
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
