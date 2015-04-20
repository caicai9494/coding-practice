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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	ListNode *merged = new ListNode(0);
	ListNode *head = merged, *p = head;
	while(l1 != NULL || l2 != NULL)
	{
	    if(l1 != NULL) {
		if(l2 != NULL && l1->val > l2->val) {
		    p->next = l2;
		    l2 = l2->next;
		} else {
		    p->next = l1;
		    l1 = l1->next;
		}
	    } else {
		p->next = l2;
		l2 = l2->next;
	    }
    	    p = p->next;
	}

	p = head->next;
	delete head;
	return p;
    }


    ListNode *sortList(ListNode *head) {

	if(!head) return head;
	if(!head->next) return head;

	ListNode *slow, *fast;
	slow = head;
	fast = slow->next;

	while(fast && fast->next) {
	    fast = fast->next->next;
	    slow = slow->next;
	}

	ListNode *head2;
	head2 = slow->next;
	slow->next = NULL;

	head = sortList(head);
	head2 = sortList(head2);

	return mergeTwoLists(head, head2);
    }
};
