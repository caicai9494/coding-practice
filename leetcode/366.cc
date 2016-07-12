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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* nxt) : val(x), next(nxt) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
  public:
    vector<vector<int>> ret;
    unordered_map<int, vector<int>> table;
    vector<vector<int>> findLeaves(TreeNode* root) 
    {
	if (!root) { return ret; }

	int maxd = depth(root);
	for (int i = 1; i <= maxd; ++i) {
	    ret.push_back(std::move(table[i]));
	}
	return ret;
    }

    int depth(TreeNode* node)
    {
	if (!node) {
	    return 0;
	}
	int d = 1 + ::max(depth(node->left), depth(node->right));
	table[d].push_back(node->val);
	return d;
    }
};

int main()
{
    Solution s;
    auto* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    auto ret = s.findLeaves(root);
    for (auto& vec : ret) {
	DBG(vec);
    }
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
