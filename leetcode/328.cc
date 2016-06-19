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
  ListNode *oddEvenList(ListNode *head) 
  {
    if (!head || !head->next) {
        return head;
    }

    ListNode *oddHead = head;
    ListNode *evenHead = head->next;
    ListNode *odd = oddHead;
    ListNode *even = evenHead;
    while (odd && odd->next && odd->next->next) {

      odd->next = odd->next->next;
      even->next = odd->next->next;
      odd = odd->next;
      even = even->next;
    }

    odd->next = evenHead;
    return oddHead;
  }
};

int main() 
{
    Solution s;
    // int A[] = {5, 7, 7, 8, 8, 10};
    // vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    // cout << s. << endl;
    return 0;
}
