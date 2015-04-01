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
	bool isValidBST(TreeNode *root)
	{
	    if(root == NULL) return true;
	    if(greater(root, root->left) && less(root, root->right))
		return (isValidBST(root->left) && isValidBST(root->right));
	}
	bool greater(TreeNode *root, TreeNode *obj)
	{
	    if(root == NULL || obj == NULL) return true;

	    if(root->val > obj->val && greater(root, obj->left) && greater(root, obj->right))
		return true;
	    else return false;
	}
	bool less(TreeNode *root, TreeNode *obj)
	{
	    if(root == NULL || obj == NULL) return true;

	    if(root->val < obj->val && less(root, obj->left) && less(root, obj->right))
		return true;
	    else return false;
	}

};
