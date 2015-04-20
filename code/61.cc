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
	    if(!head || !head->next || k == 0) return head;

	    int count = 1; //count length
	    ListNode *ptr;
	    ptr = head;
	    while(ptr->next) 
	    {
		count++;
		ptr = ptr->next;
	    }

	    k %= count;
	    if(k == 0) return head; //return null when k is too big
	    ptr->next = head;

	    ptr = head; //traverse to object node
	    for(int i = 0; i < n - k - 1; i++)
		ptr = ptr->next;

	    ListNode* newHead = ptr->next;
	    ptr->next = NULL;

	    return newHead;
	    
	}

};
