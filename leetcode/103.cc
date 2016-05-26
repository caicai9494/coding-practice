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

/**
 *
 *  * Definition for a binary tree node.
 *
 *   * struct TreeNode {
 *
 *   *     int val;
 *
 *   *     TreeNode *left;
 *
 *   *     TreeNode *right;
 *
 *   *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *
 *   * };
 *
 *   */

using namespace std;

class Solution {
    bool d_flag; // from left to right
    vector<vector<int> > d_answer;
  public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) 
    {
	if (root != nullptr) {

	    d_flag = true;
	    vector<TreeNode*> nodes;
	    nodes.push_back(root);

	    zigzag(nodes);
	}
	return d_answer;
    }

    void zigzag(const vector<TreeNode*>& nodes)
    {
	if (nodes.empty()) {
	    return; 
	}

	vector<TreeNode*> backup;
	vector<int> numbers;
	for (auto it = nodes.begin(); it != nodes.end(); ++it) {

	    if ((*it)->left) {
		backup.push_back((*it)->left);
	    }

	    if ((*it)->right) {
		backup.push_back((*it)->right);
	    }

	    numbers.push_back((*it)->val);
	}

	if (d_flag) {
	    d_answer.push_back(numbers);
	}
	else {
	    reverse(numbers.begin(), numbers.end());
	    d_answer.push_back(numbers);
	}

	d_flag = !d_flag;
	zigzag(backup);
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
