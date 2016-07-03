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
	vector<TreeNode*> pathP;
	vector<TreeNode*> retP;
	getPath(&retP, &pathP, root, p);
	vector<TreeNode*> pathQ;
	vector<TreeNode*> retQ;
	getPath(&retQ, &pathQ, root, q);

	TreeNode* ret = NULL;
	for (auto itp = retP.begin(), itq = retQ.begin();
	     itp != retP.end() && itq != retQ.end(); 
	     ++itp, ++itq) {
	    if ((*itp)->val == (*itq)->val) {
		ret = *itp;
	    }
	    else break;
	}
	return ret;
    }

    void getPath(vector<TreeNode*>* ret, vector<TreeNode*>* path, TreeNode* root, TreeNode* target)
    {
	if (!root) {
	    return;
	}
	path->push_back(root);
	if (root == target) {
	    ret->assign(path->begin(), path->end());
	    return;
	}
	if (root->left) {
	    getPath(ret, path, root->left, target);
	}
	if (root->right) {
	    getPath(ret, path, root->right, target);
	}
	path->pop_back();
    }

};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1, 
	                    new TreeNode(2, 
				new TreeNode(3), new TreeNode(4)), 
			    new TreeNode(5, 
				new TreeNode(6), new TreeNode(7)));
    //s.getPath(&s.d_path, root, new TreeNode(6));
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
