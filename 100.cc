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
    bool isSameTree(TreeNode *p, TreeNode *q) {

	if(p == NULL && q== NULL)
	    return true;

	else if(p != NULL && q != NULL)
	{
	    if(p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) 
		return true;
	}
	else 
	    return false;

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
