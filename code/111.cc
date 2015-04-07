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
	int minDepth(TreeNode *root)
	{
	    if(root == NULL) return 0;
	    if(root->left && root->right)
	        return 1 + min(minDepth(root->left), minDepth(root->right));
	    if(root->left)
		return 1 + minDepth(root->left);
	    else
		return 1 + minDepth(root->right);
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
