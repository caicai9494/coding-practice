#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
#include <stack>
#include <bitset>

using namespace std;
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

    ListNode *mergeK(vector<ListNode *> &lists, int left, int right) {
	if(left == right) return lists[left];

	int mid = (left + right) / 2;
	auto l1 = mergeK(lists, left, mid);
	auto l2 = mergeK(lists, mid + 1, right);
	return mergeTwoLists(l1, l2);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
	if(lists.empty()) return NULL;
	return mergeK(lists, 0, lists.size() - 1);
    }
};
int main()
{
    Solution s;
    return 0;
}
