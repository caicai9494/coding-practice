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
    bool hasCycle(ListNode *head) {
	ListNode *fast, *slow;
	fast = slow = head;
	while(fast && fast->next && fast->next->next)
	{
	    fast = fast->next->next;
	    if(fast == slow)
		return true;
	    slow = slow->next;
	}
	return false;
    }
};
int main()
{
    Solution s;
    return 0;
}
