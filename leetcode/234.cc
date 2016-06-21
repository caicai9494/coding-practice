#include <algorithm>
#include <cassert>
#include <limits>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "lz_error.h"

using namespace std;

class Solution {
  public:
    ListNode* reverse(ListNode* node)
    {
	if (!node || !node->next) {
	    return node;
	}

	ListNode* newhd = reverse(node->next);
	node->next->next = node;
	node->next = nullptr;

	return newhd;
    }

    bool isPalindrome(ListNode* head) 
    {
	if (!head || !head->next) {
	    return true;
	}

	ListNode *slow = head;
	ListNode *fast = head;

	while (fast && fast->next) {
	    slow = slow->next;
	    fast = fast->next->next;
	}
	slow = reverse(slow);
	while (head && slow) {
	    if (head->val != slow->val) {
		return false;
	    }
	    head = head->next;
	    slow = slow->next;
	}
	return false;
    }
};

int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
