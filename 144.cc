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
    vector<int> preorderTraversal(TreeNode *root) {
	if(!root)
	    return result;

	stack<TreeNode*> treestack;
	treestack.push(root);

	while(!treestack.empty())
	{
	    TreeNode ptr = treestack.top();
	    if(ptr)
		result.push_back(ptr->val);
	    treestack.pop();

	    if(ptr->right)
	    treestack.push(ptr->right);
	    if(ptr->left)
	    treestack.push(ptr->left);
	}


	return result;
    }
};
int main()
{
    Solution s;
    return 0;
}
