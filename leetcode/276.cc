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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
  public:
    int numWays(int n, int k) 
    {
	if (n == 0) return 0;
	if (n == 1) return k;
	int same = 0;
	int diff = 0;

	for (int i = 3; i <= n; ++i) {
	    int tmp = same;
	    same = diff;
	    diff = (tmp + diff) *  (k - 1);
	}
	return same + diff;
    }
};

int main()
{
    Solution s;
    DBG(s.numWays(1, 10));
    DBG(s.numWays(2, 10));
    DBG(s.numWays(3, 10));
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
