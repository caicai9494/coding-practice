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
    int getSum(int a, int b) 
    {
	int c = 0;
	int sum = 0;
	int mask = 1;

	while (mask != 0) {
	    int a1 = (a & mask) != 0 ? 1 : 0;
	    int b1 = (b & mask) != 0 ? 1 : 0;

	    if (a1 == 1 && b1 == 1) {
		if (c == 1) {
		    sum |= mask;
		}
		c = 1;
	    }
	    else if (a1 ^ b1 == 1) {
		if (c == 0) {
		    sum |= mask;
		}

	    }
	    else { // both zeros
		if (c == 1) {
		    sum |= mask;
		}
		c = 0;
	    }
	    mask <<= 1;
	}

	return sum;
    }
};

int main()
{
    Solution s;
    DBG(s.getSum(1, 2));
    //int A[] = {5, 7, 7, 8, 8, 10};
    //vector<int> num = {4, 5, 6, 7 , 8, 0, 1, 2};
    //cout << s. << endl;
    return 0;
}
