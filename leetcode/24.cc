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
	ListNode* swapPairs(ListNode* head) 
	{
	    if (head && head->next) {

		ListNode* second = head->next;
		ListNode* third = second->next;
		second->next = head;
		head->next = swapPairs(third);
		head = second;
	    }

	    return head;

	}

};
