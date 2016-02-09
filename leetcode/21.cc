#include <iostream>
#include <limits>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    static ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	ListNode *p, *head; //dummy
	head = p = new ListNode(0);
	while(l1 != NULL || l2 != NULL)
	{
	    if(l1 != NULL && (l2 != NULL || l1->val < l2->val))
	    {
		p->next = l1;
		l1 = l1->next;
	    }
	    else
	    {
		p->next = l2;
		l2 = l2->next;
	    }

	    p = p->next;
	}

	p = head->next;
	delete head;
	
	return p;
    }
};

