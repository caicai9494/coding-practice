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
	ListNode *deleteDuplicates(ListNode *head)
	{
	    if(!head) return NULL;
	    ListNode *i, *j;
	    i = head;
	    j = head->next;

	    while(j)
	    {
		if(i->val != j->val) i->next->val = j->val, i = i->next;
		j = j->next;
	    }

	    ListNode *temp;
	    temp = i->next;
	    i->next = NULL;
	    while(temp)
	    {
		i = temp;
		temp = temp->next;
		delete i;
	    }

	    return head;
	}

};
