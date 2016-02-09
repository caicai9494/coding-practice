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
	TreeNode *prev;
	bool isValidBST(TreeNode *root)
	{
	    if(root == NULL) return true;

	    if(!isValidBST(root->left))
		return false;

	    if(prev && prev->val >= root->val)
		return false;
	    prev = root;

	    if(!isValidBST(root->right))
		return false;
	}

};
