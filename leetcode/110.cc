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
	bool isBalanced(TreeNode *root)
	{
	    if(height(root) == -1)
		return false;
	    return true;
	}

	int height(TreeNode *root)
	{
	    if(root == NULL)
		return 0;

	    int l = height(root->left);
	    int r = height(root->right);

	    if(l - r > 1 || l - r < -1 || l == -1 || r == -1)
		return -1;
	    
	    return 1 + max(l, r);
	}

};
