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
	ListNode *partition(ListNode *head, int x) {

	    if(!head) return nullptr;

	    ListNode n1(0), n2(0);
	    ListNode *cur = head, *p1 = &n1, *p2 = &n2;

	    while(cur) {
		if(cur->val < x) {
		    p1 = p1->next = cur;
		} else {
		    p2 = p2->next = cur;
		}
		cur = cur->next;
	    }

	    p2->next = nullptr;
	    p1->next = n2.next;

	    return n1.next;
	}

};
