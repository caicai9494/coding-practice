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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	    return create(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
	}
	TreeNode* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
	    if(ps > pe) return nullptr;
	    TreeNode* node = new TreeNode(preorder[ps]);

	    int pos;
	    for(int i = is; i <= ie; ++i) {
		if(inorder[i] == node->val) {
		    pos = i;
		    break;
		}
	    }

	    node->left = create(preorder, inorder, ps+1, ps+pos-is, is, pos-1);
	    node->right = create(preorder, inorder, ps+pos-is+1, pe, pos+1, ie);

	    return node;
	}

};
