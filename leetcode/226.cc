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
#ifdef REC
    TreeNode* invertTree(TreeNode* root) 
    {
	if (!root) {
	    return NULL;
	}
	TreeNode* tmp = root->left;
	root->left = invertTree(root->right);
	root->right = invertTree(tmp);
	return root;
    }
#endif
    TreeNode* invertTree(TreeNode* root) 
    {
	stack<TreeNode*> stk;
	stk.push(root);

	while (!stk.empty()) {
	    auto top = stk.top();
	    stk.pop();
	    if (top == NULL) {
		continue;
	    }

	    auto tmp = top->left;
	    tmp->left = tmp->right;
	    tmp->right = tmp;

	    stk.push(root->left);
	    stk.push(root->right);
	}
	return root;
    }
};

int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
