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
	ListNode* swapPairs(ListNode *head)
	{
	    if(!head||!(head->next)) return head;
	    ListNode **cursor = &head;

	    while(*cursor && (*cursor)->next)
	    {
		ListNode *temp = (*cursor)->next;
		(*cursor)->next = temp->next;
		temp->next = *cursor;
		*cursor = temp;
		*cursor = (*cursor)->next->next;
	    }

	    return head;
	}

};
