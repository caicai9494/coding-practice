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

	TreeNode* sortedListToBST(ListNode* head) {
	    if(!head) return NULL;
	    if(!head->next) return {head->val};

	    ListNode *fast, *slow, *pre;
	    slow = head;
	    fast = head->next;

	    while(fast && fast->next) {
		pre = slow;
		slow = slow->next;
		fast = fast->next;
	    }

	    pre->next = NULL;

	    TreeNode *tnode = new TreeNode(slow->val);
	    tnode->left = sortedListToBST(head);
	    tnode->right = sortedListToBST(slow->next);
	    return root;
	}

	TreeNode* root;

};
