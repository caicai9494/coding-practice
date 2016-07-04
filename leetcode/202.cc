#include <algorithm>
#include <cassert>
#include <cmath>
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
  public:
    bool isHappy(int n) 
    {
	unordered_set<int> exists;
	while (1) {
	    if (n == 1) return true;
	    exists.insert(n);

	    int next = 0;
	    while (n > 0) {
		next += ::pow((n % 10), 2);
		n /= 10;
	    }
	    n = next;
	    if (exists.find(n) != exists.end()) { return false; }
	}

	return false;
    }
};

int main()
{
    Solution s;
    DBG(s.isHappy(10598542));
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
