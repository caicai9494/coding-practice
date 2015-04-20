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
class BSTIterator {
public:
    stack<TreeNode*> nodes;
    BSTIterator(TreeNode *root) {
	fill_stack(root);
    }

    inline void fill_stack(TreeNode* root) {
	while(root) {
	    nodes.push(root);
	    root = root->left;
	}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
	return !nodes.empty();
    }

    /** @return the next smallest number */
    int next() {
	auto node = nodes.top();
	nodes.pop();

	fill_stack(node->right);

	return node->val;
    }

};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
