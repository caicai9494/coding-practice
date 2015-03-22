#include <iostream>
#include <limits>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    static ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	ListNode *merged = new ListNode(0);
	ListNode *head = merged;
	while(l1 != NULL || l2 != NULL)
	{
	    if(l1 == NULL)
	    {
		merged->next = l2;
		merged = merged->next;
		l2 = l2->next;
		//break;
	    }
	    else if(l2 == NULL)
	    {
		merged->next = l1;
		merged = merged->next;
		l1 = l1->next;
		
	    }

	    else if(l1->val >= l2->val)
	    {
		merged->next = l2;
		merged = merged->next;
		l2 = l2->next;
		//if(!l2)
		  //  break;
	    }
	    else if(l1->val < l2->val)
	    {
		merged->next = l1;
		merged = merged->next;
		l1 = l1->next;
	    }
	}

	
	return head->next;
    }
};

