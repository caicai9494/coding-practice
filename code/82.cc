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
#include <unordered_map>

using namespace std;
class Solution
{
    public:
	ListNode *deleteDuplicates(ListNode *head)
	{
	    if(!head || !head->next) return head;

	    int val = head->val;
	    ListNode *node = head->next;

	    if(node->val != val) {
		head->next = deleteDuplicates(head->next);
		return head;
	    }
	    else {
		while(node && node->val == val) {
		    ListNode *temp = node;
		    node = node->next;
		    delete temp;
		}
		return deleteDuplicates(node);
	    }
	}

};
