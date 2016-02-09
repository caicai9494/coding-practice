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
	void flatten(TreeNode *root)
	{
	    if(!root) return;
	    if(!root->left && !root->right) return;

	    flatten(root->left);

	    if(root->left)
	    {
		TreeNode *l, *r;
		l = root->left;
		r = root->right;
		root->right = l;
		root->left = NULL;
		while(l->right)
		    l = l->right;
		l->right = r;
	    }

	    flatten(root->right);
	}

};
int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    cout << s. << endl;
    return 0;
}
