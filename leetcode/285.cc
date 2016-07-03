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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
	assert(p != NULL);
	if (p->right) {
	    return goLeft(p->right);
	}

	vector<TreeNode*> path;
	path.push_back(root);
	TreeNode* cursor = root;
	while (cursor->val != p->val) {
	    if (cursor->val > p->val) {
		path.push_back(cursor->left);
		cursor = cursor->left;
	    }
	    else {
		path.push_back(cursor->right);
		cursor = cursor->right;
	    }
	}

	for (auto rit = path.rbegin(); rit != path.rend(); ++rit) {
	    if ((*rit)->val > p->val) {
		return *rit;
	    }
	}
	return NULL;
    }

    TreeNode goLeft(TreeNode* root) 
    {
	if (!root) return NULL;
	if (root->left) {
	    return goLeft(root->left);
	}
	else {
	    return root;
	}
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
