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
	void connect(TreeLinkNode *root)
	{
	    if(root == NULL) return;

	    queue<TreeLinkNode*> treequeue;
	    treequeue.push(root);
	    treequeue.push(NULL);

	    //vector<TreeLinkNode*> container;
	    while(!treequeue.empty())
	    {
		TreeLinkNode *head = treequeue.front();
		treequeue.pop();

		if(head == NULL)
		{

		    if(!treequeue.empty())
			treequeue.push(NULL);
		}
		else
		{
		    head->next = treequeue.front();
		    //container.push_back(head);
		    if(head->left)
		        treequeue.push(head->left);
		    if(head->right)
		        treequeue.push(head->right);
		}
		
	    }
	}

};
