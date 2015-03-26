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
#include <queue>

using namespace std;
class Solution
{
    public:
	vector<vector<int> > result;

	vector<vector<int> > levelOrder(TreeNode *root)
	{
	    queue<TreeNode*> container;
	    if(root == NULL) return result;
	    else
	    {
		container.push(root);
		container.push(NULL);

		vector<int> temp;

		while(!container.empty())
		{
		    TreeNode* topNode = container.front();
		    container.pop();
		    if(topNode == NULL)
		    {
			result.push_back(temp);
			temp.resize(0);
			if(container.size() > 0)
			    container.push(NULL);
		    }
		    else
		    {
		        temp.push_back(topNode->val);
			if(topNode->left != NULL)
			container.push(topNode->left);
			if(topNode->right != NULL)
			container.push(topNode->right);

		    }

		}
		
		if(!temp.empty())
		    result.push_back(temp);
	    }

	    return result;
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
