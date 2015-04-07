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
	ListNode *rotateRight(ListNode* head, int k)
	{
	    if(!head) return NULL;

	    int count = 0; //count length
	    ListNode *ptr, *target;
	    ptr = head;
	    while(ptr != NULL) 
	    {
		count++;
		ptr = ptr->next;
	    }

	    k %= count;
	    if(k == 0) return head; //return null when k is too big

	    ptr = head; //traverse to object node
	    while(count - k > 1)
	    {
		ptr = ptr->next;
		count--;
	    }

	    target = ptr->next;
	    //ptr->next = NULL; //set previous node

	    while(target->next != NULL)
		target = target->next;
	    target->next = head;
	    head = ptr->next;
	    ptr->next = NULL;

	    return head;
	    
	}

};
