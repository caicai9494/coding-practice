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
    vector<string> ret;
    vector<string> binaryTreePaths(TreeNode* root) {
	if (!root) { return ret; }
	string path;
	binaryTreePaths(root, &path);
	return ret;
    }

    void binaryTreePaths(TreeNode* root, string* path) {
	if (!root) {
	    return;
	}

	string& ref = *path;
	if (!root->left && !root->right) {
	    ref = ref + to_string(root->val);
	    ret.push_back(*path);
	    return;
	}
	ref = ref + to_string(root->val) + "->";
	string backup = *path;
	binaryTreePaths(root->left, path);
	binaryTreePaths(root->right, &backup);
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
