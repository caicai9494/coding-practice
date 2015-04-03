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
    ListNode* detectCycle(ListNode *head) {
	set<ListNode*> container;
	ListNode *ptr = head;
	while(ptr)
	{
	    auto res = container.insert(ptr);
	    if(!res->second)
		return ptr;
	    ptr = ptr->next;
	}
	return NULL;
    }
};
