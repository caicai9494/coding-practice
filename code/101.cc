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
class Solution
{
    public:
	bool isSymmetric(TreeNode *root) {
	    if(!root) return true;
	    return inorder(root) == inorder2(root) && preorder(root) == preorder2(root);
	}

	string inorder(TreeNode *root) {
	    if(!root) return "";
	    else return inorder(root->left) + to_string(root->val) + inorder(root->right);
	}
	string inorder2(TreeNode *root) {
	    if(!root) return "";
	    else return inorder2(root->right) + to_string(root->val) + inorder2(root->left);
	}

	string preorder(TreeNode *root) {
	    if(!root) return "";
	    else return to_string(root->val) + preorder(root->left) + preorder(root->right);
	}

	string preorder2(TreeNode *root) {
	    if(!root) return "";
	    else return to_string(root->val) + preorder2(root->right) + preorder2(root->left);
	}



};
