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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
	if (!root) {
	    return NULL;
	}
	if (root->val > p->val && root->val > q->val) {
	    return lowestCommonAncestor(root->left, p, q);
	}
	else if (root->val < p->val && root->val < q->val) {
	    return lowestCommonAncestor(root->right, p, q);
	}
	return root;
    }

#ifdef DEBUG
    void getPath(vector<TreeNode*>* path, TreeNode* root, TreeNode* target)
    {
	if (root->val == target->val) {
	    /*
	    for (size_t i = 0; i != path->size(); ++i) {
		cout << (*path)[i]->val << ' '; 
	    }
	    cout << endl;
	    */
	    return;
	}
	path->push_back(root);
	if (root->left) {
	    getPath(path, root->left, target);
	}
	if (root->right) {
	    getPath(path, root->right, target);
	}
	path->pop_back();
    }
#endif

};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1, 
	                    new TreeNode(2, 
				new TreeNode(3), new TreeNode(4)), 
			    new TreeNode(5, 
				new TreeNode(6), new TreeNode(7)));
    s.getPath(&s.d_path, root, new TreeNode(6));
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
