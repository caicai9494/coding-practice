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
	vector<vector<int> >ret;

	void searchPath(TreeNode* root, int sum, vector<int>& place)
	{
	    if (!root) 	return;
	    else if(sum == root->val && !root->left && !root->right) {
		place.push_back(root->val);
		ret.push_back(place);
		place.pop_back();
		return;
	    } else {
		place.push_back(root->val);

		searchPath(root->left, sum - root->val, place);

		searchPath(root->right, sum - root->val, place);
		place.pop_back();
	    }
	}

	vector<vector<int> > pathSum(TreeNode* root, int sum)
	{
	    if(!sum && !root) return {}; 
	    vector<int> temp;
	    searchPath(root, sum, temp);
	    return ret;
	}

};
