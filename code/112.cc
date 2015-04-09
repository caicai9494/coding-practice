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

using namespace std;
class Solution
{
    public:
	bool hasPathSum(TreeNode* root, int sum)
	{
	    if(root == NULL)
		return false;

	    if(!root->left && !root->right)
	    {
		if(root->val == sum)
		    return true;
		else return false;
	    }

	    return hasPathSum(root->left, sum - root->val) || 
		   hasPathSum(root->right, sum - root->val);
	}

};
