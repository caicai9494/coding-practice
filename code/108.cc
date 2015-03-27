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

	TreeNode* rec(vector<int>& num, int left, int right)
	{
	    if(left > right) return NULL;
	    int mid = (left + right) / 2;
	    
	    TreeNode* node = new TreeNode(num[mid]);
	    node->left = rec(num, left, mid - 1);
	    node->right = rec(num, mid + 1, right);

	    return node;
	}

	TreeNode *sortedArrayToBST(vector<int> num)
	{
	    return rec(num, 0, num.size() - 1);
	}

};
