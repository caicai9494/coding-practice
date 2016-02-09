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
	ListNode *getIntersectionNode(ListNode* headA, ListNode* headB) {
	    if(!headA || !headB) return NULL;

	    int lenA = 0, lenB = 0;
	    ListNode *curA = headA, *curB = headB;

	    while(curA) {
		lenA++;
		curA = curA->next;
	    }
	    while(curB) {
		lenB++;
		curB = curB->next;
	    }

	    curA = headA, curB = headB;
	    while(lenB != lenA) {
		if(lenA > lenB) {
		    --lenA;
		    curA = curA->next;
		}
		else {
		    --lenB;
		    curB = curB->next;
		}
	    }

	    while(curA) {
		if(curA == curB) return curA;

		curA = curA->next;
		curB = curB->next;
	    }
	    return NULL;
	}
};
