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

class Solution {

    public:
	int maxDepth(TreeNode* root)
	{
	    if(!root) return 0;
	    return 1 + max(maxDepth(root->left), maxDepth(root->right));;
	}

};
