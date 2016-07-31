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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* nxt) : val(x), next(nxt) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
  public:
    bool isStrobogrammatic(string num) 
    {
	vector<char> table;
	for (int i = 0; i < 10; ++i) {
	    table.push_back('0' + i);
	}

	table[9] = '6';
	table[6] = '9';
	table[8] = '8';

	int l = 0;
	int r = num.size() - 1;
	while (l <= r) {
	    if (num[l] == num[r]) {
		if(num[l] == '8' || num[l] == '1' || num[l] == '0') {
		    l++; r--;
		    continue;
		}
		else { return false; }
	    }
	    if (num[l++] != table[num[r--] - '0']) {
		return false;
	    }
	}
	return true;
    }
};

int main()
{
    Solution s;
    DBG(s.isStrobogrammatic("818"));
    DBG(s.isStrobogrammatic("69"));
    DBG(s.isStrobogrammatic("169"));
    DBG(s.isStrobogrammatic("619"));
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
