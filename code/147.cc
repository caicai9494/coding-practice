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
	ListNode *insertionSortList(ListNode *head) {
	    if(!head) return head;
	    if(!head->next) return head;

	    ListNode result(numeric_limits<int>::min());

	    while(head) {
		ListNode* cur = &result;
		while(cur->next && head->val > cur->next->val) {
		    cur = cur->next;
		}

		ListNode* temp = head->next;
		head->next = cur->next;
		cur->next = head;
		head = temp;

	    }

	    return result.next;
	}

};
int main()
{
    Solution s;
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    cout << s. << endl;
    return 0;
}
